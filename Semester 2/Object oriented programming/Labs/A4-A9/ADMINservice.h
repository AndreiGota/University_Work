#pragma once
#include "ADMINrepository.h"

class AdministratorService {
private:
	AdministratorRepository& repository;
public:
	//Constructor for the AdministratorService class
	//param repo - the admin repository
	explicit AdministratorService(AdministratorRepository& repo);

	//Method to get all the elements of the admin repo
	//return - the elements from the admin repo
	vector<DogObject> getAllAdminService();

	//Method to get the number of elements from the admin repo
	//return - the number of elements from the admin repo
	int getNumberElementsService();

	//Method to add an element to the admin repo
	void addAdminService(const string& breed, const string& name, int age, const string& photo);

	//Method to delete an element from the admin repo
	void deleteAdminService(const string& name, const string& breed);

	//Method to update an element from the repository
	void updateAdminService(const string& old_name, const string& old_breed, const string& new_breed, const string& new_name, int new_age, const string& new_photo);

	//Method to filter the dogs by breed and age
	void getFiltered(vector<DogObject>& valid_dogs, const string& breed_filter, int age_filter);

	int findByNameService(const string& name);

	vector<string> getAllBreeds();

	int numberOfDogsPerBreed(const string& breed);

	//Destructor
	~AdministratorService();
};