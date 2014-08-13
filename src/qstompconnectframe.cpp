#include "qstompconnectframe.h"

#include "qstompframe_p.h"

#include <QtCore/QDebug>

class QStompConnectFramePrivate : public QStompFramePrivate {

};

QStompConnectFrame::QStompConnectFrame(const QString &hostName,
                                       const QString &login,
                                       const QString &passCode)
    : QStompFrame(*new QStompConnectFramePrivate, QtStomp::CommandConnect)
{
    setHeader(QtStomp::HeaderAcceptVersion, "1.2");
    setHeader(QtStomp::HeaderHost, hostName);

    if (!login.isEmpty()) {
        setHeader(QtStomp::HeaderLogin, login);
    }

    if (!passCode.isEmpty()) {
        setHeader(QtStomp::HeaderPassCode, passCode);
    }
}

QStompConnectFrame::~QStompConnectFrame()
{

}


