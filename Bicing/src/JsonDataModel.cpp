#include "JsonDataModel.hpp"

#include <bb/data/JsonDataAccess>
using namespace bb::cascades;
using namespace bb::system;
JsonDataModel::JsonDataModel(QObject *parent){
    setParent(parent);
}
JsonDataModel::~JsonDataModel()
{
}


bool JsonDataModel::saveData()
{
    JsonDataAccess jda;
    QVariantMap m;
    m.insert("settings",m_settings);
    jda.save(m, "app/native/assets/settings.json");
    qDebug() << jda.load("app/native/assets/settings.json");

    if (jda.hasError()) {
        bb::data::DataAccessError error = jda.error();
        qDebug() << "JSON loading error: " << error.errorType() << ": " << error.errorMessage();
        return false;
    }

    return true;
}

void JsonDataModel::getRequest(QString url){
    QNetworkAccessManager* m = new QNetworkAccessManager(this);
    QNetworkReply* reply = m->get(QNetworkRequest(url));
    bool ok = connect(reply,SIGNAL(finished()),this,SLOT(onReplyFinished()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);
}
void JsonDataModel::onReplyFinished(){
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    QVariant jsonData;
    QString response;
    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                const QByteArray buffer(reply->readAll());
                bb::data::JsonDataAccess jda;
                jsonData = jda.loadFromBuffer(buffer);
                response="Loaded successfully";
            }else{
                response="No bytes available";
            }

        }
        else{
            response =  tr("Error: %1 status: %2").arg(reply->errorString(), reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString());
        }
        reply->deleteLater();
    }
    if (response.trimmed().isEmpty()) {
        response = tr("Unable to retrieve request headers");
    }
    //qDebug() << "RESPONSE : " << response;
    parseJsonData(jsonData); // TODO : parse JSON DATA
    emit replyCompleted(response);
}

void JsonDataModel::parseJsonData(QVariant jsonData){
    clear();
    QVariantList l = jsonData.toMap()["network"].toMap()["stations"].toList();
    findSettings();
    foreach(QVariant v, l){
        QVariantMap m  =v.toMap();
        m.insert("localtime",getLocalTimeFromStation(m["timestamp"].toString()));
        m.insert("isFavorite",QVariant(false));
        foreach(QVariant s, m_settings["favorites"].toList()){
            if(m["id"].toString()==s.toMap()["id"].toString()){
                m.insert("isFavorite",QVariant(true));
                break;
            }
        }
        append(m);


    }
    clear();
}

void JsonDataModel::findSettings(){
    qDebug() << "ATTEMPTING TO RETRIEVE SETTINGS";
    JsonDataAccess jda;
    QString filepath("app/native/assets/settings.json");
    QVariantMap m = jda.load(filepath).toMap();
    if (jda.hasError()) {
        bb::data::DataAccessError error = jda.error();
        qDebug() << "JSON loading error: " << error.errorType() << ": "
                << error.errorMessage();
        return;
    }
    if(m.isEmpty()){
        qDebug() << "List is empty, attempt failed, ignoring";
        return;
    }else{
        m_settings.clear();
        m_settings=m["settings"].toMap();
        qDebug() << "DONE";
    }
}


QString JsonDataModel::getLocalTimeFromStation(QString time,QString mode){
    time.replace(time.indexOf('.',Qt::CaseInsensitive),5,"Z");
    QDateTime t = QDateTime::fromString(time,Qt::ISODate);
    return t.toLocalTime().toString(mode);
}

void JsonDataModel::applyFilter(QString filter){
    filter = filter.trimmed();
    QVariantMapList l;
    for(int i=0; i<size();i++){
        QVariant v = value(i);
        l.append(v.toMap());
    }
    clear();
    if(filter.isEmpty()){
        append(l);
    }else{
        foreach (QVariantMap m, l)
        {
            if(m["name"].toString().contains(filter,Qt::CaseInsensitive)){
                append(m);
            }
        }
    }
}

void JsonDataModel::updateItemIsFavoriteAtIndex(QVariantList indexPath, const bool isFavorite)
{
    QVariantMap modelItem = data(indexPath).toMap();
    // Update the item in the list of data.
    modelItem["isFavorite"]= isFavorite;
    QVariantMap m;
    m.insert("id",modelItem["id"].toString());
    QVariantList l = m_settings["favorites"].toList();
    if(l.contains(m)){
        if(!isFavorite) l.removeAt(m_settings["favorites"].toList().indexOf(m));
    }else{
        if(isFavorite)l.append(m);
    }
    m_settings.insert("favorites",l);

    foreach(QVariant v, m_settings["favorites"].toList()){
        qDebug() << v;
    }
    replace(indexPath[0].toInt(),modelItem);

    // Since the item status was changed, it is removed from the model and
    // consequently it is removed from the current list shown by the app.
    //removeAt(itemIndex);
}

void JsonDataModel::setIsFavorite(const QVariantList selectionList, const bool isFavorite)
{
    // If the selectionList parameter is a list of index paths update all the items
    if (selectionList.at(0).canConvert<QVariantList>()) {
        for (int i = selectionList.count() - 1; i >= 0; i--) {
            // Get the item at the index path of position i in the selection list
            QVariantList indexPath = selectionList.at(i).toList();
            updateItemIsFavoriteAtIndex(indexPath, isFavorite);
        }
    } else {
        updateItemIsFavoriteAtIndex(selectionList, isFavorite);
    }

    saveData();
}

void JsonDataModel::deleteItemAtIndex(QVariantList indexPath)
{
    removeAt(indexPath[0].toInt());
}

void JsonDataModel::deleteJsonItems(const QVariantList selectionList)
{
    // If the selectionList parameter is a list of index paths update all the items
    if (selectionList.at(0).canConvert<QVariantList>()) {
        for (int i = selectionList.count() - 1; i >= 0; i--) {

            // Get the item at the index path of position i in the selection list.
            QVariantList indexPath = selectionList.at(i).toList();
            deleteItemAtIndex(indexPath);
        }
    } else {
        deleteItemAtIndex(selectionList);
    }

    saveData();
}

QString JsonDataModel::url(){
    return m_url;
}
void JsonDataModel::setUrl(QString url){
    m_url=url;
    emit urlChanged(url);
    getRequest(m_url);
}


