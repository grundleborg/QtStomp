#ifndef Q_STOMP_CONNECTION_H
#define Q_STOMP_CONNECTION_H

#include "qstompframe.h"

#include <QtCore/QObject>
#include <QtCore/QScopedPointer>
#include <QtCore/QString>

#include <QtNetwork/QAbstractSocket>

class QStompConnectionPrivate;

class QStompConnection : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(QStompConnection);

    public:
        explicit QStompConnection(QObject *parent = 0);
        ~QStompConnection();

        void setHostName(const QString &hostName);
        void setPort(quint16 port);
        void setLogin(const QString &login);
        void setPassCode(const QString &passCode);

        QString hostName() const;
        quint16 port() const;
        QString login() const;
        QString passCode() const;

    public Q_SLOTS:
        void connectToServer();
        void disconnectFromServer();

        void sendFrame(const QStompFrame &frame);

    protected:
        const QScopedPointer<QStompConnectionPrivate> d_ptr;

    Q_SIGNALS:
        void connected();
        void disconnected();
        void connectFailed();
        void disconnectFailed();

        void connectedFrameReceived(const QStompFrame &frame);
        void errorFrameReceived(const QStompFrame &frame);
        void messageFrameReceived(const QStompFrame &frame);
        void receiptFrameReceived(const QStompFrame &frame);

    private Q_SLOTS:
        void onSocketConnected();
        void onSocketDisconnected();
        void onSocketError(QAbstractSocket::SocketError socketError);
        void onConnectedFrameReceived(const QStompFrame &frame);

    private:
        Q_DECLARE_PRIVATE(QStompConnection);
};

#endif // Q_STOMP_CONNECTION_H


