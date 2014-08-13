#ifndef Q_STOMP_FRAME_H
#define Q_STOMP_FRAME_H

#include "qstompframebody.h"
#include "qtstomp.h"

#include <QtCore/QByteArray>
#include <QtCore/QMap>
#include <QtCore/QScopedPointer>
#include <QtCore/QString>

class QStompFramePrivate;

class QStompFrame {

    public:
        explicit QStompFrame(QtStomp::Command command);
        virtual ~QStompFrame();

        void setHeader(const QString &headerName, const QString &headerValue);
        QString header(const QString &headerName) const;
        QMap<QString, QString> headers() const;
        bool hasHeader(const QString &headerName) const;
        
        bool hasBody() const;

        QStompFrameBody *body() const;
        void setBody(QStompFrameBody *body);

        bool isReceiptRequested() const;
        void setReceiptRequested(bool receiptRequested);

    protected:
        QString commandString() const;

        void setHasBody(bool hasBody);

        QByteArray encodeBody() const;
        QByteArray encodeFrame() const;

        QScopedPointer<QStompFramePrivate> d_ptr;
        QStompFrame(QStompFramePrivate &dd, QtStomp::Command command);

    private:
        QString encodeHeader(QString headerName, QString headerValue) const;

        QStompFramePrivate const * d;

        friend class QStompConnection;

        Q_DECLARE_PRIVATE(QStompFrame);
};

#endif // Q_STOMP_FRAME_H


