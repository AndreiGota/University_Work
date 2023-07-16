#pragma once
#include "Patient.h"
#include "Doctor.h"

class Repo {
private:
	//vector<Patient> patients;
	vector<Doctor> doctors;
public:
	Repo() = default;
	//vector<Patient> readPatient();
	vector<Doctor> readDoctor();
};