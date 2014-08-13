#include "lib/test.h"

#include "qstompconnection.h"

#include <QtCore/QDebug>

#include <QtTest>

class TestConnection : public Test {
    Q_OBJECT

    private Q_SLOTS:
        void testNothing();
        void testConnecting();
};

void TestConnection::testNothing()
{
    qDebug() << "Doing Nothing.";
    QVERIFY(true);
}

void TestConnection::testConnecting()
{
    qDebug() << "Testing Connecting.";

    QStompConnection c(this);
    
    c.setHostName("localhost");
    c.setPort(12098);
    c.setLogin("testlogin");
    c.setPassCode("testpasscode");

    c.connectToServer();

    QCOMPARE(mLoop->exec(), 0);
}

QTEST_MAIN(TestConnection);

#include "test-connection.moc"


