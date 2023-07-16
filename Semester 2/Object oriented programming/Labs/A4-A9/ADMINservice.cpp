#include "ADMINservice.h"
#include <iterator>
#include <algorithm>

AdministratorService::AdministratorService(AdministratorRepository& repo) : repository(repo)
{

}

vector<DogObject> AdministratorService::getAllAdminService()
{
	return this->repository.getAllAdminRepo();
}

int AdministratorService::getNumberElementsService()
{
	return this->repository.getNumberElements();
}

void AdministratorService::addAdminService(const string& breed, const string& name, int age, const string& photo)
{
	DogObject dog{ breed, name, age, photo };
	this->repository.addAdminRepo(dog);
}

void AdministratorService::deleteAdminService(const string& name, const string& breed)
{
	int delete_index = this->repository.findByName(name);
	this->repository.deleteAdminRepo(delete_index);
}

void AdministratorService::updateAdminService(const string& old_name, const string& old_breed, const string& new_breed, const string& new_name, int new_age, const string& new_photo)
{
	int update_index = this->repository.findByName(old_name);
	DogObject new_dog{ new_breed, new_name, new_age, new_photo };
	this->repository.updateAdminRepo(update_index, new_dog);
}

void AdministratorService::getFiltered(vector<DogObject>& valid_dogs, const string& breed_filter, int age_filter)
{
	vector<DogObject> dogsFromDatabase;
	dogsFromDatabase = this->repository.getAllAdminRepo();
	if (breed_filter[0] == '\0') {
		copy_if(dogsFromDatabase.begin(), dogsFromDatabase.end(), back_inserter(valid_dogs), [&age_filter](DogObject& dog) { return dog.getAge() < age_filter; });
	}
	else {
		copy_if(dogsFromDatabase.begin(), dogsFromDatabase.end(), back_inserter(valid_dogs), [&age_filter, &breed_filter](DogObject& dog) { return dog.getAge() < age_filter && dog.getBreed() == breed_filter; });
	}

}

int AdministratorService::findByNameService(const string& name)
{
	return this->repository.findByName(name);
}

vector<string> AdministratorService::getAllBreeds()
{
	vector<string> breeds;
	vector<DogObject> dogsFromDatabase;
	dogsFromDatabase = this->repository.getAllAdminRepo();
	for (const DogObject& dog : dogsFromDatabase) {
		if (find(breeds.begin(), breeds.end(), dog.getBreed()) == breeds.end())
			breeds.push_back(dog.getBreed());
	}
	return breeds;
}

int AdministratorService::numberOfDogsPerBreed(const string& breed)
{
	int count = 0;
	vector<DogObject> dogsFromDatabase;
	dogsFromDatabase = this->repository.getAllAdminRepo();
	for (const DogObject& dog : dogsFromDatabase) {
		if (dog.getBreed() == breed)
			count++;
	}
	return count;
}

AdministratorService::~AdministratorService() = default;


