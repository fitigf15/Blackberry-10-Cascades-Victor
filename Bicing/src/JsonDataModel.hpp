/*
 * JsonDataModel.hpp
 *
 *  Created on: 07/11/2014
 *      Author: Victor
 */

#ifndef JSONDATAMODEL_HPP_
#define JSONDATAMODEL_HPP_

#include <bb/cascades/QListDataModel>
#include <bb/data/JsonDataAccess>
#include <bb/system/InvokeManager>
#include <QtNetwork/QNetworkReply>

using namespace bb::data;
typedef bb::cascades::QListDataModel<QVariantMap> JsonListDataModel;
typedef QList<QVariantMap> QVariantMapList;

class JsonDataModel: public JsonListDataModel
{
Q_OBJECT

Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

public:

    JsonDataModel(QObject *parent = 0);
    virtual ~JsonDataModel();

    QString url();
    void setUrl(QString url);

    void setJsonData(QVariant data);
    void setIsFavorite(const QVariantList selectionList, const bool isFavorite);
    void deleteJsonItems(const QVariantList selectionList);

    Q_INVOKABLE void applyFilter(QString filter);
Q_SIGNALS:
    void urlChanged(QString url);
    void replyCompleted(QString reply);

private Q_SLOTS:

    void onReplyFinished();

private:

    bool jsonToDataFolder();
    bool saveData();
    void updateItemIsFavoriteAtIndex(QVariantList indexPath, const bool isFavorite);
    void deleteItemAtIndex(QVariantList indexPath);
    void getRequest(QString url);
    void findSettings();
    void parseJsonData(QVariant jsonData);

    QString getLocalTimeFromStation(QString time, QString mode="hh:mm");


    QString m_url;
    QVariantMap m_settings;
};


#endif /* JSONDATAMODEL_HPP_ */
