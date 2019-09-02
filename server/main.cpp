#include "server.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server s;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");   //数据库服务器ip
    db.setUserName("root");        //数据库用户名
    db.setPassword("123456");      //密码
    db.setDatabaseName("info");    //使用哪个数据库
    if(!db.open())
    {
        QMessageBox::warning(NULL, "错误", db.lastError().text());
        return a.exec();
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE usr(name varchar,password varchar)");
    query.exec();
    s.show();

    return a.exec();
}
