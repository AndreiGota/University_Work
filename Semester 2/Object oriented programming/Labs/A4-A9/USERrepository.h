#pragma once
#include <vector>
#include "domain.h"

class UserRepository {
protected:
	vector<DogObject> adoptionList;
	string userFilename;
public:
	//Constructor for the UserRepository class
	//param adoption_list - the list of dogs the the user is adopting
	explicit UserRepository(vector<DogObject>& adoption_list);

	UserRepository();

	//Method to get all the elements of the UserRepository
	//return - the list of elements for the UserRepository
	virtual vector<DogObject>& getAllUserRepo() = 0;

	//Method to get the number of elements from the UserRepository
	//return - the number of elements
	virtual int getNumberElements() = 0;

	//Method to add a dog to the UserRepository
	//param dog - the element to be added
	virtual void addUserRepo(const DogObject& dog) = 0;

	virtual void writeToFile() = 0;

	virtual string& getFilename() = 0;

	//Destructor
	virtual ~UserRepository();
};

class UserRepoException : public exception {
private:
	string error_message;
public:
	explicit UserRepoException(string& _error_message);

	const char* what() const noexcept override;
};