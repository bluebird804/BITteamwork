//本地服务器存储和验证成功
#include "mainwindow.h"
#include "signupdlg.h"
#include "logindlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    signupdlg sign;
    Dialog log;//登录
    sign.show();
    if(sign.exec()==QDialog::Accepted){
        w.show();
        return a.exec();
    }
    return 0;
}
