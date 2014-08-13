#ifndef Q_STOMP_FRAME_BODY_H
#define Q_STOMP_FRAME_BODY_H

#include <QtCore/QByteArray>
#include <QtCore/QString>

class QStompFrameBody {

    public:
        QStompFrameBody();
        virtual ~QStompFrameBody();

        virtual QString contentType() const = 0;
        virtual QByteArray encode() const = 0;
};

#endif // Q_STOMP_FRAME_BODY_H


