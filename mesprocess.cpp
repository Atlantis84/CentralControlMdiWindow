#include "mesprocess.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include "QsLog.h"
MesProcess::MesProcess(QObject *parent) : QObject(parent)
{
    accessManager = new QNetworkAccessManager(this);
    connect(accessManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_urlReply(QNetworkReply*)));
}

void MesProcess::exec_http_post()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://127.0.0.1:8088/post"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

    QJsonObject  root, data_value,ats_models;
    QJsonArray   ats_value;

    ats_models.insert("itemId","");
    ats_models.insert("itemName","C1");
    ats_models.insert("itemL_Limit","");
    ats_models.insert("itemH_Limit","");
    ats_models.insert("itemTsValue","");
    ats_models.insert("itemLength","");
    ats_models.insert("itemRes","OK");
    ats_models.insert("errCodes","SX;LB");

    ats_value.append(ats_models);
    root.insert("atsTsItemsModels", ats_value);

    root.insert("iType", "1");
    root.insert("pcbCode", "56CTA69");
    root.insert("workStationSn", "WS101A01");
    root.insert("tsRes","OK");
    root.insert("tsLength", "");
    root.insert("pcName", "sys001");
    root.insert("pcIp", "127.0.0.1");
    root.insert("devName","µÂÂÉAOI");
    root.insert("devModel", "DL2000");
    root.insert("devNo", "ZD_AOI001");
    root.insert("toolNo", "");
    root.insert("toolBitSn", "");
    root.insert("logData", "");

    data_value.insert("imeiInfo","11");
    data_value.insert("meidInfo","22");
    data_value.insert("macInfo","22");
    root.insert("data",data_value);

    QJsonDocument doc_data(root);
    QByteArray request_data = doc_data.toJson(QJsonDocument::Compact);
    accessManager->post(request, request_data);
}

void MesProcess::slot_urlReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError){

        QByteArray responseByte = reply->readAll();
        QLOG_DEBUG()<<"Predict response:" << QString(responseByte);
    }
    else {
        QLOG_WARN()<<"http recv ERROR!";
    }
}
