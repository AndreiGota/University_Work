#include "starsModel.h"

int starModel::rowCount(const QModelIndex& parent) const
{
    return (int)this->controller.getStars().size();
}

int starModel::columnCount(const QModelIndex& parent) const
{
    return 5;
}

QVariant starModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int column = index.column();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        Star& s = this->controller.getStars().at(row);
        if (column == 0)
            return QString::fromStdString(s.getName());
        else if (column == 1)
            return QString::fromStdString(s.getConstellation());
        else if (column == 2)
            return QString::fromStdString(to_string(s.getRA()));
        else if (column == 3)
            return QString::fromStdString(to_string(s.getDec()));
        else if (column == 4)
            return QString::fromStdString(to_string(s.getDiameter()));
    }
    return QVariant();
}

QVariant starModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole and orientation == Qt::Horizontal) {
        if (section == 0)
            return QString("Name");
        else if (section == 1)
            return QString("Constellation");
        else if (section == 2)
            return QString("RA");
        else if (section == 3)
            return QString("Dec");
        else if (section == 4)
            return QString("Diameter");
    }
    return QVariant();
}

bool starModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    /*ASTA E DACA NU EDITEZI DIRECT IN TABEL
    if (role != Qt::EditRole)
        return false;

    emit dataChanged(index, index);
    return true;*/
    //ASTA E PENTRU EDITAT IN TABEL
    if (role != Qt::EditRole)
        return false;
    int col = index.column();
    int row = index.row();

    Star& starX = controller.getStars()[row];
    if (col == 0) {
        string newName = value.toString().toStdString();
        starX.setName(newName);
        controller.writeStars();
    }
    else if (col == 1) {
        string newConstellation = value.toString().toStdString();
        starX.setConstellation(newConstellation);
        controller.writeStars();
    }
    else if (col == 2) {
        
    }
    else if (col == 3) {
        
    }
    else if (col == 4) {
        int newDiameter = value.toString().toInt();
        starX.setDiameter(newDiameter);
        controller.writeStars();
    }
    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags starModel::flags(const QModelIndex& index) const
{
    int col = index.column();
    if (col == 2 || col == 3) {
        return Qt::ItemFlags();
    }
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

void starModel::addStarModel(Star& star)
{
    /*int nr = (int)this->controller.getProducts().size();
    this->controller.addProductController(p);
    this->beginInsertRows(QModelIndex{}, nr, nr);
    this->endInsertRows();
    this->controller.writeProducts();
    emit dataChanged(QModelIndex{}, QModelIndex{});*/
    int nr = (int)this->controller.getStars().size();
    controller.addStar(star);
    this->beginInsertRows(QModelIndex{}, nr, nr);
    this->endInsertRows();
    this->controller.writeStars();
    emit dataChanged(QModelIndex{}, QModelIndex{});
}
