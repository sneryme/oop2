#ifndef MODEL_H
#define MODEL_H
#include <QModelIndex>
#include "region.h"



class Model : public QAbstractListModel
{
public:
    Model(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &perent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<Region> *newValues);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<Region> *value;
};

#endif // MODEL_H
