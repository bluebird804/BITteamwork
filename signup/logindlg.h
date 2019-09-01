#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    bool judge(QString name,QString password);
    ~Dialog();

private slots:
    void on_loginbtn_clicked();
    void on_checkBox_stateChanged();

private:
    Ui::Dialog *ui;
};

#endif // LOGINDLG_H
