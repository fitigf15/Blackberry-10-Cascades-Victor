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

Q_PROPERTY(QString jsonAssetPath READ jsonAssetPath WRITE setJsonAssetPath NOTIFY jsonAssetPathChanged)

Q_PROPERTY(QString jsonDataPath READ jsonDataPath WRITE setJsonDataPath NOTIFY jsonDataPathChanged)


public:

    JsonDataModel(QObject *parent = 0);
    virtual ~JsonDataModel();
    QString jsonAssetPath();
    void setJsonAssetPath(const QString jsonAssetPath);
    QString jsonDataPath();
    void setJsonDataPath(const QString jsonDataPath);
    Q_INVOKABLE void applyFilter(QString filter);

signals:

    void jsonAssetPathChanged(QString jsonAssetPath);
    void jsonDataPathChanged(QString jsonDataPath);

public slots:

    void setIsFavorite(const QVariantList selectionList, const bool isFavorite);
    void deleteJsonItems(const QVariantList selectionList);
    void addJsonItem(const QString itemTitle);
    void editJsonItem(const QVariant item, const QString newItemTitle);

private:

    bool jsonToDataFolder();
    bool saveData();
    void updateItemIsFavoriteAtIndex(QVariantList indexPath, const bool isFavorite);
    void deleteItemAtIndex(QVariantList indexPath);
    void findJson();

    void findFavorites();

    QString getLocalTimeFromStation(QString time, QString mode="hh:mm");

    QString mJsonDataPath;
    QString mJsonAssetsPath;
    QString mJsonFilePath;

    QVariantMapList mJsonData;
    QVariantMap mSettings;
};


#endif /* JSONDATAMODEL_HPP_ */
