#pragma once
#include "Observer.h"
#include "vector"
using namespace std;

class Subject
{
private:
	vector<Observer*> observers;
public:
	void addObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void notify() {
		for (auto& observer : observers) {
			observer->update();
		}
	}
	void removeObserver(Observer* o) {
		auto it = std::find(this->observers.begin(), this->observers.end(), o);

		if (it != this->observers.end())
			this->observers.erase(it);
	}
};
