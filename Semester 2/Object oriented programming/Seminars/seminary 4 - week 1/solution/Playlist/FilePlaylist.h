#pragma once
#include "PlayList.h"

class FilePlaylist : public PlayList
{
protected:
	std::string fileName;
public:
	FilePlaylist(std::string fileName = "")
	{
		this->fileName = fileName;
	}
	virtual ~FilePlaylist()
	{

	}
	virtual void writeToFile() = 0;
	virtual void displayPlaylist() = 0;
};