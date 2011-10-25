
#include "arg_passphrase.h"


#include <assert.h>


ArgPassphrase::ArgPassphrase(
    const QString &identifier
,   const QString &comment)
:   AbstractCmdArgument(identifier, comment)
{
}


ArgPassphrase::~ArgPassphrase()
{
}


const QString ArgPassphrase::syntax() const
{
    return "\"" + identifier() + "\"";
}


const QString ArgPassphrase::regExp() const
{
    return "\\\"([^\\n\\r\\v\\t]+)\\\"";
}


const bool ArgPassphrase::capture(const QStringList &texts)
{
    if(texts.count() != 2)
        return false;

    m_passphrase = texts.last();
    return isValid();
}


const bool ArgPassphrase::isValid() const
{
    return m_passphrase.length() > 3;
}


void ArgPassphrase::invalidate()
{
    m_invalidatedPassphrase = m_passphrase;
    m_passphrase = "";
}


const QString ArgPassphrase::error() const
{
    if(isValid())
        return QString();

    if(empty())
        return identifier() + " expected";

    if(!matched())
        return "passphrase should be delimited by quotation marks";

    if(m_invalidatedPassphrase.length() < 4)
        return "passphrase should contain at least 4 charachters";

    return "unknown";
}