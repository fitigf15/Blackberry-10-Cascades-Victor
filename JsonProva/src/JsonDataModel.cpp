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
    QString favoritesFilePath("app/native/assets/settings.json");
    QVariantList l;
    foreach(QVariantMap m,mJsonData){
        l.append(m);
        //qDebug() << m["extra"].toMap()["uid"].toString() << " : " << m["isFavorite"];
    }
    QVariantMap m;
    QVariantMap m2;
    m.insert("stations",l);
    m2.insert("network",m);
    qDebug() << "BEFORE";
    qDebug() << jda.load(mJsonFilePath);
    qDebug() << jda.load(favoritesFilePath);
    jda.save(m2, mJsonFilePath);
    m.clear();
    m.insert("settings",mSettings);
    jda.save(m, favoritesFilePath);
    qDebug() << "AFTER";
    qDebug() << jda.load(mJsonFilePath);
    qDebug() << jda.load(favoritesFilePath);

    if (jda.hasError()) {
        bb::data::DataAccessError error = jda.error();
        qDebug() << "JSON loading error: " << error.errorType() << ": " << error.errorMessage();
        return false;
    }

    return true;
}

bool JsonDataModel::jsonToDataFolder()
{
    // Since we need read-write access to the database, the JSON file has
    // to be moved to a folder where we have that access (application's data folder).
    // First, we check if the file already exists (previously copied)
    QStringList pathSplit = mJsonAssetsPath.split("/");
    QString fileName = pathSplit.last();
    QString dataFolder = QDir::homePath();

    // The path to the file in the data folder
    mJsonFilePath = dataFolder + "/" + fileName;
    QFile newFile(mJsonFilePath);

    if (!newFile.exists()) {
        // If the file is not already in the data folder, we copy it from the
        // assets folder (read only) to the data folder (read and write).
        // Note that on a debug build you will be able to write to a database
        // in the assets folder but that is not possible on a signed application.
        QString appFolder(QDir::homePath());
        appFolder.chop(4);
        QString originalFileName = appFolder + mJsonAssetsPath;
        QFile originalFile(originalFileName);

        if (originalFile.exists()) {
            return originalFile.copy(mJsonFilePath);
        } else {
            qDebug() << "Failed to copy file data base file does not exists.";
            return false;
        }
    }

    return true;
}

void JsonDataModel::findFavorites(){
    qDebug() << "ATTEMPTING TO RETRIEVE FAVORITES";
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

        mSettings.clear();
        mSettings=m["settings"].toMap();
        qDebug() << "DONE";
    }
}

void JsonDataModel::findJson(){

    //qDebug() << "ATTEMPTING TO FIND A LIST INTO JSON WITH DATA PATH: "<<mJsonDataPath<<" (CAN BE EMPTY) AND ASSETS PATH: " <<mJsonAssetsPath;
    JsonDataAccess jda;
    QVariantList l;

    if(mJsonDataPath=="" and mJsonAssetsPath!=""){
        //qDebug() << "Json data path is empty but json assets path are not empty, proceed";
        if (jsonToDataFolder()) {
            l = jda.load(mJsonFilePath).toList();
        }

    }
    if(mJsonDataPath!="" and mJsonAssetsPath!=""){
        //qDebug() << "Json data path and json assets path are not empty, proceed";

        if (jsonToDataFolder()) {

               QVariantMap tempMap;
               if(mJsonDataPath.contains("/",Qt::CaseInsensitive)){
                   QStringList pathSplit = mJsonDataPath.split("/");
                   //qDebug() << "BROWSING THE PATH LIST: " << pathSplit;
                   if(pathSplit.first()==""){
                       pathSplit.pop_front();
                       //qDebug() << "STARTING WITH /path.. POPPING FIRST EMPTY ELEMENT FROM THE PATH LIST. RESULT: " << pathSplit;

                   }
                   //qDebug() << "FOUND" << jda.load(mJsonFilePath);
                   //qDebug() << "JOINING "+pathSplit.first();
                   tempMap= jda.load(mJsonFilePath).toMap()[pathSplit.first()].toMap();
                   pathSplit.pop_front();
                   //qDebug() << "RESTING PATH: "<< pathSplit ;
                   //qDebug() << "ACTUAL MAP: " << tempMap ;
                   //qDebug() << "POPPING THE REST OF ELEMENTS ON THE PATH LIST.";
                   while(!pathSplit.isEmpty()){
                       //qDebug() << "POPPING AND JOINING: "+pathSplit.first()+", result:";
                       if (pathSplit.last()!=pathSplit.first()){
                           tempMap= tempMap[pathSplit.first()].toMap();
                           pathSplit.pop_front();
                           //qDebug() << "RESTING PATH: " << pathSplit;
                           //qDebug() << "ACTUAL MAP: " << tempMap;
                       }else{
                           l = tempMap[pathSplit.first()].toList();
                           pathSplit.pop_front();
                           //qDebug() << "THIS WAS THE LAST ITEM, WE PROCEED TO SEE IF WE FOUND THE LIST";
                       }
                   }

               }else{
                   l = jda.load(mJsonFilePath).toMap()[mJsonDataPath].toList();
                   //qDebug() << "The found list is:" << l;
               }
           }
    }
    if (jda.hasError()) {
        bb::data::DataAccessError error = jda.error();
        qDebug() << "JSON loading error: " << error.errorType() << ": "
                << error.errorMessage();
        return;
    }
    if(l.isEmpty()){
        qDebug() << "List is empty, attempt failed, ignoring";
        return;
    }else {
        //qDebug() << "NOW WE WILL FORMAT THE LIST A BIT";
        mJsonData.clear();
        findFavorites();
        foreach(QVariant v, l){
            QVariantMap m  =v.toMap();
            m.insert("timestamp",getLocalTimeFromStation(m["timestamp"].toString()));
            m.insert("type","station");
            m.insert("isFavorite",QVariant(false));
            foreach(QVariant v, mSettings["favorites"].toList()){
                if(m["id"].toString()==v.toMap()["id"].toString()){
                    m.insert("isFavorite",QVariant(true));
                    break;
                }
            }
            mJsonData.append(m);


        }
        //qDebug() << "APPENDING THE MODIFIED FINAL LIST TO THE DATA MODEL";
        clear();
        append(mJsonData);

    }


}

