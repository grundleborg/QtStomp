#ifndef Q_STOMP_FRAME_BODY_TEXT_H
#define Q_STOMP_FRAME_BODY_TEXT_H

#include "qstompframebody.h"

#include <QtCore/QScopedPointer>

class QStompFrameBodyTextPrivate;

class QStompFrameBodyText : public QStompFrameBody {

    public:
        QStompFrameBodyText(const QString &text, const QString &contentType = "text/plain");
        virtual ~QStompFrameBodyText();

        QString text() const;

        virtual QString contentType() const;
        virtual QByteArray encode() const;

    protected:
        QScopedPointer<QStompFrameBodyTextPrivate> d_ptr;
        QStompFrameBodyText(QStompFrameBodyTextPrivate &dd);

    private:
        Q_DECLARE_PRIVATE(QStompFrameBodyText);
};

#endif // Q_STOMP_FRAME_BODY_TEXT_H


