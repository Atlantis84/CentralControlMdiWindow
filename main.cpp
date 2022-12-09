#include "mainwindow.h"
#include <QApplication>
#include "gdatafactory.h"
#include <QDir>
#include "QsLog.h"
#include "QsLogDest.h"
#include <QFile>
using namespace QsLogging;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString qssFile = ":/icon/darkgray.qss";
    QFile file(qssFile);

    Logger& logger = Logger::instance();
    logger.setLoggingLevel(QsLogging::TraceLevel);

    const QString sLogPath(QDir(QApplication::applicationDirPath()).filePath("log.txt"));
    DestinationPtr fileDestination(DestinationFactory::MakeFileDestination(sLogPath, EnableLogRotation, MaxSizeBytes(512*1024), MaxOldLogCount(5)));
    logger.addDestination(fileDestination);

    DestinationPtr debugDestination(DestinationFactory::MakeDebugOutputDestination());
    logger.addDestination(debugDestination);
    QLOG_INFO()<<u8"QsLog Init Done";
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }

    if(GDataFactory::get_pgsql()->ConnectDataBase())
        QLOG_INFO()<<"connect to db success!";
    else {
        QLOG_INFO()<<"connect to db failed!";
        QApplication::exit(1);
    }

    GDataFactory::get_factory()->connect_common_signal_slot();

//    if(GDataFactory::get_welcome_wgt()->exec() == QDialog::Accepted )
        GDataFactory::get_main_window()->show();
//    else
//        QApplication::exit(1);
    return a.exec();
}
