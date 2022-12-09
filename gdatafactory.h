#ifndef GDATAFACTORY_H
#define GDATAFACTORY_H

#include <QObject>
#include "mainwindow.h"
#include "welcomewidget.h"
#include "dmdbaccessinterface.h"
#include "centralwidget.h"
#include "leftwidget.h"
#include "rightheadwidget.h"
#include "rightmainwindow.h"
#include "rightmainwidget.h"
#include "rightquerywidget.h"
#include <QSerialPort>
class GDataFactory : public QObject
{
public:
    GDataFactory();

    void connect_common_signal_slot();
    bool init_serial_port(QString comPort);
//    QSerialPort*
private:
    QSerialPort* m_pSerialPort;
    bool m_pSerialPortInitSign;
public:
    static GDataFactory* get_factory()
    {
        if(m_pGDataFactory == nullptr)
            m_pGDataFactory = new GDataFactory();
        return m_pGDataFactory;
    }

    static MainWindow* get_main_window()
    {
        if(m_pMainWindow == nullptr)
            m_pMainWindow = new MainWindow();
        return m_pMainWindow;
    }

    static WelcomeWidget* get_welcome_wgt()
    {
        if(m_pWelcomeWgt == nullptr)
            m_pWelcomeWgt = new WelcomeWidget();
        return m_pWelcomeWgt;
    }

    static DMDBAccessInterface* get_pgsql()
    {
        if(m_pDMDBAccess == nullptr)
            m_pDMDBAccess = DMDBAccessInterface::GetInterface() ;
        return m_pDMDBAccess;
    }

    static CentralWidget* get_central_wgt()
    {
        if(m_pCentralWgt == nullptr)
            m_pCentralWgt = new CentralWidget();
        return m_pCentralWgt;
    }

    static LeftWidget* get_left_wgt()
    {
        if(m_pLeftWgt == nullptr)
            m_pLeftWgt = new LeftWidget();
        return m_pLeftWgt;
    }

    static RightHeadWidget* get_right_head_wgt()
    {
        if(m_pRightHeadWgt == nullptr)
            m_pRightHeadWgt = new RightHeadWidget();
        return m_pRightHeadWgt;
    }

    static RightMainWindow* get_right_main_window()
    {
        if(m_pRightMainWindow == nullptr)
            m_pRightMainWindow = new RightMainWindow();
        return m_pRightMainWindow;
    }

    static RightMainWidget* get_right_main_wgt()
    {
        if(m_pRightMainWgt == nullptr)
            m_pRightMainWgt = new RightMainWidget();
        return m_pRightMainWgt;
    }

    static RightQueryWidget* get_right_query_wgt()
    {
        if(m_pRightQueryWgt == nullptr)
            m_pRightQueryWgt = new RightQueryWidget();
        return m_pRightQueryWgt;
    }
private:
    static GDataFactory* m_pGDataFactory;
    static MainWindow* m_pMainWindow;
    static WelcomeWidget* m_pWelcomeWgt;
    static DMDBAccessInterface* m_pDMDBAccess;
    static CentralWidget* m_pCentralWgt;
    static LeftWidget* m_pLeftWgt;
    static RightHeadWidget* m_pRightHeadWgt;
    static RightMainWindow* m_pRightMainWindow;
    static RightMainWidget* m_pRightMainWgt;
    static RightQueryWidget* m_pRightQueryWgt;
};

#endif // GDATAFACTORY_H
