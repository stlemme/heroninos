
#pragma once
#ifndef __ARG_PASSPHRASE_H__
#define __ARG_PASSPHRASE_H__

#include "abstractcmdargument.h"

#include <QFileInfo>


class ArgPassphrase : public AbstractCmdArgument
{
public:
    ArgPassphrase(
        const QString &identifier = "passphrase"
    ,   const QString &comment = QString());

    virtual ~ArgPassphrase();

    // TODO: security level checks?

    inline const QString &passphrase() const
    {
        return m_passphrase;
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

    QString m_passphrase;
    QString m_invalidatedPassphrase;
};

#endif // __ARG_PASSPHRASE_H__