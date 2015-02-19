/****************************************************************************
** Meta object code from reading C++ file 'bicing.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/bicing.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bicing.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bicing[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       8,  129, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x05,
      49,   46,    7,    7, 0x05,
      88,   84,    7,    7, 0x05,
     131,   84,    7,    7, 0x05,
     177,  175,    7,    7, 0x05,
     204,  202,    7,    7, 0x05,
     253,  247,    7,    7, 0x05,
     283,  277,    7,    7, 0x05,
     346,  277,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     415,    7,    7,    7, 0x08,
     433,    7,    7,    7, 0x08,
     489,    7,    7,    7, 0x08,

 // methods: signature, parameters, type, tag, flags
     523,  515,    7,    7, 0x02,
     562,  559,    7,    7, 0x02,
     586,    7,    7,    7, 0x02,
     640,  611,  598,    7, 0x02,
     712,  686,    7,    7, 0x02,
     745,    7,    7,    7, 0x02,
     762,    7,    7,    7, 0x02,
     786,    7,    7,    7, 0x02,
     817,  810,    7,    7, 0x02,
     857,  810,    7,    7, 0x02,
     933,  559,  903,    7, 0x02,

 // properties: name, type, flags
     981,  969, 0x08495103,
     996,  969, 0x08495103,
    1011,  598, 0x09495103,
    1033,  598, 0x09495103,
    1056,  969, 0x08495103,
    1081, 1061, 0x0049510b,
    1096,  903, 0x0049510b,
    1121,  903, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       7,
       8,

       0        // eod
};

static const char qt_meta_stringdata_Bicing[] = {
    "Bicing\0\0cn\0currentNetworkChanged(QVariantMap)\0"
    "cs\0currentStationChanged(QVariantMap)\0"
    "cns\0currentNearbyStationsChanged(QVariantList)\0"
    "currentNetworkStationsChanged(QVariantList)\0"
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
    "inspectCurrentStation()\0filter\0"
    "filterCurrentStationsDataModel(QString)\0"
    "filterCurrentNearbyStationsDataModel(QString)\0"
    "bb::cascades::GroupDataModel*\0"
    "getNearbyStationsDataModel(QString)\0"
    "QVariantMap\0currentNetwork\0currentStation\0"
    "currentNearbyStations\0currentNetworkStations\0"
    "nets\0bb::cascades::Image\0staticMapImage\0"
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
        case 3: _t->currentNetworkStationsChanged((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 4: _t->netsChanged((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 5: _t->staticMapImageChanged((*reinterpret_cast< bb::cascades::Image(*)>(_a[1]))); break;
        case 6: _t->replyCompleted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->currentStationsDataModelChanged((*reinterpret_cast< bb::cascades::GroupDataModel*(*)>(_a[1]))); break;
        case 8: _t->currentNearbyStationsDataModelChanged((*reinterpret_cast< bb::cascades::GroupDataModel*(*)>(_a[1]))); break;
        case 9: _t->onReplyFinished(); break;
        case 10: _t->onImageFinished((*reinterpret_cast< bb::cascades::maps::MapImageGenerator*(*)>(_a[1]))); break;
        case 11: _t->onSystemLanguageChanged(); break;
        case 12: _t->updateDeviceLocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 13: _t->locationTapped((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->updateMap(); break;
        case 15: { QVariantList _r = _t->worldToPixelInvokable((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = _r; }  break;
        case 16: _t->updateMarkers((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 17: _t->goToMyLocation(); break;
        case 18: _t->routeToCurrentStation(); break;
        case 19: _t->inspectCurrentStation(); break;
        case 20: _t->filterCurrentStationsDataModel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->filterCurrentNearbyStationsDataModel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: { bb::cascades::GroupDataModel* _r = _t->getNearbyStationsDataModel((*reinterpret_cast< QString(*)>(_a[1])));
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantMap*>(_v) = currentNetwork(); break;
        case 1: *reinterpret_cast< QVariantMap*>(_v) = currentStation(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = currentNearbyStations(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = currentNetworkStations(); break;
        case 4: *reinterpret_cast< QVariantMap*>(_v) = nets(); break;
        case 5: *reinterpret_cast< bb::cascades::Image*>(_v) = staticMapImage(); break;
        case 6: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = currentStationsDataModel(); break;
        case 7: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = currentNearbyStationsDataModel(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentNetwork(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 1: setCurrentStation(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 2: setCurrentNearbyStations(*reinterpret_cast< QVariantList*>(_v)); break;
        case 3: setCurrentNetworkStations(*reinterpret_cast< QVariantList*>(_v)); break;
        case 4: setNets(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 5: setStaticMapImage(*reinterpret_cast< bb::cascades::Image*>(_v)); break;
        case 6: setCurrentStationsDataModel(*reinterpret_cast< bb::cascades::GroupDataModel**>(_v)); break;
        case 7: setCurrentNearbyStationsDataModel(*reinterpret_cast< bb::cascades::GroupDataModel**>(_v)); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
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
void Bicing::currentNetworkStationsChanged(QVariantList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Bicing::netsChanged(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Bicing::staticMapImageChanged(bb::cascades::Image _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Bicing::replyCompleted(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Bicing::currentStationsDataModelChanged(bb::cascades::GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Bicing::currentNearbyStationsDataModelChanged(bb::cascades::GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
