#include "tableModel.h"

int tableModel::rowCount(const QModelIndex& parent) const
{
    return (int)this->controller.getSongs().size();
}

int tableModel::columnCount(const QModelIndex& parent) const
{
    return 5;
}

QVariant tableModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int column = index.column();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        Song& s = this->controller.getSongs().at(row);
        if (column == 0)
            return QString::fromStdString(to_string(s.getId()));
        else if (column == 1)
            return QString::fromStdString(s.getTitle());
        else if (column == 2)
            return QString::fromStdString(s.getArtist());
        else if (column == 3)
            return QString::fromStdString(to_string(s.getRank()));
        else if (column == 4)
            return QString::fromStdString(to_string(this->controller.getSameRankSong(s)));
    }
    return QVariant();
}

QVariant tableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole and orientation == Qt::Horizontal) {
        if (section == 0)
            return QString("Id");
        else if (section == 1)
            return QString("Title");
        else if (section == 2)
            return QString("Artist");
        else if (section == 3)
            return QString("Rank");
    }
    return QVariant();
}

bool tableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role != Qt::EditRole)
        return false;

    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags tableModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

Controller& tableModel::getControllerReference()
{
    return this->controller;
}

void tableModel::updateSongModel(int row, string title, int rank)
{
    /*
    if (currentRow < 0 || currentRow >= this->repository.getNumberOfIdeas())
        return;

    Idea& currentIdea = this->repository.getIdeasReferences().at(currentRow);

    if (currentIdea.getStatus() != "proposed")
        return;

    currentIdea.setStatus(std::string("accepted"));

    this->notify();

    emit dataChanged(QModelIndex{}, QModelIndex{});
    */
    if (row < 0 || row >= this->controller.getSongs().size())
        return;
    Song& s = this->controller.getSongs().at(row);
    s.setRank(rank);
    s.setTitle(title);
    this->controller.writeSongs();
    emit dataChanged(QModelIndex{}, QModelIndex{});
}
