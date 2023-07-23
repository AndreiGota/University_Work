
#include "SongsQT.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "CSVPlaylist.h"
#include "Gui.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	Repository repo("Songs.txt");
	unique_ptr<FilePlaylist> p = make_unique<CSVPlaylist>();
	Service serv(repo, p.get(), SongValidator{});
	Gui gui(serv);
	gui.show();

    return a.exec();
}
