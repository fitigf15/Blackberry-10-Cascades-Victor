/****************************************************************************
** Meta object code from reading C++ file 'JsonDataModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/JsonDataModel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JsonDataModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JsonDataModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   15,   14,   14, 0x05,
      72,   59,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     126,  101,   14,   14, 0x0a,
     173,  159,   14,   14, 0x0a,
     213,  203,   14,   14, 0x0a,
     252,  234,   14,   14, 0x0a,

 // methods: signature, parameters, type, tag, flags
     290,  283,   14,   14, 0x02,

 // properties: name, type, flags
      15,  311, 0x0a495103,
      59,  311, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_JsonDataModel[] = {
    "JsonDataModel\0\0jsonAssetPath\0"
    "jsonAssetPathChanged(QString)\0"
    "jsonDataPath\0jsonDataPathChanged(QString)\0"
    "selectionList,isFavorite\0"
    "setIsFavorite(QVariantList,bool)\0"
    "selectionList\0deleteJsonItems(QVariantList)\0"
    "itemTitle\0addJsonItem(QString)\0"
    "item,newItemTitle\0editJsonItem(QVariant,QString)\0"
    "filter\0applyFilter(QString)\0QString\0"
};

void JsonDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        JsonDataModel *_t = static_cast<JsonDataModel *>(_o);
        switch (_id) {
        case 0: _t->jsonAssetPathChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->jsonDataPathChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setIsFavorite((*reinterpret_cast< const QVariantList(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 3: _t->deleteJsonItems((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 4: _t->addJsonItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->editJsonItem((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->applyFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData JsonDataModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject JsonDataModel::staticMetaObject = {
    { &JsonListDataModel::staticMetaObject, qt_meta_stringdata_JsonDataModel,
      qt_meta_data_JsonDataModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JsonDataModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JsonDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JsonDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JsonDataModel))
        return static_cast<void*>(const_cast< JsonDataModel*>(this));
    return JsonListDataModel::qt_metacast(_clname);
}

int JsonDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = JsonListDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = jsonAssetPath(); break;
        case 1: *reinterpret_cast< QString*>(_v) = jsonDataPath(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setJsonAssetPath(*reinterpret_cast< QString*>(_v)); break;
        case 1: setJsonDataPath(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void JsonDataModel::jsonAssetPathChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JsonDataModel::jsonDataPathChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
