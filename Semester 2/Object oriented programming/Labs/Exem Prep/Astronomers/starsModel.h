#pragma once
#include "Controller.h"
#include <QAbstractTableModel>

class starModel : public QAbstractTableModel {
private:
	Controller& controller;
public:
	starModel(Controller& c): controller(c) {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
	Qt::ItemFlags flags(const QModelIndex& index) const;

	Controller& getControllerReference() {
		return this->controller;
	}

	void addStarModel(Star& star);
};