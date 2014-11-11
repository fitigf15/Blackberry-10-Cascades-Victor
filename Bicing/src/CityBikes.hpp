/*
 * MyBikes.hpp
 *
 *  Created on: 11/11/2014
 *      Author: Victor
 */

#ifndef _CITYBIKES_HPP_
#define _CITYBIKES_HPP_
#include <bb/cascades/QListDataModel>
#include <bb/cascades/Image>
#include <bb/cascades/maps/MapImageGenerator>
#include <bb/system/InvokeManager>
#include <QtNetwork/QNetworkReply>

typedef bb::cascades::QListDataModel<QVariantMap> JsonListDataModel;
typedef QList<QVariantMap> QVariantMapList;

namespace bb
{
    namespace cascades
    {
        class Image;
        class LocaleHandler;
        namespace maps {
            class MapView;
            class MapImageGenerator;
        }
    }
    namespace platform {
        namespace geo {
            class GeoLocation;
        }
    }
}
class QTranslator;
class CityBikes: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString currentLocationID READ currentLocationID WRITE setCurrentLocationID NOTIFY currentLocationIDChanged)
    Q_PROPERTY(bb::cascades::Image staticMapImage READ staticMapImage WRITE setStaticMapImage NOTIFY staticMapImageChanged)

public:

    CityBikes();
    virtual ~CityBikes();

    QString url();
    void setUrl(QString url);
    QString currentLocationID();
    void setCurrentLocationID(QString currentLocationID);
    bb::cascades::Image staticMapImage();
    void setStaticMapImage(bb::cascades::Image i);



    void setJsonData(QVariant data);
    void setIsFavorite(const QVariantList selectionList, const bool isFavorite);
    void deleteJsonItems(const QVariantList selectionList);
    Q_INVOKABLE void updateDeviceLocation(double lat, double lon);
    Q_INVOKABLE void applyFilter(QString filter);

Q_SIGNALS:
    void urlChanged(QString url);
    void currentLocationIDChanged(QString currentLocationID);
    void staticMapImageChanged(bb::cascades::Image i);
    void replyCompleted(QString reply);

private Q_SLOTS:

    void onReplyFinished();
    void onImageFinished(bb::cascades::maps::MapImageGenerator*);

private slots:

    void onSystemLanguageChanged();

private:

    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler *m_pLocaleHandler;
    bb::cascades::maps::MapView *m_mapView;
    bb::platform::geo::GeoLocation *m_deviceLocation;
    JsonListDataModel* m_jsonDataModel;
    bb::cascades::Image m_staticMapImage;


    void addGeoLocation(QVariantMap map);
    void updateItemIsFavoriteAtIndex(QVariantList indexPath, const bool isFavorite);
    void deleteItemAtIndex(QVariantList indexPath);
    void getRequest(QString url);
    void findSettings();
    void parseJsonData(QVariant jsonData);
    void getMapImage(double lat,double lon);

    QString getLocalTimeFromStation(QString time, QString mode="hh:mm");
    bool jsonToDataFolder();
    bool saveData();

    QString m_url;
    QVariantMap m_settings;
    QString m_currentLocationID;



};

#endif
