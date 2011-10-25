
#pragma once
#ifndef __CMD_TEXTEDIT_H__
#define __CMD_TEXTEDIT_H__

#include <QPlainTextEdit>

class CmdHighlighter;

class QKeyEvent;
class QFocusEvent;
class QCompleter;


class CmdTextEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    CmdTextEdit(QWidget *parent = 0);
    virtual ~CmdTextEdit();

public slots:

    void registerCompleterStrings(const QStringList &strings);
    void unregisterCompleterStrings(const QStringList &strings);

protected:

    void initialize();

    void setupDocument();
    QTextDocument *createDocument() const;

    void setupCompleters();
    void setupHighlighter();

    virtual void focusInEvent(QFocusEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

protected:

    void process();

    QString textUnderCursor() const;

protected slots:

    void insertCompletion(const QString &completion);

    void on_processPushButton_clicked(bool);

private:
    CmdHighlighter *m_highlighter;
};

#endif // __CMD_TEXTEDIT_H__