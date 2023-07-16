#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Doctor {
private:
	string name;
	string specialization;
public:
	Doctor(string name = "", string specialization = ""): name(name), specialization(specialization) {}
	string getName() { return this->name; }
	string getSpecialization() { return this->specialization; }
	static vector<string> tokenize(const string& answer, char delimiter);
	friend istream& operator>>(istream& is, Doctor& a);
	friend ostream& operator<<(ostream& os, Doctor& a);
};