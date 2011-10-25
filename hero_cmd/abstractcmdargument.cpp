
#include "abstractcmdargument.h"


AbstractCmdArgument::AbstractCmdArgument(
    const QString &identifier
,   const QString &comment)
:   AbstractCmdFragment()
,   m_identifier(identifier)
,   m_comment(comment)
{
}


AbstractCmdArgument::~AbstractCmdArgument()
{
}


const QString AbstractCmdArgument::comment() const
{
    return m_comment;
}


const bool AbstractCmdArgument::parse(QString &cmd)
{
    const bool result = AbstractCmdFragment::parse(cmd);

    if(!result)
        invalidate();

    return result;
}
