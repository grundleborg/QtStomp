#ifndef QT_STOMP_H
#define QT_STOMP_H

#include <QtCore/QString>
#include <QtCore/QVector>

namespace QtStomp {
    enum Command {
        CommandConnect = 0,
        CommandStomp,
        CommandConnected,
        CommandSend,
        CommandSubscribe,
        CommandUnsubscribe,
        CommandAck,
        CommandNack,
        CommandBegin,
        CommandCommit,
        CommandAbort,
        CommandDisconnect,
        CommandMessage,
        CommandReceipt,
        CommandError,
    };

    const QVector<QString> CommandString = {
        "CONNECT",
        "STOMP",
        "CONNECTED",
        "SEND",
        "SUBSCRIBE",
        "UNSUBSCRIBE",
        "ACK",
        "NACK",
        "BEGIN",
        "COMMIT",
        "ABORT",
        "DISCONNECT",
        "MESSAGE",
        "RECEIPT",
        "ERROR"
    };


    const QString HeaderAcceptVersion("accept-version");
    const QString HeaderHost("host");
    const QString HeaderLogin("login");
    const QString HeaderPassCode("pass-code");
}

#endif // QT_STOMP_H


