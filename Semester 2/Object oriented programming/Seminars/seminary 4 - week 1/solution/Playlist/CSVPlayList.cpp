#include "CSVPlayList.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"
using namespace std;

void CSVPlayList::writeToFile()
{
	ofstream fout(this->fileName.c_str());
	if (!fout.is_open())
		throw FileException("File was not opened");
	for (auto song : songs)
		fout << song;
	fout.close();
}

void CSVPlayList::displayPlaylist()
{
	ShellExecuteA(NULL, NULL, "c:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}