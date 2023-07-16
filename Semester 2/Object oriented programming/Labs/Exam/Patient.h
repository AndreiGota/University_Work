#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Patient {
private:
	string name;
	string diagnosis;
	string specialization;
	string current_doctor;
	string admission_date;
public:
	Patient(string name = "", string diagnosis = "", string specialization = "", string current_doctor = "", string admission_date = "") :
		name(name), diagnosis(diagnosis), specialization(specialization), current_doctor(current_doctor), admission_date(admission_date) {}
	string getName() { return this->name; }
	string getDiagnosis() { return this->diagnosis; }
	string getSpecialization() { return this->specialization; }
	string getCurrentDoctor() { return this->current_doctor; }
	string getAdmissionDate() { return this->admission_date; }
	static vector<string> tokenize(const string& answer, char delimiter);
	friend istream& operator>>(istream& is, Patient& a);
	friend ostream& operator<<(ostream& os, Patient& a);
	string toString() { return this->name + "," + this->diagnosis + "," + this->specialization + "," + this->current_doctor + "," + this->admission_date; }
};