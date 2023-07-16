#include "Service.h"
#include <algorithm>
#include <cassert>

Service::Service()
{
	Repo repo;
	doctors = repo.readDoctor();
	assert(doctors.size() == 3);
	//patients = repo.readPatient();
	/*assert(patients.size() == 6);
	sort(patients.begin(), patients.end(), [](Patient a, Patient b) {
		return a.getAdmissionDate() < a.getAdmissionDate();
		});*/
}

vector<Patient> Service::getAllPatientsFromSpecialization(string specialization)
{
	return vector<Patient>();
}

void Service::addPatient(Patient& p)
{
	this->patients.push_back(p);
	this->notify();
	this->writePatientsToFile();
}

void Service::writePatientsToFile()
{
	string filename = R"(C:\Users\Andrei\source\repos\OOPExam\OOPExam\Patients.txt)";
	ofstream fout(filename);
	for (int i = 0; i < patients.size(); i++)
		fout << patients[i];
	fout.close();
}
