#include "model.h"

Model::Model(QObject *parent): QAbstractListModel(parent)
{
    value = new QList<Region>();
}

int Model::rowCount(const QModelIndex &) const
{
    return value->count();
}

int Model::columnCount(const QModelIndex &) const
{
    return 7;
}

QVariant Model::data( const QModelIndex &index, int role ) const
{

    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                switch (index.column()) {
                    case 0: {
                        value = this->value->at(index.row()).getYear();
                        break;
                    }
                    case 1: {
                        value = this->value->at(index.row()).getRegion();
                        break;
                    }
                    case 2: {
                        value = this->value->at(index.row()).getNpg();
                        break;
                    }
                    case 3: {
                        value = this->value->at(index.row()).getbirth_rate();
                        break;
                     }
                    case 4: {
                        value = this->value->at(index.row()).getdeath_rate();
                        break;
                        }
                    case 5: {
                         value = this->value->at(index.row()).getGdw();
                         break;
                     }
                    case 6: {
                        value = this->value->at(index.row()).geturbanization();
                        break;
                       }
                }
            }
            break;

            case Qt::UserRole: //data
            {
                value = this->value->at(index.row()).getYear();
            }
            break;

            default:
                break;
        }

    return value;
}

void Model::populate(QList<Region> *newValues)
{
    int idx = value->count();
    this->beginInsertRows(QModelIndex(), 0, idx);
        this->value = newValues;
    endInsertRows();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section){
        case 0:
            return QString("Year");
        case 1:
            return QString("Region");
        case 2:
            return QString("NPG");
        case 3:
            return QString("Birth rate");
        case 4:
            return QString("Death rate");
        case 5:
            return QString("GDW");
        case 6:
            return QString("Urbanization");
        }
    }
    return QVariant();
}
