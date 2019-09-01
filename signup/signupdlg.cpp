#include "signupdlg.h"
#include "ui_signupdlg.h"
#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

signupdlg::signupdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupdlg)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");   //数据库服务器ip
    db.setUserName("root");        //数据库用户名
    db.setPassword("123456");      //密码
    db.setDatabaseName("info");    //使用哪个数据库
    if(!db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE usr(name int,password int)");
    query.exec();
}

signupdlg::~signupdlg()
{
    delete ui;
}

void signupdlg::on_cfmbtn_clicked()
{
    QString user=ui->usnmedit->text();
    QString passwd=ui->pswdedit->text();
    QString confirm=ui->pswdcfm->text();//密码确认未写

    if(!user.isEmpty()&&!passwd.isEmpty())
    {
        QSqlQuery query;
        QString str = QString("insert into usr(name, password) values('%1', '%2')").arg(user).arg(passwd);
        query.exec(str);
        accept();
    }
}
