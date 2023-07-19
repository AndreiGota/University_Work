#pragma once
#include "FilePlaylist.h"

class CSVPlayList : public FilePlaylist
{
public:
	CSVPlayList(std::string fileName = "") : FilePlaylist(fileName){}
	~CSVPlayList(){}
	void writeToFile() override;
	void displayPlaylist() override;
};