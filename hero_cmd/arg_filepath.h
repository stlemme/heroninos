
#pragma once
#ifndef __ARG_FILE_PATH_H__
#define __ARG_FILE_PATH_H__

#include "abstractcmdargument.h"

#include <QFileInfo>


class ArgFilePath : public AbstractCmdArgument
{
public:
    ArgFilePath(
        const QString &identifier = "filepath"
    ,   const QString &comment = QString()
    ,   const bool existingFile = false
    ,   const QFile::Permissions permissions = QFile::ReadUser);

    ArgFilePath(
        const bool existingFile
    ,   const QFile::Permissions permissions = QFile::ReadUser);


    virtual ~ArgFilePath();

        
    inline const QFileInfo &fileInfo() const
    {
        return m_filePath;
    }

    //  AbstractCmdFragment interface

    virtual const QString syntax() const;
    virtual const QString error() const;

    //  AbstractCmdArgument interface

    virtual const bool isValid() const;

protected:

    virtual const QString regExp() const;

    virtual const bool capture(const QStringList &texts);
    virtual void invalidate();

protected:

    QFileInfo m_filePath;
    QFileInfo m_invalidatedFilePath;
    
    bool m_existingFile;
    QFile::Permissions m_permissions;
};

#endif // __ARG_FILE_PATH_H__