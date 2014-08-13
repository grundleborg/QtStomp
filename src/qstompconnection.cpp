#include "qstompconnection.h"

#include "qstompconnectframe.h"

#include <QtCore/QDebug>

#include <QtNetwork/QTcpSocket>

class QStompConnectionPrivate {
    public:
        virtual ~QStompConnectionPrivate() { }
        QString hostName;
        quint16 port;
        QString login;
        QString passCode;

        QTcpSocket socket;
};

QStompConnection::QStompConnection(QObject *parent)
    : QObject(parent),
      d_ptr(new QStompConnectionPrivate)
{
    Q_D(QStompConnection);

    connect(&d->socket, SIGNAL(connected()),
            this, SLOT(onSocketConnected()));
    connect(&d->socket, SIGNAL(disconnected()),
            this, SLOT(onSocketDisconnected()));
    connect(&d->socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(connectedFrameReceived(QStompFrame)),
            this, SLOT(onConnectedFrameReceived(QStompFrame)));
}

QStompConnection::~QStompConnection()
{

}

QString QStompConnection::hostName() const
{
    Q_D(const QStompConnection);

    return d->hostName;
}

void QStompConnection::setHostName(const QString &hostName)
{
    Q_D(QStompConnection);

    d->hostName = hostName;
}

quint16 QStompConnection::port() const
{
    Q_D(const QStompConnection);

    return d->port;
}

void QStompConnection::setPort(quint16 port)
{
    Q_D(QStompConnection);

    d->port = port;
}

QString QStompConnection::login() const
{
    Q_D(const QStompConnection);

    return d->login;
}

void QStompConnection::setLogin(const QString &login)
{
    Q_D(QStompConnection);

    d->login = login;
}

QString QStompConnection::passCode() const
{
    Q_D(const QStompConnection);

    return d->passCode;
}

void QStompConnection::setPassCode(const QString &passCode)
{
    Q_D(QStompConnection);

    d->passCode = passCode;
}

void QStompConnection::connectToServer()
{
    Q_D(QStompConnection);

    Q_ASSERT(d->socket.state() == QAbstractSocket::UnconnectedState);
    if (d->socket.state() != QAbstractSocket::UnconnectedState) {
        qWarning() << "Attempted to connect a socket that is already in a connected state.";
        return;
    }

    d->socket.connectToHost(d->hostName, d->port);
}

void QStompConnection::disconnectFromServer()
{
    // TODO: Send disconnect frame.
    
    // TODO: Disconnect the socket.
}

void QStompConnection::onSocketConnected()
{
    Q_D(QStompConnection);

    // TODO: Carry out the STOMP connection process
    QStompConnectFrame connectFrame(d->hostName, d->login, d->passCode);
    sendFrame(connectFrame);

    // TODO: Only after that is done, emit the connected signal
}

void QStompConnection::onSocketDisconnected()
{
    Q_EMIT disconnected();
}

void QStompConnection::onSocketError(QAbstractSocket::SocketError socketError)
{
    // TODO: See what the error is and forward the appropriate signal.
}

void QStompConnection::sendFrame(const QStompFrame &frame)
{
    Q_D(QStompConnection);

    // TODO: Assert that the socket is open to send frames over.
    
    d->socket.write(frame.encodeFrame());
}

void QStompConnection::onConnectedFrameReceived(const QStompFrame &frame)
{
    // TODO: Implement me!
}


