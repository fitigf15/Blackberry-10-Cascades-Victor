/****************************************************************************
** Meta object code from reading C++ file 'bicing.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/bicing.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bicing.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bicing[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       7,  134, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x05,
      49,   46,    7,    7, 0x05,
      88,   84,    7,    7, 0x05,
     133,  131,    7,    7, 0x05,
     160,  158,    7,    7, 0x05,
     209,  203,    7,    7, 0x05,
     239,  233,    7,    7, 0x05,
     302,  233,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     371,    7,    7,    7, 0x08,
     389,    7,    7,    7, 0x08,
     445,    7,    7,    7, 0x08,

 // methods: signature, parameters, type, tag, flags
     479,  471,    7,    7, 0x02,
     518,  515,    7,    7, 0x02,
     542,    7,    7,    7, 0x02,
     596,  567,  554,    7, 0x02,
     668,  642,    7,    7, 0x02,
     701,    7,    7,    7, 0x02,
     718,    7,    7,    7, 0x02,
     742,    7,    7,    7, 0x02,
     766,    7,    7,    7, 0x02,
     788,    7,    7,    7, 0x02,
     816,  809,    7,    7, 0x02,
     856,  809,    7,    7, 0x02,
     932,  515,  902,    7, 0x02,

 // properties: name, type, flags
     980,  968, 0x08495103,
     995,  968, 0x08495103,
    1010,  554, 0x09495103,
    1032,  968, 0x08495103,
    1057, 1037, 0x0049510b,
    1072,  902, 0x0049510b,
    1097,  902, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       6,
       7,

       0        // eod
};

static const char qt_meta_stringdata_Bicing[] = {
    "Bicing\0\0cn\0currentNetworkChanged(QVariantMap)\0"
    "cs\0currentStationChanged(QVariantMap)\0"
    "cns\0currentNearbyStationsChanged(QVariantList)\0"
    "n\0netsChanged(QVariantMap)\0i\0"
    "staticMapImageChanged(bb::cascades::Image)\0"
    "reply\0replyCompleted(QString)\0model\0"
    "currentStationsDataModelChanged(bb::cascades::GroupDataModel*)\0"
    "currentNearbyStationsDataModelChanged(bb::cascades::GroupDataModel*)\0"
    "onReplyFinished()\0"
    "onImageFinished(bb::cascades::maps::MapImageGenerator*)\0"
    "onSystemLanguageChanged()\0lat,lon\0"
    "updateDeviceLocation(double,double)\0"
    "id\0locationTapped(QString)\0updateMap()\0"
    "QVariantList\0mapObject,latitude,longitude\0"
    "worldToPixelInvokable(QObject*,double,double)\0"
    "mapObject,containerObject\0"
    "updateMarkers(QObject*,QObject*)\0"
    "goToMyLocation()\0routeToCurrentStation()\0"
    "inspectCurrentStation()\0shareCurrentStation()\0"
    "openNearbyStations()\0filter\0"
    "filterCurrentStationsDataModel(QString)\0"
    "filterCurrentNearbyStationsDataModel(QString)\0"
    "bb::cascades::GroupDataModel*\0"
    "getNearbyStationsDataModel(QString)\0"
    "QVariantMap\0currentNetwork\0currentStation\0"
    "currentNearbyStations\0nets\0"
    "bb::cascades::Image\0staticMapImage\0"
    "currentStationsDataModel\0"
    "currentNearbyStationsDataModel\0"
};

void Bicing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Bicing *_t = static_cast<Bicing *>(_o);
        switch (_id) {
        case 0: _t->currentNetworkChanged((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: _t->currentStationChanged((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 2: _t->currentNearbyStationsChanged((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 3: _t->netsChanged((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 4: _t->staticMapImageChanged((*reinterpret_cast< bb::cascades::Image(*)>(_a[1]))); break;
        case 5: _t->replyCompleted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->currentStationsDataModelChanged((*reinterpret_cast< bb::cascades::GroupDataModel*(*)>(_a[1]))); break;
        case 7: _t->currentNearbyStationsDataModelChanged((*reinterpret_cast< bb::cascades::GroupDataModel*(*)>(_a[1]))); break;
        case 8: _t->onReplyFinished(); break;
        case 9: _t->onImageFinished((*reinterpret_cast< bb::cascades::maps::MapImageGenerator*(*)>(_a[1]))); break;
        case 10: _t->onSystemLanguageChanged(); break;
        case 11: _t->updateDeviceLocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 12: _t->locationTapped((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->updateMap(); break;
        case 14: { QVariantList _r = _t->worldToPixelInvokable((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = _r; }  break;
        case 15: _t->updateMarkers((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 16: _t->goToMyLocation(); break;
        case 17: _t->routeToCurrentStation(); break;
        case 18: _t->inspectCurrentStation(); break;
        case 19: _t->shareCurrentStation(); break;
        case 20: _t->openNearbyStations(); break;
        case 21: _t->filterCurrentStationsDataModel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->filterCurrentNearbyStationsDataModel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: { bb::cascades::GroupDataModel* _r = _t->getNearbyStationsDataModel((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bb::cascades::GroupDataModel**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Bicing::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Bicing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Bicing,
      qt_meta_data_Bicing, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bicing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bicing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bicing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bicing))
        return static_cast<void*>(const_cast< Bicing*>(this));
    return QObject::qt_metacast(_clname);
}

int Bicing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantMap*>(_v) = currentNetwork(); break;
        case 1: *reinterpret_cast< QVariantMap*>(_v) = currentStation(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = currentNearbyStations(); break;
        case 3: *reinterpret_cast< QVariantMap*>(_v) = nets(); break;
        case 4: *reinterpret_cast< bb::cascades::Image*>(_v) = staticMapImage(); break;
        case 5: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = currentStationsDataModel(); break;
        case 6: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = currentNearbyStationsDataModel(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentNetwork(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 1: setCurrentStation(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 2: setCurrentNearbyStations(*reinterpret_cast< QVariantList*>(_v)); break;
        case 3: setNets(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 4: setStaticMapImage(*reinterpret_cast< bb::cascades::Image*>(_v)); break;
        case 5: setCurrentStationsDataModel(*reinterpret_cast< bb::cascades::GroupDataModel**>(_v)); break;
        case 6: setCurrentNearbyStationsDataModel(*reinterpret_cast< bb::cascades::GroupDataModel**>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Bicing::currentNetworkChanged(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Bicing::currentStationChanged(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Bicing::currentNearbyStationsChanged(QVariantList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Bicing::netsChanged(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Bicing::staticMapImageChanged(bb::cascades::Image _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Bicing::replyCompleted(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Bicing::currentStationsDataModelChanged(bb::cascades::GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Bicing::currentNearbyStationsDataModelChanged(bb::cascades::GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
