#include "Controller.h"
#include <algorithm>
#include "FilePlaylist.h"
#include "RepositoryExceptions.h"

using namespace std;

void Controller::addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source)
{
	Song s{ artist, title, Duration{minutes, seconds}, source };
	this->validator.validate(s);
	this->repo.addSong(s);

	// record the action for undo
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, s));
}

void Controller::removeSongFromRepository(const std::string & artist, const std::string & title)
{
	Song s = this->repo.findByArtistAndTitle(artist, title);
	this->repo.removeSong(s);

	// record the action for undo
	this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, s));
}

void Controller::undo()
{
	if (undoActions.empty()) 
	{
		throw RepositoryException{ "There are no more actions to undo." };
	}
	
	try
	{
		//undoActions.back()->executeUndo();
		std::unique_ptr<UndoAction> last =  std::move(undoActions.back());
		last->executeUndo();
		
		undoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void Controller::addSongToPlaylist(const Song& song)
{
	if (this->playList == nullptr)
		return;
	this->playList->add(song);
}

void Controller::addAllSongsByArtistToPlaylist(const std::string& artist)
{
	vector<Song> songs = this->repo.getSongs();
	int nSongs = count_if(songs.begin(), songs.end(),
		[artist](const Song& s)
		{
			return s.getArtist() == artist;
		});

	vector<Song> songsByArtist(nSongs);
	copy_if(songs.begin(), songs.end(), songsByArtist.begin(),
		[artist](const Song& s)
		{
			return s.getArtist() == artist;
		});

	for (auto s : songsByArtist)
		this->playList->add(s);
}

void Controller::startPlaylist()
{
	if (this->playList == nullptr)
		return;
	this->playList->play();
}

void Controller::nextSongPlaylist()
{
	if (this->playList == nullptr)
		return;
	this->playList->next();
}

void Controller::savePlaylist(const std::string& filename)
{
	if (this->playList == nullptr)
		return;

	this->playList->setFilename(filename);
	this->playList->writeToFile();
}

void Controller::openPlaylist() const
{
	if (this->playList == nullptr)
		return;

	this->playList->displayPlaylist();
}
