#include "qstompframe.h"

#include "qstompframe_p.h"

#include "qtstomp.h"

#include <QtCore/QDebug>

QStompFrame::QStompFrame(QtStomp::Command command)
    : d_ptr(new QStompFramePrivate)
{
    Q_D(QStompFrame);

    d->command = command;
    d->hasBody = false;
    d->receiptRequested = false;
    d->body = 0;
}

QStompFrame::QStompFrame(QStompFramePrivate &dd, QtStomp::Command command)
    : d_ptr(&dd)
{ 
    Q_D(QStompFrame);

    d->command = command;
    d->hasBody = false;
    d->receiptRequested = false;
    if (d->hasBody) {
        delete d->body;
    }
}

QStompFrame::~QStompFrame()
{

}

void QStompFrame::setHeader(const QString &headerName, const QString &headerValue)
{
    Q_D(QStompFrame);

    d->headers.insert(headerName, headerValue);
}

QString QStompFrame::header(const QString &headerName) const
{
    Q_D(const QStompFrame);

    return d->headers.value(headerName);
}

QMap<QString, QString> QStompFrame::headers() const
{
    Q_D(const QStompFrame);

    return d->headers;
}

bool QStompFrame::hasHeader(const QString &headerName) const
{
    Q_D(const QStompFrame);

    return d->headers.contains(headerName);
}

bool QStompFrame::hasBody() const
{
    Q_D(const QStompFrame);

    return d->hasBody;
}

void QStompFrame::setHasBody(bool hasBody)
{
    Q_D(QStompFrame);

    if (hasBody == true) {
        Q_ASSERT(d->command == QtStomp::CommandSend
              || d->command == QtStomp::CommandMessage
              || d->command == QtStomp::CommandError);
        if (! (d->command == QtStomp::CommandSend)
           || (d->command == QtStomp::CommandMessage)
           || (d->command == QtStomp::CommandError)) {
            qWarning() << "This command type does not support having a body.";
            return;
        }
    }

    d->hasBody = hasBody;
}

bool QStompFrame::isReceiptRequested() const
{
    Q_D(const QStompFrame);

    return d->receiptRequested;
}

void QStompFrame::setReceiptRequested(bool receiptRequested)
{
    Q_D(QStompFrame);

    // TODO: Check if this command type supports receipt requested.

    d->receiptRequested = receiptRequested;
}

QString QStompFrame::commandString() const
{
    Q_D(const QStompFrame);

    return QtStomp::CommandString[d->command];
}

QStompFrameBody *QStompFrame::body() const
{
    Q_D(const QStompFrame);

    return d->body;
}

void QStompFrame::setBody(QStompFrameBody *body)
{
    Q_D(QStompFrame);

    if (body != 0) {
        setHasBody(true);
        if (hasBody()) {
            d->body = body;
            d->encodedBody = body->encode();
            d->headers.insert("content-length", QString::number(d->encodedBody.length()));
            d->headers.insert("content-type", body->contentType());
        }
    } else {
        d->body = 0;
        d->encodedBody = QByteArray();
        d->headers.remove("content-length");
        d->headers.remove("content-type");
        setHasBody(false);
    }
}

QByteArray QStompFrame::encodeFrame() const
{
    Q_D(const QStompFrame);

    QString head = commandString();
    head.append(QChar(QChar::LineFeed));

    QMapIterator<QString, QString> i(d->headers);
    while(i.hasNext()) {
        i.next();
        head.append(encodeHeader(i.key(), i.value()));
        head.append(QChar(QChar::LineFeed));
    }
    head.append(QChar(QChar::LineFeed));

    QByteArray frame = head.toUtf8();
    frame.append(d->encodedBody);
    frame.append((char)0);
    
    return frame;
}

QString QStompFrame::encodeHeader(QString headerName, QString headerValue) const
{
    headerName.replace(QChar(QChar::CarriageReturn), "\\r");
    headerName.replace(QChar(QChar::LineFeed), "\\n");
    headerName.replace(':', "\\c");
    headerName.replace('\\', "\\\\");

    headerValue.replace(QChar(QChar::CarriageReturn), "\\r");
    headerValue.replace(QChar(QChar::LineFeed), "\\n");
    headerValue.replace(':', "\\c");
    headerValue.replace('\\', "\\\\");

    return headerName + ":" + headerValue;
}