QString JsonDataModel::getLocalTimeFromStation(QString time,QString mode){
    time.replace(time.indexOf('.',Qt::CaseInsensitive),5,"Z");
    QDateTime t = QDateTime::fromString(time,Qt::ISODate);
    return t.toLocalTime().toString(mode);
}
void JsonDataModel::setJsonDataPath(const QString jsonDataPath){
    mJsonDataPath = jsonDataPath;
    emit jsonDataPathChanged(jsonDataPath);
    findJson();
}

void JsonDataModel::setJsonAssetPath(const QString jsonAssetPath)
{
    if (mJsonAssetsPath.compare(jsonAssetPath) != 0) {
        // Set and emit the JSON asset path.
        mJsonAssetsPath = jsonAssetPath;
        emit jsonAssetPathChanged(jsonAssetPath);
        findJson();
    }
}


void JsonDataModel::applyFilter(QString filter){
    filter = filter.trimmed();
    QVariantMapList l = mJsonData;
    clear();
    if(filter.isEmpty()){
        append(mJsonData);
    }else{
        foreach (QVariantMap m, mJsonData)
        {
            if(m["name"].toString().contains(filter,Qt::CaseInsensitive)){
                append(m);
            }
        }
    }
}



QString JsonDataModel::jsonAssetPath()
{
    return mJsonAssetsPath;
}
QString JsonDataModel::jsonDataPath()
{
    return mJsonDataPath;
}

void JsonDataModel::updateItemIsFavoriteAtIndex(QVariantList indexPath, const bool isFavorite)
{
    QVariantMap modelItem = data(indexPath).toMap();

    // Two indexes are needed: the index of the item in the data list and
    // the index of the item in the current model.
    int itemDataIndex = mJsonData.indexOf(modelItem);

    // Update the item in the list of data.
    QVariantMap itemMap =mJsonData.at(itemDataIndex) ;
    itemMap["isFavorite"]= isFavorite;
    mJsonData.replace(itemDataIndex, itemMap);
    QVariantMap m;
    m.insert("id",itemMap["id"].toString());
    QVariantList l = mSettings["favorites"].toList();
    if(l.contains(m)){
        if(!isFavorite) l.removeAt(mSettings["favorites"].toList().indexOf(m));
    }else{
        if(isFavorite)l.append(m);
    }
    mSettings.insert("favorites",l);

    foreach(QVariant v, mSettings["favorites"].toList() ){
        qDebug() << v;
    }
    replace(itemDataIndex,itemMap);

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
    QVariantMap modelItem = data(indexPath).toMap();

    // Two indices are needed: the index of the item in the data list and
    // the index of the item in the current model.
    int itemDataIndex = mJsonData.indexOf(modelItem);
    int itemIndex = indexPath.last().toInt();

    // Remove the item from the data list and from the current data model items.
    mJsonData.removeAt(itemDataIndex);
    removeAt(itemIndex);
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

void JsonDataModel::addJsonItem(const QString itemTitle)
{
    //todo customize code
    /*
    QVariantMap itemMap;
    itemMap["title"] = QVariant(itemTitle);
    itemMap["status"] = QVariant("todo");

    if (indexOf(itemMap) == -1) {
        if (mFilter.compare("todo") == 0) {
            // New items are added to the todo list. If the filter is set to todo,
            // the current list is shown and the new item is added at the top of the list model.
            insert(0, itemMap);
        }

        // Add the new item to the data list.
        mJsonData.insert(0, itemMap);
        saveData();
    }
    */
    qDebug() << "Support for adding items still not added, we are sorry for \"" << itemTitle << "\"";


}

void JsonDataModel::editJsonItem(const QVariant item, const QString newItemTitle)
{
    // Get the indices of the item in the model and in the data list.
    QVariantMap itemMap = item.toMap();
    int itemDataIndex = mJsonData.indexOf(itemMap);
    int itemIndex = indexOf(itemMap);

    // Update the title.
    itemMap["title"] = newItemTitle;

    // And replace the item in both the model and the data list.
    mJsonData.replace(itemDataIndex, itemMap);
    replace(itemIndex, itemMap);

    saveData();
}


