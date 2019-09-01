#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("客户端"));
    init();
    connect(ui->sendBtn,SIGNAL(clicked(bool)),SLOT(onSendMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init()

{

    tcpSocket = new QTcpSocket;

    newTcpConnect();



    connect(tcpSocket,SIGNAL(readyRead()),SLOT(onReciveData()));

}



void MainWindow::newTcpConnect()

{

    tcpSocket->abort();

    tcpSocket->connectToHost("127.0.0.1",6666);

}



void MainWindow::onReciveData()

{

    QString data = tcpSocket->readAll();

    qDebug()<<data;

    mChat += ("Recv " + data);

    ui->textEdit->setText(mChat);

}



void MainWindow::onSendMessage()

{

    QString textEdit = ui->lineEdit->text();

    QString strData =QString::fromLocal8Bit("Time: ") + QTime::currentTime().toString() + "\n" + textEdit.toLocal8Bit() +"\n";

    QByteArray sendMessage = strData.toLocal8Bit();

    mChat+= ("Send " + sendMessage);

    ui->textEdit->setText(mChat);

    tcpSocket->write(sendMessage);

}



void MainWindow::onShowError(QAbstractSocket::SocketError)

{

    qDebug()<<tcpSocket->errorString();

    tcpSocket->close();

}
