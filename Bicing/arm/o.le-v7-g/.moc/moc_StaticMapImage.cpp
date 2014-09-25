/****************************************************************************
** Meta object code from reading C++ file 'StaticMapImage.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/StaticMapImage.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StaticMapImage.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StaticMapImage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   53,   15,   15, 0x08,
     153,   15,  128,   15, 0x0a,
     166,   16,   15,   15, 0x0a,

 // methods: signature, parameters, type, tag, flags
     233,  206,   15,   15, 0x02,

 // properties: name, type, flags
     264,  128, 0x0049510b,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_StaticMapImage[] = {
    "StaticMapImage\0\0aPropertyMap\0"
    "getProperties(QObject*)\0aMapImageGenerator\0"
    "onImageFinished(bb::cascades::maps::MapImageGenerator*)\0"
    "QDeclarativePropertyMap*\0properties()\0"
    "setProperties(QDeclarativePropertyMap*)\0"
    "aLatitude,aLongitude,width\0"
    "getImageMap(double,double,int)\0"
    "properties\0"
};

void StaticMapImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StaticMapImage *_t = static_cast<StaticMapImage *>(_o);
        switch (_id) {
        case 0: _t->getProperties((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->onImageFinished((*reinterpret_cast< bb::cascades::maps::MapImageGenerator*(*)>(_a[1]))); break;
        case 2: { QDeclarativePropertyMap* _r = _t->properties();
            if (_a[0]) *reinterpret_cast< QDeclarativePropertyMap**>(_a[0]) = _r; }  break;
        case 3: _t->setProperties((*reinterpret_cast< QDeclarativePropertyMap*(*)>(_a[1]))); break;
        case 4: _t->getImageMap((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StaticMapImage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StaticMapImage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StaticMapImage,
      qt_meta_data_StaticMapImage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StaticMapImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StaticMapImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StaticMapImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StaticMapImage))
        return static_cast<void*>(const_cast< StaticMapImage*>(this));
    return QObject::qt_metacast(_clname);
}

int StaticMapImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativePropertyMap**>(_v) = properties(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setProperties(*reinterpret_cast< QDeclarativePropertyMap**>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void StaticMapImage::getProperties(QObject * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
