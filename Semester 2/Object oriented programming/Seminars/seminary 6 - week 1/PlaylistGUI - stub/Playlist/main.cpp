#include "UI.h"
#include <Windows.h>
#include "CSVPlayList.h"
#include "RepositoryExceptions.h"

using namespace std;

int main()
{
	system("color f4");

	Repository repo("Songs.txt");
	FilePlaylist* p = new CSVPlaylist{};
	Service serv(repo, p, SongValidator{});
	UI ui(serv);
	ui.run();
	delete p;
	
	return 0;
}