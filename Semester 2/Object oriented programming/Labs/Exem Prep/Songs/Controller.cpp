#include "Controller.h"
#include <fstream>
#include <sstream>

void Controller::readSongs()
{
	/*
	ifstream fin(this->docFile);
    string line;
    while (getline(fin, line)) {
        string token;
        vector<string> data;
        stringstream ss(line);
        while (getline(ss, token, '|'))
            data.push_back(token);
        Doctor d(data[0], data[1]);
        doctors.push_back(d);
    }
    fin.close();
	*/
    ifstream fin(this->songFile);
    string line;
    while (getline(fin, line)) {
        string token;
        vector<string> data;
        stringstream ss(line);
        while (getline(ss, token, '|'))
            data.push_back(token);
        Song s(stoi(data[0]), data[1], data[2], stoi(data[3]));
        songs.push_back(s);
    }
}

void Controller::writeSongs()
{
    ofstream fout(this->songFile);
    for (auto& it : this->songs)
        fout << it.toString() << "\n";
}

int Controller::getSameRankSong(Song& s)
{
    int nr = 0;
    for (auto& it : this->songs)
        if (it.getRank() == s.getRank() && it.getTitle() != s.getTitle())
            nr++;
    return nr;
}
