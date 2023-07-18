#pragma once
#include "Courier.h"
#include "Package.h"
#include "Subject.h"

class Controller: public Subject {
private:
	vector<Courier> couriers;
	vector<Package> packages;
	string courierFile = "courier.txt", packageFile = "package.txt";
public:
	Controller() {
		this->readCouriers();
		this->readPackages();
	}
	void readCouriers();
	void readPackages();
	void writePackagea();
	vector<Courier>& getCouriers() {
		return this->couriers;
	}
	vector<Package>& getPackages() {
		return this->packages;
	}
};