
#include "cmdhighlighter.h"

//#include "hero_controller/cmdsyntax.hpp"

#include <QTextDocument>
#include <QStringListModel>
#include <QColor>


CmdHighlighter::CmdHighlighter()
:   QSyntaxHighlighter(static_cast<QWidget*>(NULL))
{
    initialize();
}


CmdHighlighter::~CmdHighlighter()
{
}


void CmdHighlighter::createAndAppendRules(
    const QString &pattern
,   QTextCharFormat *format)
{
    m_patternsByFormat[format] << QRegExp(pattern);
}


void CmdHighlighter::initialize()
{
    qDeleteAll(m_formats);

    m_formats.clear();
    m_patternsByFormat.clear();

   /* QTextCharFormat *fcmd(new QTextCharFormat());
    fcmd->setForeground(QColor("#0000ff"));

    QTextCharFormat *fneg(new QTextCharFormat());
    fneg->setForeground(QColor("#00ff00"));

    QTextCharFormat *fpos(new QTextCharFormat());
    fpos->setForeground(QColor("#00ff00"));

    QTextCharFormat *ff(new QTextCharFormat());
    ff->setForeground(QColor("#aaaaaa"));


    createAndAppendRules(cmd_syntax_session,        fcmd);
    createAndAppendRules(cmd_syntax_transaction_in, fpos);
    createAndAppendRules(cmd_syntax_transaction_in, fneg);
    createAndAppendRules(cmd_syntax_flags,          ff);*/
}


void CmdHighlighter::highlightBlock(const QString &text)
{
    t_patternsByFormat::const_iterator f(m_patternsByFormat.begin());
    const t_patternsByFormat::const_iterator fe(m_patternsByFormat.end());

    for(; f != fe; ++f)
    {
        const QTextCharFormat &format(*f.key());

        foreach(QRegExp pattern, f.value())
        {
            int index(text.indexOf(pattern));
            while(-1 != index)
            {
                const int length(pattern.matchedLength());
                setFormat(index, length, format);

                index = text.indexOf(pattern, index + length);
            }
        }
    }
}
