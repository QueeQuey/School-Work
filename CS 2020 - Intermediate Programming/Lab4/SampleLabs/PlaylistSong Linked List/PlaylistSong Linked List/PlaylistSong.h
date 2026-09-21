#ifndef PLAYLISTSONG_H
#define PLAYLISTSONG_H

#include <iostream>
using namespace std;

class PlaylistSong {
public:
	PlaylistSong(string value = "noName", PlaylistSong* nextLoc = nullptr);
	void InsertAfter(PlaylistSong* nodePtr);
	PlaylistSong* GetNext();
	void PrintNodeData();
private:
	string name;
	PlaylistSong* nextPlaylistSongPtr;
};
#endif

