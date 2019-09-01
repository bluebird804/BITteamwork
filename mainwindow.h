
#ifndef MAINWINDOW_H

#define MAINWINDOW_H



#include <QMainWindow>

#include <QtNetwork>

#include <QTcpServer>

#include <QTcpSocket>

#include <QTimer>

#include <QAbstractSocket>

namespace Ui {

class MainWindow;

}



class MainWindow : public QMainWindow

{

    Q_OBJECT



public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();



public:

    void init();

    void newTcpConnect();



private slots:

    void onReciveData();

    void onSendMessage();

    void onShowError(QAbstractSocket::SocketError);



private:

    QTcpSocket *tcpSocket;

    QByteArray mChat;



private:

    Ui::MainWindow *ui;

};



#endif // MAINWINDOW_H
