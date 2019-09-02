#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    this->connect(ui->cnctbtn,SIGNAL(clicked()),this,SLOT(init()));
    this->connect(ui->sendbtn,SIGNAL(clicked()),this,SLOT(send()));
}

server::~server()
{
    delete ui;
}

void server::init()
{
    tcpsvr=new QTcpServer(this);
    socket =new QTcpSocket(this);
    tcpsvr->listen(QHostAddress::Any,139);
    connect(tcpsvr,SIGNAL(newConnection()),this,SLOT(newconnect()));
}


void server::newconnect()
{
    socket = tcpsvr->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(read()));
}

void server::read()
{
    QString data = socket->readAll();
}

void server::send()
{

}
