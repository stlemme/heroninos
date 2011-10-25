
#pragma once
#ifndef __ABSTRACT_CMD_FRAGMENT_H__
#define __ABSTRACT_CMD_FRAGMENT_H__

#include <QVector>
#include <QString>
#include <QStringList>


class AbstractCmdFragment
{
public:

    AbstractCmdFragment();
    virtual ~AbstractCmdFragment();

    virtual const QString syntax() const = 0;
    virtual const QString error() const = 0;

    virtual const bool parse(QString &cmd);

protected:

    virtual const bool capture(const QStringList &texts) = 0;

    virtual const QString regExp() const = 0;
    virtual const QString comment() const = 0;

    inline const bool empty() const
    {
        return m_empty;
    }

    inline const bool matched() const
    {
        return m_matched;
    }

protected:

    bool m_matched;
    bool m_empty;
};

typedef QVector<AbstractCmdFragment*> t_CmdFragments;


#endif // __ABSTRACT_CMD_FRAGMENT_H__