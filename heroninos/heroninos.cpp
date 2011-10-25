
#include "gui/shellwidget.h"

#include <QtGui/QApplication>


int main(int argc, char** argv) 
{
    int result = -1;

    QApplication a(argc, argv);

    ShellWidget w;
    w.show();

    result = a.exec();

    return result;
}




//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QMessageBox>
//#include <QFile>

    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLCIPHER");

    //if(!QFile::exists("test.db"))
    //{
    //    db.setDatabaseName("test.db");
    //    if(!db.open()) 
    //    {
    //        QMessageBox::critical(0, "Cannot open database"
    //            , "Unable to establish a database connection.\nThis example needs SQLCipher support."
    //            , QMessageBox:: Cancel);

    //        return -1;
    //    }

    //    QSqlQuery q;
    //    q.exec("pragma key = '12345678';");
    //    q.exec("create table person (id int primary key, name varchar (20), address varchar (200), typeid int)");
    //}
