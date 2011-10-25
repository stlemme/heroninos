
#include "shellwidget.h"
#include "heroninos/ui_shellwidget.h"

#include <assert.h>


ShellWidget::ShellWidget(QWidget* parent)
:   QWidget(parent)
,   m_ui(new Ui_ShellWidget)
{
    m_ui->setupUi(this);

    m_ui->outputPlainTextEdit->setFont(m_ui->cmdPlainTextEdit->font());
}


ShellWidget::~ShellWidget()
{
}


#include <QTime>
#include <QFileInfo>

#include "hero_cmd/cmd_make.h"

void ShellWidget::on_cmdPlainTextEdit_textChanged()
{
    QString cmdLine = m_ui->cmdPlainTextEdit->toPlainText().trimmed();

    CmdMake cmdMake;

    QTime t0;

    const bool test = cmdMake.parse(cmdLine);

    QTime t1;

    QString out;
    
    out += QString("\nsyntax: %1").arg(cmdMake.syntax());
    out += QString("\nparsing %1").arg(test ? "succeeded" : cmdMake.error());
    out += "\n";
    out += QString("\nfilepath: %1").arg(test ? cmdMake.filePath().absoluteFilePath() : "invalid"); 
    out += QString("\npassphrase: %1").arg(test ? cmdMake.passphrase() : "invalid"); 
    out += QString("\n\n\tparsed in less than %1 msecs").arg(t0.msecsTo(t1));

    m_ui->outputPlainTextEdit->setPlainText(out);
}


/*
void ShellWidget::on_cmdPlainTextEdit_textChanged()
{
    QString in = m_ui->cmdPlainTextEdit->toPlainText().trimmed();

    // |\\d+[\\.,]\\d+|[\\.,]\\d+
    QString number("^((\\d+(?![\\.,])|\\d*[\\.,]\\d+)(?![\\.,])\\b)");
    QString op("^\\s+(<<|>>)");
    QString accounts("^\\s+(daniel|annika|liara)\\b");
    QString note("^\\s+\\\"([^\\n\\r\\v\\t]+)\\\"");
    QString tags("^\\s+(\\b#[^#\\n\\r\\v\\t]+\\b)+");

    QString out;
    
    // step 1

    QRegExp s1(number, Qt::CaseInsensitive);
    assert(s1.isValid());

    const int i1 = s1.indexIn(in);

    out += "checking for number: ";

    if(i1 != -1)
        out += "succeeded -> " + s1.capturedTexts().first();
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(s1);


    // step 2 find argument one : file path

    QRegExp s2(op, Qt::CaseInsensitive);
    assert(s2.isValid());

    s2.setMinimal(true);

    const int i2 = s2.indexIn(in);
    const int l2 = s2.matchedLength();

    out += "checking for operator: ";

    if(i2 != -1 && s2.captureCount() == 1)
    {
        out += "succeeded -> " + s2.capturedTexts().last();
    }
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(i2, l2);


   // step 3 find argument one : file path

    QRegExp s3(accounts, Qt::CaseInsensitive);
    assert(s3.isValid());

    s3.setMinimal(true);

    const int i3 = s3.indexIn(in);
    const int l3 = s3.matchedLength();

    out += "checking for accounts: ";

    if(i3 != -1 && s3.captureCount() == 1)
    {
        out += "succeeded -> " + s3.capturedTexts().last();
    }
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(i3, l3);


    
    if(in.isEmpty())
    {
        out += "checking if is empty: succeeded";

         m_ui->outputPlainTextEdit->setPlainText(out);
         return;
    }



   // step 3 find argument one : file path

    QRegExp s4(note, Qt::CaseInsensitive);
    assert(s4.isValid());

    s4.setMinimal(true);

    const int i4 = s4.indexIn(in);
    const int l4 = s4.matchedLength();

    if(i4 != -1)
    {
        out += "checking for note: ";

        if(s4.captureCount() == 1)
        {
            out += "succeeded -> " + s4.capturedTexts().last();
        }
        else 
        {
            out += "failed ? " + in;
            m_ui->outputPlainTextEdit->setPlainText(out);
            return;
        }

        out += "\n";
        in.remove(i4, l4);


        if(in.isEmpty())
        {
            out += "checking if is empty: succeeded";

             m_ui->outputPlainTextEdit->setPlainText(out);
             return;
        }

    }



   // step 3 find argument one : file path

    QRegExp s5(tags, Qt::CaseInsensitive);
    assert(s5.isValid());

    s5.setMinimal(true);

    const int i5 = s5.indexIn(in);
    const int l5 = s5.matchedLength();

        out += "checking for tags: ";

        if(i5 != -1 && s5.captureCount() == 1)
        {
            out += "succeeded -> " + s5.capturedTexts().last();
        }
        else 
        {
            out += "failed ? " + in;
            m_ui->outputPlainTextEdit->setPlainText(out);
            return;
        }

        out += "\n";
        in.remove(i5, l5);


        if(in.isEmpty())
        {
            out += "checking if is empty: succeeded";

             m_ui->outputPlainTextEdit->setPlainText(out);
             return;
        }


//
//    //const QString filePathArg("(\"[^:\\n\\r\\t\\t\*\\?<>\\|]+\")");
//    //const QString passphraseArg("(\"[^:\\n\\r\\t\\t\*\\?<>\\|]+\")");
//
////    QRegExp cmd("^make\\b\\s+\\s*(\\s+bencrypted with\\s+(\".[^\\n\\r\\t\\v\\a\\f]+\"))?");
//
//  //  assert(cmd.isValid());
//
//    //cmd.indexIn(in);
//    //QString out = cmd.capturedTexts().join("\n");
//    
//    out += "checking if is empty: ";
//
//    if(in.isEmpty())
//        out += "succeeded";
//    else
//    {
//        out += "failed";
//        m_ui->outputPlainTextEdit->setPlainText(out);
//        return;
//    }
//

    m_ui->outputPlainTextEdit->setPlainText(out);
}
//*/


