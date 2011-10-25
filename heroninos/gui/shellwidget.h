
#pragma once
#ifndef __SHELLWIDGET_H__
#define __SHELLWIDGET_H__


#include <QWidget>

class Ui_ShellWidget;


class ShellWidget
:    public QWidget
{
    Q_OBJECT

public:
 
    ShellWidget(QWidget *parent = NULL);
    virtual ~ShellWidget();

protected slots:

    void on_cmdPlainTextEdit_textChanged();

protected:

protected:

    std::auto_ptr<Ui_ShellWidget> m_ui;
};

#endif // __SHELLWIDGET_H__