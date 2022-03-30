#include "myModel.h"

MyModel::MyModel(QObject *parent):QAbstractTableModel(parent)
{
    River* r3 = new River("3","Волга","Каспийское море", "3530", "254", "1360", this);
    River* r1 = new River("1", "Сена", "Ла-Манш", "776", "34", "78.65", this);
    River* r2 = new River("2", "Турнеэльвен", "Ботанический залив", "565", "27", "40.2", this);
    River* r4 = new River("4", "Дунай", "Черное море", "2850", "210", "817", this);
    AddRiver(r1);
    AddRiver(r2);
    AddRiver(r3);
    AddRiver(r4);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return rivers.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 6;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        River* r = rivers.at(index.row());
        if (index.column() == 0){Value = r->ID();}
        else if (index.column() == 1){Value = r->Name();}
        else if (index.column() == 2){Value = r->Flow();}
        else if (index.column() == 3){Value = r->Lenght();}
        else if (index.column() == 4){Value = r->Runoff();}
        else if (index.column() == 5){Value = r->Area();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Куда впадает?");
            case 3:
                return QString("Протяженность");
            case 4:
                return QString("Годовой сток");
            case 5:
                return QString("Площадь бассейна");
            }
        }
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        River* r = rivers.at(index.row());
        if (index.column() == 0){r->SetID(value.toString());}
        else if (index.column() == 1){r->SetName(value.toString());}
        else if (index.column() == 2){r->SetFlow(value.toString());}
        else if (index.column() == 3){r->SetLenght(value.toString());}
        else if (index.column() == 4){r->SetRunoff(value.toString());}
        else if (index.column() == 5){r->SetArea(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void MyModel::AddRiver(River* river)
{
    beginInsertRows(QModelIndex(),rivers.size(),rivers.size());
    rivers.append(river);
    endInsertRows();
}

void MyModel::DeleteRiver(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    rivers.removeAt(row);
    endRemoveRows();
}

void MyModel::Sort()
{
    for(int i=0; i<rivers.size()-1; i++)
        for(int j = rivers.size()-1; j>i; j--)
            if(rivers[j]->Name()<rivers[j-1]->Name())
            {
                River* c = rivers[j];
                rivers[j] = rivers[j-1];
                rivers[j-1] = c;
            }
}
