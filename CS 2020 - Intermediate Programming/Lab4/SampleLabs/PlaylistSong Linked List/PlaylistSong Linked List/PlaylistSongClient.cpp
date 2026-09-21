#include <iostream>
using namespace std;

#include "PlaylistSong.h"

int main() {
	PlaylistSong* headObj = nullptr;
	PlaylistSong* firstSong = nullptr;
	PlaylistSong* secondSong = nullptr;
	PlaylistSong* thirdSong = nullptr;
	PlaylistSong* currObj = nullptr;

	headObj = new PlaylistSong("head");

	firstSong = new PlaylistSong("Egmont");
	headObj->InsertAfter(firstSong);

	secondSong = new PlaylistSong("Cavatina");
	firstSong->InsertAfter(secondSong);

	thirdSong = new PlaylistSong("Adagio");
	secondSong->InsertAfter(thirdSong);

	currObj = headObj;

	while (currObj != nullptr) {
		currObj->PrintNodeData();
		currObj = currObj->GetNext();
	}
	return 0;
}