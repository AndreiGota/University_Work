#pragma once
#include "domain.h"
#include <vector>

class AdministratorRepository {
private:
	vector<DogObject> admin_repo_dog_list;
	string dogsFilename;
public:
	void loadDogsFromFile();

	void writeDogsToFile();

	//Constructor for the Administrator Repository class
	explicit AdministratorRepository(vector<DogObject>& repo_array, string& dogs_filename);

	//Method to initialise the repository with a number of entities
	void initialiseAdminRepo();

	//Method to get all the elements from the admin repo
	//return - the array of elements
	vector<DogObject>& getAllAdminRepo();

	//Method to get the number of elements in the admin repo
	//return - the number of elements
	int getNumberElements();

	//Method to add an element
	//param dog - the entity to be added
	void addAdminRepo(const DogObject& dog);

	//Method to delete an element
	//param delete_index - the index of the dog to be deleted
	void deleteAdminRepo(int delete_index);

	//Method to update an entity
	//param update_index - the index of the dog to be updated
	//param new_dog - the new dog with which the update is done
	void updateAdminRepo(int update_index, const DogObject& new_dog);

	//Method to find an entity by name and breed
	// param name - the name of the dog we are looking for
	int findByName(const string& name);

	//Destructor
	~AdministratorRepository();
};

class AdminRepoException : public exception {
private:
	string error_message;
public:
	explicit AdminRepoException(string _error_message);
	const char* what() const noexcept override;
};