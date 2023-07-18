#pragma once
#include "Controller.h"
#include <QAbstractTableModel>

class tableModel: public QAbstractTableModel {
private:
	Controller& controller;
public:
	tableModel(Controller& c): controller(c) {}
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;

    Controller& getControllerReference();
    void updateSongModel(int row, string title, int rank);
};