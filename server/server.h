#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class server;
}

class server : public QDialog
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();

private:
    Ui::server *ui;
    QTcpServer *tcpsvr;
    QTcpSocket *socket;

private slots:
    void init();
    void newconnect();
    void read();
    void send();
};

#endif // SERVER_H
