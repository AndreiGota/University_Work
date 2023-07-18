#pragma once
#include "Song.h"

class Controller {
private:
	vector<Song> songs;
	string songFile = "songs.txt";
public:
	Controller() {
		this->readSongs();
		this->writeSongs();
	}
	void readSongs();
	void writeSongs();
	vector<Song>& getSongs() {
		sort(songs.begin(), songs.end(), [&](Song& a, Song& b) {
			return a.getRank() < b.getRank();
			});
		return this->songs;
	}
	int getSameRankSong(Song& s);
};