#include "JSONPlaylist.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void JSONPlayList::writeToFile() {
	ofstream fout(this->fileName);

	fout << "[\n";
	for (int i = 0; i < this->songs.size(); i++) {
		Song song = this->songs[i];

		fout << "\t{\n";
		fout << "\t\t\"artist\": \"" << song.getArtist() << "\",\n";
		fout << "\t\t\"title\": \"" << song.getTitle() << "\",\n";
		
		fout << "\t\t\"duration\":\n\t\t\t{\n";
		fout << "\t\t\t\t\"minutes\": " << song.getDuration().getMinutes() << ",\n";
		fout << "\t\t\t\t\"second\": " << song.getDuration().getSeconds() << "\n";
		fout << "\t\t\t},\n";

		fout << "\t\t\"source\": \"" << song.getSource() << "\"\n";
		
		fout << "\t}";
		if (i != this->songs.size() - 1)
			fout << ",";
		fout << "\n";
	}
	fout << "]";

	fout.close();
}

void JSONPlayList::displayPlaylist() {
	ShellExecuteA(NULL, NULL, "C:\\Users\\Administrator\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}

