#ifndef Q_STOMP_FRAME_P_H
#define Q_STOMP_FRAME_P_H

#include "qtstomp.h"

#include <QtCore/QMap>
#include <QtCore/QString>

class QStompFramePrivate {
    public:
        virtual ~QStompFramePrivate() { }
        QMap<QString, QString> headers;
        bool hasBody;
        bool receiptRequested;
        QtStomp::Command command;
        QByteArray encodedBody;
        QStompFrameBody *body;
};


#endif // Q_STOMP_FRAME_P_H


