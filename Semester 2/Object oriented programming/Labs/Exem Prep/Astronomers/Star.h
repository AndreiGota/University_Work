#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Star {
private:
	string name, constellation;
	int ra, dec, diameter;
public:
	Star(string name = "", string constellation = "", int ra = 0, int dec = 0, int diameter = 0):
		name(name), constellation(constellation), ra(ra), dec(dec), diameter(diameter) {}
	string getName() { return this->name; }
	string getConstellation() { return this->constellation; }
	int getRA() { return this->ra; }
	int getDec() { return this->dec; }
	int getDiameter() { return this->diameter; }

	string toStringFile() {
		return this->name + "|" + this->constellation + "|" + to_string(this->ra) + "|" + to_string(this->dec) + "|" + to_string(this->diameter);
	}

	void setName(string n) {
		this->name = n;
	}

	void setConstellation(string cons) {
		this->constellation = cons;
	}

	void setDiameter(int dia) {
		this->diameter = dia;
	}
};