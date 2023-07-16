#pragma once
#include "Person.h"
#include "Event.h"
#include "Subject.h"

class Controller: public Subject {
private:
	vector<Person> persons;
	vector<Event> events;
	string personFile = "person.txt", eventFile = "event.txt";
public:
	Controller() {
		this->readPerson();
		this->readEvent();
	}
	void readPerson();
	void readEvent();
	void writeEvent();
	vector<Person>& getPersons();
	vector<Event>& getEvents();
	void addEvent(Event& event) {
		this->events.push_back(event);
	}
};