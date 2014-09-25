/****************************************************************************
** Meta object code from reading C++ file 'filteredDataModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/filteredDataModel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filteredDataModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FilteredDataModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   19,   18,   18, 0x05,
      73,   57,   18,   18, 0x05,

 // methods: signature, parameters, type, tag, flags
     105,   18,   18,   18, 0x02,

 // properties: name, type, flags
      19,  119, 0x0a495903,
      57,  119, 0x0a495903,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_FilteredDataModel[] = {
    "FilteredDataModel\0\0filterText\0"
    "filterTextChanged(QString)\0filterAttribute\0"
    "filterAttributeChanged(QString)\0"
    "clearFilter()\0QString\0"
};

void FilteredDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FilteredDataModel *_t = static_cast<FilteredDataModel *>(_o);
        switch (_id) {
        case 0: _t->filterTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->filterAttributeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->clearFilter(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FilteredDataModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FilteredDataModel::staticMetaObject = {
    { &bb::cascades::GroupDataModel::staticMetaObject, qt_meta_stringdata_FilteredDataModel,
      qt_meta_data_FilteredDataModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FilteredDataModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FilteredDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FilteredDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilteredDataModel))
        return static_cast<void*>(const_cast< FilteredDataModel*>(this));
    typedef bb::cascades::GroupDataModel QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int FilteredDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef bb::cascades::GroupDataModel QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = filterText(); break;
        case 1: *reinterpret_cast< QString*>(_v) = filterAttribute(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFilterText(*reinterpret_cast< QString*>(_v)); break;
        case 1: setFilterAttribute(*reinterpret_cast< QString*>(_v)); break;
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
void FilteredDataModel::filterTextChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilteredDataModel::filterAttributeChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
