
#pragma once
#ifndef __ABSTRACT_CMD_H__
#define __ABSTRACT_CMD_H__

#include "abstractcmdargument.h"
#include "variantcmdflag.h"


#include <QString>
#include <QRegExp>


class AbstractCmd
{
public:

    AbstractCmd();
    virtual ~AbstractCmd();

    virtual const QString command() const = 0;
    virtual const QString comment() const = 0;

    const QString syntax() const;

    const QString error() const;
    inline const bool passed() const 
    {
        return m_passed;
    }

    const bool parse(const QString &cmd);

protected:

    void operator << (AbstractCmdArgument *argument);
    void operator << (VariantCmdFlag *flag);

private:

    inline const QRegExp commandAsRegExp() const;

protected:

    t_CmdArguments m_arguments;
    t_CmdFlags m_flags;

    AbstractCmdFragment *m_lastFragment;
    bool m_passed;
};

#endif // __ABSTRACT_CMD_H__