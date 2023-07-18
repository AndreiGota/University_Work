#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Song {
private:
	string title, artist;
	int id, rank;
public:
	Song(int id = -1, string title = "", string artist = "", int rank = -1):
		id(id), title(title), artist(artist), rank(rank) {}
	int getId() { return this->id; }
	string getTitle() { return this->title; }
	string getArtist() { return this->artist; }
	int getRank() { return this->rank; }
	void setRank(int r) { this->rank = r; }
	void setTitle(string& t) { this->title = t; }
	string toString() {
		return to_string(this->id) + "|" + this->title + "|" + this->artist + "|" + to_string(this->rank);
	}
};