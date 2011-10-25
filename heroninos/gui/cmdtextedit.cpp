
#include "cmdtextedit.h"

#include "cmdhighlighter.h"

//#include "hero_controller/cmdsyntax.hpp"

#include <QFont>
#include <QCompleter>
#include <QResizeEvent>
#include <QFocusEvent>
#include <QPlainTextDocumentLayout>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QScrollBar>

#include <assert.h>


CmdTextEdit::CmdTextEdit(QWidget *parent) 
:   QPlainTextEdit(parent)
,   m_highlighter(NULL)
{
    setFont(QFont("Consolas, Courier New, Courier", 9));
    initialize();
}


CmdTextEdit::~CmdTextEdit()
{
    delete m_highlighter;
}


void CmdTextEdit::initialize()
{
    setupHighlighter();
    setupCompleters();

    setupDocument();
}


QTextDocument *CmdTextEdit::createDocument() const
{
    QTextDocument *textdoc(new QTextDocument());

    QPlainTextDocumentLayout* layout = new QPlainTextDocumentLayout(textdoc);
    textdoc->setDocumentLayout(layout);

    textdoc->setDefaultFont(font());

    return textdoc;
}


void CmdTextEdit::setupDocument()
{
    QTextDocument *textdoc(createDocument());

    setDocument(textdoc);

    setTabStopWidth(QFontMetrics(font()).width(QLatin1Char('0')) * 4);

    // setup highlighter

    assert(m_highlighter);
    m_highlighter->setDocument(textdoc);
}


void CmdTextEdit::setupHighlighter()
{
    m_highlighter = new CmdHighlighter();
}


void CmdTextEdit::setupCompleters()
{
/*
    if(m_completer)
    {
        delete m_completer;
        m_completer = NULL;
    }

    if(strings.isEmpty())
        return;

    QStringList strings;
    // TODO: context sensitive completion?

    QStringListModel *slm = new QStringListModel();
    slm->setStringList(strings);

    m_completer = new QCompleter(slm, this);

    m_completer->setCompletionMode(QCompleter::PopupCompletion);
    m_completer->setCaseSensitivity(Qt::CaseInsensitive);

    QObject::connect(m_completer, SIGNAL(activated(const QString&)),
        this, SLOT(insertCompletion(const QString&)));
*/
}


void CmdTextEdit::registerCompleterStrings(const QStringList &strings)
{
    //assert(m_completer);

    //QStringListModel *slm = dynamic_cast<QStringListModel*>(m_completer->model());
    //assert(slm);

    //// TODO: register them
}


void CmdTextEdit::unregisterCompleterStrings(const QStringList &strings)
{
    //assert(m_completer);

    //QStringListModel *slm = dynamic_cast<QStringListModel*>(m_completer->model());
    //assert(slm);

    //// TODO: unregister them
}


void CmdTextEdit::insertCompletion(const QString &completion)
{
    //assert(m_completer);
    //assert(m_completer->widget() == this);

    //QTextCursor tc = textCursor();

    //int extra = completion.length() - m_completer->completionPrefix().length();

    //tc.movePosition(QTextCursor::Left);
    //tc.movePosition(QTextCursor::EndOfWord);

    //tc.insertText(completion.right(extra));

    //setTextCursor(tc);
}


void CmdTextEdit::focusInEvent(QFocusEvent *event)
{
    //if (m_completer)
    //    m_completer->setWidget(this);

    QPlainTextEdit::focusInEvent(event);
}


QString CmdTextEdit::textUnderCursor() const
{
    QTextCursor tc(textCursor());

    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}


// modified from  http://www.trinitydesktop.org/docs/qt4/tools-customcompleter.html

void CmdTextEdit::keyPressEvent(QKeyEvent *event)
{
    if(true /*!m_completer || !m_completer->popup()->isVisible()*/
    && Qt::Key_Enter == event->key() || Qt::Key_Return == event->key()) 
    {
        event->accept();
        process();

        return;
    }

    //if(m_completer && m_completer->popup()->isVisible()) 
    //{
    //    // The following keys are forwarded by the completer to the widget.
    //    switch(event->key()) 
    //    {
    //    case Qt::Key_Enter:
    //    case Qt::Key_Return:
    //    case Qt::Key_Escape:
    //    case Qt::Key_Tab:
    //    case Qt::Key_Backtab:
    //        event->ignore();
    //        // Let the completer do default behavior.
    //        return; 
    //    default:
    //        break;
    //    }
    //}

    // [ctrl + e]

    const bool ctrlE(
        (event->modifiers() & Qt::ControlModifier) && Qt::Key_E == event->key());

    // Don't process the shortcut when we have a completer.

    if(/*!m_completer ||*/ !ctrlE) 
        QPlainTextEdit::keyPressEvent(event);

    const bool tab((event->modifiers() == Qt::NoModifier) && Qt::Key_Tab == event->key());
    const bool ctrlOrShift(event->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier));

    if(/*!m_completer ||*/ tab || (ctrlOrShift && event->text().isEmpty()))
        return;


    static const QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // End of word.

    const bool modifier((event->modifiers() != Qt::NoModifier) && !ctrlOrShift);

    const QString prefix(textUnderCursor());

    if(/*m_completer &&*/ !ctrlE && (modifier || event->text().isEmpty() 
    || prefix.length() < 2 || eow.contains(event->text().right(1)))) 
    {
        /*m_completer->popup()->hide();*/
        return;
    }

    /*if(prefix != m_completer->completionPrefix()) 
    {
        m_completer->setCompletionPrefix(prefix);
        m_completer->popup()->setCurrentIndex(m_completer->completionModel()->index(0, 0));
    }*/

    /*QRect cr(cursorRect());
    cr.setWidth(
        m_completer->popup()->sizeHintForColumn(0) + m_completer->popup()->verticalScrollBar()->sizeHint().width());

    m_completer->popup()->setFont(*m_font);
    m_completer->popup()->setFrameShadow(QFrame::Plain);

    m_completer->complete(cr); // popup it up!*/
}


void CmdTextEdit::on_processPushButton_clicked(bool)
{
    process();
}


void CmdTextEdit::process()
{

}