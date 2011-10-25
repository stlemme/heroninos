
#pragma once
#ifndef __ABSTRACT_CMD_ARGUMENT_H__
#define __ABSTRACT_CMD_ARGUMENT_H__

#include "abstractcmdfragment.h"

#include <QString>


// TODO: argument could be optional
// TODO: argument could have its own flags

class AbstractCmdArgument : public AbstractCmdFragment
{
public:

    AbstractCmdArgument(
        const QString &identifier
    ,   const QString &comment = QString());

    virtual ~AbstractCmdArgument();

    virtual const bool parse(QString &cmd);

    virtual const bool isValid() const = 0;

    inline const QString identifier() const
    {
        return m_identifier;
    }

protected:

    virtual void invalidate() = 0;

    virtual const QString comment() const;

protected:
    const QString m_identifier;
    const QString m_comment;
};

typedef QVector<AbstractCmdArgument*> t_CmdArguments;

#endif // __ABSTRACT_CMD_ARGUMENT_H__