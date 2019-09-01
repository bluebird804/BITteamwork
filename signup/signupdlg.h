#ifndef SIGNUPDLG_H
#define SIGNUPDLG_H

#include <QDialog>

namespace Ui {
class signupdlg;
}

class signupdlg : public QDialog
{
    Q_OBJECT

public:
    explicit signupdlg(QWidget *parent = nullptr);
    ~signupdlg();

private slots:
    void on_cfmbtn_clicked();

private:
    Ui::signupdlg *ui;
};

#endif // SIGNUPDLG_H
