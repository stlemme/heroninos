
#pragma once
#ifndef __CMD_HIGHLIGHTER_H__
#define __CMD_HIGHLIGHTER_H__

#include <QSyntaxHighlighter>

#include <QMap>
#include <QVector>

class QTextCharFormat;
class QTextDocument;
class QStringListModel;
class QColor;
class QStringList;


class CmdHighlighter 
:   public QSyntaxHighlighter
{
public:

    CmdHighlighter();
    virtual ~CmdHighlighter();

protected:

    void initialize();

    void createAndAppendRules(
        const QString &pattern
    ,   QTextCharFormat *format);

    // QSyntaxHighlighter interface

    virtual void highlightBlock(const QString &text);

protected:

    typedef QVector<QRegExp> t_regExps;
    typedef QMap<QTextCharFormat*, t_regExps> t_patternsByFormat;

    QVector<QTextCharFormat*> m_formats;
    t_patternsByFormat m_patternsByFormat;
};

#endif // __CMD_HIGHLIGHTER_H__