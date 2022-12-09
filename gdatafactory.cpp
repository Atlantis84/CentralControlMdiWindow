#include "gdatafactory.h"
#include "QsLog.h"
GDataFactory* GDataFactory::m_pGDataFactory=nullptr;
MainWindow* GDataFactory::m_pMainWindow = nullptr;
WelcomeWidget* GDataFactory::m_pWelcomeWgt = nullptr;
DMDBAccessInterface* GDataFactory::m_pDMDBAccess = nullptr;
CentralWidget* GDataFactory::m_pCentralWgt=nullptr;
LeftWidget* GDataFactory::m_pLeftWgt =nullptr;
RightHeadWidget* GDataFactory::m_pRightHeadWgt=nullptr;
RightMainWindow* GDataFactory::m_pRightMainWindow = nullptr;
RightMainWidget* GDataFactory::m_pRightMainWgt=nullptr;
RightQueryWidget* GDataFactory::m_pRightQueryWgt=nullptr;
GDataFactory::GDataFactory()
{
    m_pSerialPort = new QSerialPort();
    m_pSerialPortInitSign = false;
}

void GDataFactory::connect_common_signal_slot()
{
    connect(get_left_wgt(),SIGNAL(signal_send_path(const QString)),get_right_query_wgt(),SLOT(slot_rev_path(const QString)));
    connect(get_right_query_wgt(),SIGNAL(signal_add_sub_window(const QString,const QString)),get_right_main_wgt(),
            SLOT(slot_add_sub_window(const QString,const QString)));
}

bool GDataFactory::init_serial_port(QString comPort)
{
    if(m_pSerialPortInitSign)
        return m_pSerialPortInitSign;
    else
    {
        m_pSerialPort->setPortName(comPort);
        m_pSerialPortInitSign = m_pSerialPort->open(QIODevice::ReadWrite);
        if(!m_pSerialPortInitSign)
        {
            QLOG_INFO()<<comPort<<" Open failed!";
            return m_pSerialPortInitSign;
        }
        else
        {
            QLOG_INFO()<<comPort<<" Open Success!";
            m_pSerialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
            m_pSerialPort->setDataBits(QSerialPort::Data8);
            m_pSerialPort->setFlowControl(QSerialPort::NoFlowControl);
            m_pSerialPort->setParity(QSerialPort::NoParity);
            m_pSerialPort->setStopBits(QSerialPort::OneStop);
            m_pSerialPort->clear();
        }
    }
    return m_pSerialPortInitSign;
}
