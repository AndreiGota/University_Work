#pragma once
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

class Offer {
public:
	int userId;
	string date;
	int sum;
	Offer(int d = -1, string x = "", int s = -1) : userId(d), date(x), sum(s) {}
	
	string toStringOffer() {
		return to_string(this->userId) + "," + this->date + "," + to_string(this->sum);
	}
};

class Item {
private:
	string name;
	string category;
	int currPrice;
	vector<Offer> offers;
public:
	Item(string name = "", string category = "", int currPrice = -1, vector<Offer> offers = {}) : name(name), category(category), currPrice(currPrice), offers(offers) {}
	string getName() { return this->name; }
	string getCategory() { return this->category; }
	int getPrice() { return this->currPrice; }
	vector<Offer> getOffers() { return this->offers; }
	string toString() {
		return this->name + "|" + this->category + "|" + to_string(this->currPrice);
	}
	string toStringFile() {
		string x = this->name + "|" + this->category + "|" + to_string(this->currPrice) + "|";
		for (auto& it : offers) {
			x += it.toStringOffer();
			x += ";";
		}
		return x;
	}
};