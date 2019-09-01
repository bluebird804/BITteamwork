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
    query.prepare("CREATE TABLE usr(name varchar,password varchar)");
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
    QString confirm=ui->pswdcfm->text();
    if(!user.isEmpty()&&!passwd.isEmpty()&&!confirm.isEmpty()&&passwd==confirm)
    {
        QSqlQuery query;
        QString str = QString("insert into usr(name, password) values('%1', '%2')").arg(user).arg(passwd);
        QMessageBox::information(NULL, "注册成功", "注册成功！！！", QMessageBox::Yes);
        query.exec(str);
        accept();
    }
    else if(user.isEmpty())
    {
        QMessageBox::warning(this, "错误", "请输入用户名");
    }
    else if(passwd.isEmpty())
    {
        QMessageBox::warning(this, "错误", "请输入密码");
    }
    else if(confirm.isEmpty())
    {
        QMessageBox::warning(this, "错误", "请再次确认密码");
    }
    else
    {
        QMessageBox::warning(this, "错误", "密码不一致");
    }
}
