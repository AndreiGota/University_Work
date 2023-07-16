#pragma once
#include "USERrepository.h"

class HTMLRepo : public UserRepository {
public:
	HTMLRepo(const vector<DogObject>& adoption_list, const string& userFilename);
	vector<DogObject>& getAllUserRepo() override;
	int getNumberElements() override;
	void addUserRepo(const DogObject& dog) override;
	void writeToFile() override;
	string& getFilename() override;
	~HTMLRepo();
};