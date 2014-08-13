#include "test.h"

#include <QtCore/QDebug>
#include <QtCore/QTimer>

#include <cstdlib>

Test::Test(QObject *parent)
    : QObject(parent),
      mLoop(new QEventLoop(this))
{
    QTimer::singleShot(1 * 60 * 1000, this, SLOT(onWatchdogTimerTimeout()));
}

Test::~Test()
{
    delete mLoop;
}

void Test::initImpl()
{

}

void Test::initTestCaseImpl()
{

}

void Test::cleanupImpl()
{

}

void Test::cleanupTestCaseImpl()
{

}

void Test::onWatchdogTimerTimeout()
{
    qWarning() << "Test took too long to run, and watchdog timer timed out. Aborting.";
    std::abort();
}


