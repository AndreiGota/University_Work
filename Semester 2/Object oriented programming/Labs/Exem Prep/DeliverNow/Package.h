#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Location {
private:
	int coordX, coordY;
public:
	Location(int coordX = 0, int coordY = 0):
		coordX(coordX), coordY(coordY) {}
	int getCoordX() { return this->coordX; }
	int getCoordY() { return this->coordY; }
	string toStringLoc() {
		return to_string(this->coordX) + ";" + to_string(this->coordY);
	}
};

class Address {
private:
	int nr;
	string street;
public:
	Address(string _street = "", int _nr = 0) :
		street(_street), nr(_nr) {}
	string getStreet() { return this->street; }
	int getNumberStreet() { return this->nr; }
	string toStringStreet() {
		return this->street + "," + to_string(this->nr);
	}
};

class Package {
private:
	string recipient;
	Address address;
	Location location;
	bool deliveryStatus;
public:
	Package(string _recipient = "", Address _address = Address(), Location _loc = Location(), bool _deliveryStatus = false) :
		recipient(_recipient) , address(_address), location(_loc), deliveryStatus(_deliveryStatus) {}
	string getRecipient() { return this->recipient; }
	Address getAddres() { return this->address; }
	Location getLocation() { return this->location; }
	bool getDeliveryStatus() { return this->deliveryStatus; }
	string toStringFile() {
		string x = "";
		x += recipient + "|";
		x += address.toStringStreet() + "|";
		x += location.toStringLoc() + "|";
		if (deliveryStatus == false)
			x += "false";
		else
			x += "true";//prints 0 or 1
		return x;
	}

	void setStatus() {
		this->deliveryStatus = true;
	}
};