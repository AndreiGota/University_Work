#pragma once
#include "ADMINrepository.h"
#include "USERrepository.h"

class UserService {
private:
	AdministratorRepository& admin_repo;
	UserRepository* user_repo;
	bool repoTypeSelected;
public:
	//Constructor for the UserService class
	//param _admin_repo - the admin repository
	//param _user_repo - the user repository
	UserService(AdministratorRepository& _admin_repo, UserRepository* _user_repo);

	explicit UserService(AdministratorRepository& _admin_repo);

	//Method to get all elements from the user repository
	//return - the elements from the user repository
	vector<DogObject> getAllUserService();

	//Method to get the number of elements from the user repository
	//return - number of elements from the user repo
	int getNumberElementsService();

	//Method add the new dog to the user repo
	//param dog - the dog to be added
	void addUserService(const DogObject& dog);

	void repositoryType(const string& fileType);

	string& getFileUserService();

	//Destructor
	~UserService();
};