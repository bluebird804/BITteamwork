#include "logindlg.h"
#include "signupdlg.h"
#include "ui_logindlg.h"
#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::judge(QString user, QString pswd)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");   //数据库服务器ip
    db.setUserName("root");        //数据库用户名
    db.setPassword("123456");      //密码
    db.setDatabaseName("info");    //使用哪个数据库
    if(!db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return false;
    }
    QSqlQuery query(db);
    QString str=QString("select * from usr where name='%1' and password='%2'").arg(user).arg(pswd);
    query.exec(str);
    if(query.first()) return true;
    return false;
}

void Dialog::on_loginbtn_clicked()
{
    if(judge(ui->usnmedit->text(),ui->pswdedit->text()))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);
        ui->usnmedit->clear();
        ui->pswdedit->clear();
        ui->usnmedit->setFocus();
    }
}

void Dialog::on_sinupbtn_clicked()
{
    signupdlg sign;
    sign.exec();
}

void Dialog::on_checkBox_stateChanged()
{
    if(ui->checkBox->checkState()!=0)
        ui->pswdedit->setEchoMode(QLineEdit::Normal);
    else
        ui->pswdedit->setEchoMode(QLineEdit::Password);
}
