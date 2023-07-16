#include "Repository.h"

//vector<Patient> Repo::readPatient()
//{
//	string filename = R"(C:\Users\Andrei\source\repos\OOPExam\OOPExam\Patients.txt)";
//	ifstream fin(filename);
//	Patient patient;
//	while (fin >> patient)
//		patients.push_back(patient);
//	fin.close();
//	return patients;
//}

vector<Doctor> Repo::readDoctor()
{
	string filename = R"("C:\Users\Andrei\source\repos\OOPExam\OOPExam\Doctors.txt")";
	ifstream fin(filename);
	if (!fin)
	{
		// File could not be opened
		// Handle the error (e.g., display an error message)
		// and possibly return an empty vector or throw an exception.
	}

	Doctor doctor;
	while (fin >> doctor)
		doctors.push_back(doctor);

	fin.close();
	return doctors;
}

