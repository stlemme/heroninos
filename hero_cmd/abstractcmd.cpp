
#include "abstractcmd.h"


#include <assert.h>


AbstractCmd::AbstractCmd()
:   m_lastFragment(NULL)
,   m_passed(false)
{
}


AbstractCmd::~AbstractCmd()
{
}


void AbstractCmd::operator << (AbstractCmdArgument *argument)
{
    assert(argument);
    m_arguments << argument;
}


void AbstractCmd::operator << (VariantCmdFlag *flag)
{
    assert(flag);
    m_flags << flag;
}


inline const QRegExp AbstractCmd::commandAsRegExp() const
{
    const QRegExp re("^(\\b" + command() + "\\b)", Qt::CaseInsensitive);
    assert(re.isValid());

    return re;
}


const bool AbstractCmd::parse(const QString &cmd)
{
    m_lastFragment = NULL;
    m_passed = false;

    if(cmd.isEmpty())
        return false;

    QString cmdLine(cmd);

    // check command first.

    QRegExp re(commandAsRegExp());
    const int i = re.indexIn(cmdLine);

    if(i == -1)
        return false;

    // remove from cmd and iterate over fragments

    cmdLine.remove(re);

    foreach(AbstractCmdArgument *arg, m_arguments)
    {
        assert(arg);

        m_lastFragment = arg;
        if(!arg->parse(cmdLine))
            return false;
    }
    m_lastFragment = NULL;
    m_passed = true;

    return m_passed;
}


const QString AbstractCmd::syntax() const
{
    QString s = command();

    foreach(AbstractCmdArgument *arg, m_arguments)
        s += " " + arg->syntax();

    return s;
}


const QString AbstractCmd::error() const
{
    if(passed())
        return "succeeded";

    if(!m_lastFragment)
        return QString("cmd does not start with %1").arg(command());

    return m_lastFragment->error();
}