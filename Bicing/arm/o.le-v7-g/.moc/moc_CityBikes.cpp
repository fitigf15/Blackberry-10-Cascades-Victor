/****************************************************************************
** Meta object code from reading C++ file 'CityBikes.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/CityBikes.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CityBikes.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CityBikes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,
      53,   35,   10,   10, 0x05,
      89,   87,   10,   10, 0x05,
     138,  132,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     162,   10,   10,   10, 0x08,
     180,   10,   10,   10, 0x08,
     236,   10,   10,   10, 0x08,

 // methods: signature, parameters, type, tag, flags
     270,  262,   10,   10, 0x02,
     313,  306,   10,   10, 0x02,

 // properties: name, type, flags
      11,  334, 0x0a495103,
      35,  334, 0x0a495103,
     362,  342, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_CityBikes[] = {
    "CityBikes\0\0url\0urlChanged(QString)\0"
    "currentLocationID\0currentLocationIDChanged(QString)\0"
    "i\0staticMapImageChanged(bb::cascades::Image)\0"
    "reply\0replyCompleted(QString)\0"
    "onReplyFinished()\0"
    "onImageFinished(bb::cascades::maps::MapImageGenerator*)\0"
    "onSystemLanguageChanged()\0lat,lon\0"
    "updateDeviceLocation(double,double)\0"
    "filter\0applyFilter(QString)\0QString\0"
    "bb::cascades::Image\0staticMapImage\0"
};

void CityBikes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CityBikes *_t = static_cast<CityBikes *>(_o);
        switch (_id) {
        case 0: _t->urlChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->currentLocationIDChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->staticMapImageChanged((*reinterpret_cast< bb::cascades::Image(*)>(_a[1]))); break;
        case 3: _t->replyCompleted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onReplyFinished(); break;
        case 5: _t->onImageFinished((*reinterpret_cast< bb::cascades::maps::MapImageGenerator*(*)>(_a[1]))); break;
        case 6: _t->onSystemLanguageChanged(); break;
        case 7: _t->updateDeviceLocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->applyFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CityBikes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CityBikes::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CityBikes,
      qt_meta_data_CityBikes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CityBikes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CityBikes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CityBikes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CityBikes))
        return static_cast<void*>(const_cast< CityBikes*>(this));
    return QObject::qt_metacast(_clname);
}

int CityBikes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = url(); break;
        case 1: *reinterpret_cast< QString*>(_v) = currentLocationID(); break;
        case 2: *reinterpret_cast< bb::cascades::Image*>(_v) = staticMapImage(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setUrl(*reinterpret_cast< QString*>(_v)); break;
        case 1: setCurrentLocationID(*reinterpret_cast< QString*>(_v)); break;
        case 2: setStaticMapImage(*reinterpret_cast< bb::cascades::Image*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CityBikes::urlChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CityBikes::currentLocationIDChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CityBikes::staticMapImageChanged(bb::cascades::Image _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CityBikes::replyCompleted(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE