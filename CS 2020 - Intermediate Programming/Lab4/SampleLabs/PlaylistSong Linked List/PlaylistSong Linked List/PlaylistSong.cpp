#include <iostream>
using namespace std;

#include "PlaylistSong.h"


PlaylistSong::PlaylistSong(string name, PlaylistSong* nextLoc) {
	this->name = name;
	this->nextPlaylistSongPtr = nextLoc;
}
void PlaylistSong::InsertAfter(PlaylistSong* nodeLoc) {
	PlaylistSong* tmpNext = nullptr;

	tmpNext = this->nextPlaylistSongPtr;
	this->nextPlaylistSongPtr = nodeLoc;
	nodeLoc->nextPlaylistSongPtr = tmpNext;
}

PlaylistSong* PlaylistSong::GetNext() {
	return this->nextPlaylistSongPtr;
}

void PlaylistSong::PrintNodeData() {
	cout << this->name << endl;
}