/*
void ShellWidget::on_cmdPlainTextEdit_textChanged()
{
    QString in = m_ui->cmdPlainTextEdit->toPlainText().trimmed();

    QString command("^(\\bmake\\b)");
    QString filepath("^\\s+\\\"([^:\\\"\\n\\r\\v\\t\\*\\?<>\\|]+)\\\"");
    QString encrypted("^\\s+(encrypted:)");
    QString pw("^\\s+\\\"([^\\n\\r\\v\\t]+)\\\"");

    QString out;
    
    // step 1

    QRegExp s1(command, Qt::CaseInsensitive);
    assert(s1.isValid());

    const int i1 = s1.indexIn(in);

    out += "checking for command: ";

    if(i1 != -1 && s1.captureCount() == 1)
        out += "succeeded -> " + s1.capturedTexts().last();
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(s1);


    // step 2 find argument one : file path

    QRegExp s2(filepath, Qt::CaseInsensitive);
    assert(s2.isValid());

    s2.setMinimal(true);

    const int i2 = s2.indexIn(in);
    const int l2 = s2.matchedLength();

    out += "checking for filepath: ";

    if(i2 != -1 && s2.captureCount() == 1)
    {
        out += "succeeded -> " + s2.capturedTexts().last();
    }
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(i2, l2);

    if(in.isEmpty())
    {
        out += "checking if is empty: succeeded";

         m_ui->outputPlainTextEdit->setPlainText(out);
         return;
    }



   // step 3 find argument one : file path

    QRegExp s3(encrypted, Qt::CaseInsensitive);
    assert(s3.isValid());

    s3.setMinimal(true);

    const int i3 = s3.indexIn(in);
    const int l3 = s3.matchedLength();

    out += "checking for encrypted: ";

    if(i3 != -1 && s3.captureCount() == 1)
    {
        out += "succeeded -> " + s3.capturedTexts().last();
    }
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(i3, l3);



   // step 3 find argument one : file path

    QRegExp s4(pw, Qt::CaseInsensitive);
    assert(s4.isValid());

    s4.setMinimal(true);

    const int i4 = s4.indexIn(in);
    const int l4 = s4.matchedLength();

    out += "checking for pw: ";

    if(i4 != -1 && s4.captureCount() == 1)
    {
        out += "succeeded -> " + s4.capturedTexts().last();
    }
    else
    {
        out += "failed ? " + in;
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }

    out += "\n";
    in.remove(i4, l4);

    //const QString filePathArg("(\"[^:\\n\\r\\t\\t\*\\?<>\\|]+\")");
    //const QString passphraseArg("(\"[^:\\n\\r\\t\\t\*\\?<>\\|]+\")");

//    QRegExp cmd("^make\\b\\s+\\s*(\\s+bencrypted with\\s+(\".[^\\n\\r\\t\\v\\a\\f]+\"))?");

  //  assert(cmd.isValid());

    //cmd.indexIn(in);
    //QString out = cmd.capturedTexts().join("\n");
    
    out += "checking if is empty: ";

    if(in.isEmpty())
        out += "succeeded";
    else
    {
        out += "failed";
        m_ui->outputPlainTextEdit->setPlainText(out);
        return;
    }


    m_ui->outputPlainTextEdit->setPlainText(out);
}
//*/