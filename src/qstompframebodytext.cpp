#include "qstompframebodytext.h"

#include <QtCore/QDebug>

class QStompFrameBodyTextPrivate {
    public:
        virtual ~QStompFrameBodyTextPrivate() { }
        QString text;
        QString contentType;
};

QStompFrameBodyText::QStompFrameBodyText(const QString &text, const QString &contentType)
    : d_ptr(new QStompFrameBodyTextPrivate)
{
    Q_D(QStompFrameBodyText);

    d->text = text;
    d->contentType = contentType;
}

QStompFrameBodyText::QStompFrameBodyText(QStompFrameBodyTextPrivate &dd)
    : d_ptr(&dd)
{ }

QStompFrameBodyText::~QStompFrameBodyText()
{

}

QString QStompFrameBodyText::text() const
{
    Q_D(const QStompFrameBodyText);

    return d->text;
}

QString QStompFrameBodyText::contentType() const
{
    Q_D(const QStompFrameBodyText);

    return d->contentType;
}

QByteArray QStompFrameBodyText::encode() const
{
    Q_D(const QStompFrameBodyText);

    return d->text.toUtf8();
}


