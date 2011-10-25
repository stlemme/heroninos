
#include "arg_filepath.h"


#include <QDir>

#include <assert.h>


ArgFilePath::ArgFilePath(
    const QString &identifier
,   const QString &comment
,   const bool existingFile
,   const QFile::Permissions permissions)
:   AbstractCmdArgument(identifier, comment)
,   m_existingFile(existingFile)
,   m_permissions(permissions)
{
}


ArgFilePath::ArgFilePath(
    const bool existingFile
,   const QFile::Permissions permissions)
:   AbstractCmdArgument("filepath")
,   m_existingFile(existingFile)
,   m_permissions(permissions)
{
}


ArgFilePath::~ArgFilePath()
{
}


const QString ArgFilePath::syntax() const
{
    return "\"" + identifier() + "\"";
}


const QString ArgFilePath::regExp() const
{
    return "\\\"([A-Z]:[\\/])?([^:\\\"\\n\\r\\v\\t\\*\\?<>\\|]+)\\\"";
}


const bool ArgFilePath::capture(const QStringList &texts)
{
    if(texts.count() != 2 && texts.count() != 3)
        return false;

    QString filePath;
    for(int i = 1; i < texts.count(); ++i)
        filePath += texts[i];

    m_filePath = QFileInfo(filePath);
    return isValid();
}


const bool ArgFilePath::isValid() const
{
    return !m_filePath.isDir()
    &&  (m_existingFile ? m_filePath.isFile() && m_filePath.exists() : true)
    &&  (m_existingFile ? m_filePath.permission(m_permissions) : true);
}


void ArgFilePath::invalidate()
{
    m_invalidatedFilePath = m_filePath;
    m_filePath = QFileInfo();
}


const QString ArgFilePath::error() const
{
    if(isValid())
        return QString();

    if(empty())
        return identifier() + " expected";

    if(!matched())
        return "filepath must be delimited by quotation marks, and can not contain following charachters: \\*?<>|";

    if(m_invalidatedFilePath.isDir())
        return "filepath should not point to a directory";

    if(m_existingFile && !m_invalidatedFilePath.isFile())
        return "filepath does not point to a file (required)";

    if(m_existingFile && !m_invalidatedFilePath.exists())
        return "filepath does not exist (required)";

    if(m_existingFile && !m_invalidatedFilePath.permission(m_permissions))
        return "filepath does not yield required permissions (required)";

    return "unknown";
}