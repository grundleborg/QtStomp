#ifndef TEST_H
#define TEST_H

#include <QtCore/QEventLoop>
#include <QtCore/QObject>

class Test : public QObject {

    Q_OBJECT

    public:
        Test(QObject *parent = 0);
        virtual ~Test();

        QEventLoop *mLoop;

    protected Q_SLOTS:
        void onWatchdogTimerTimeout();
        
        virtual void initImpl();
        virtual void initTestCaseImpl();
        virtual void cleanupImpl();
        virtual void cleanupTestCaseImpl();
};

#endif // TEST_H


