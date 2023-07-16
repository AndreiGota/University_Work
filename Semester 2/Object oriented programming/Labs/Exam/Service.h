#pragma once
#include "Observer.h"
#include "Doctor.h"
#include "Patient.h"
#include "Repository.h"

class Service : public Subject {
private:
	vector<Doctor> doctors;
	vector<Patient> patients;
public:
	Service();
	vector<Doctor>& getAllDoctors() { return this->doctors; }
	vector<Patient>& getAllPatients() { return this->patients; }
	vector<Patient> getAllPatientsFromSpecialization(string specialization);
	void addPatient(Patient& p);
	void writePatientsToFile();
};