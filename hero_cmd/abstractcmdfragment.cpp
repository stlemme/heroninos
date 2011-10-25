
#include "abstractcmdfragment.h"


AbstractCmdFragment::AbstractCmdFragment()
:   m_matched(false)
,   m_empty(false)
{
}
 

AbstractCmdFragment::~AbstractCmdFragment()
{
}


const bool AbstractCmdFragment::parse(QString &cmd)
{
    m_empty = cmd.trimmed().isEmpty();
    if(m_empty)
        return false;

    QRegExp re("^\\s+" + regExp());
    const int i = re.indexIn(cmd);
    
    m_matched = i > -1 && re.captureCount() > 0;

    if(!m_matched)
        return false;

    cmd.remove(i, re.matchedLength());

    return capture(re.capturedTexts());
}