#pragma once
#include "FilePlaylist.h"

class JSONPlayList : public FilePlaylist {
public:
	JSONPlayList(std::string filename = "") : FilePlaylist(filename) {}
	~JSONPlayList() {};
	void writeToFile() override;
	void displayPlaylist() override;
};