// Program #3 – Wall Climb Program
// Programmer:  Layne Woodruff
// Class:  CS 2020 1001, Spring 2023
// Due Date: March 5, 2023
// 
// Purpose of program:  
//  The purpose of the program is to create a game that has two players randomly
//  see who can climb a wall and by how much. Whoever gets to 20 feet first wins.
// Processing:
//	The rand function randomly generates a number and the modulo checks the remainder 
//	of that number by either 2 or 3, adding 1 for the climb and drop function. Then
//	assigns the adjusted values to the current position of each player.
// Output:
//	The output is printing out the location of each of the players per round
//	then waiting that way a human can see the updates of player position.

#include "wall.h" // Including the file to use the wall class.
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>  //use to generate a randon number
#include<windows.h> //used to pause a windows display

using namespace std;
const int TOP_OF_WALL = 20;
int main()
{
	wall player1("Player 001"), player2("Player 456");
	int player1turn, player2turn;//use to decide if the player should climb or drop
	bool winner = false;		// use to terminate the loop once a player reaches 
								// the top of the wall

	unsigned seed = time(0);	//use top get a different set of ramdom numbers
	srand(seed);				// part of the random number process

	while (!winner)				//while there is not a winner the loop iterates
	{
		system("CLS");			//clears the screen (stdlib needed)

		cout << "==================== Top of the World!! =======================\n";
		player1turn = (rand() % 2);	//randomly generates a number from 0 to 1
		player2turn = (rand() % 2);	// 1 means the player will climb, 0 means player drops

		//Commented out setting both player1 and player2 to climb, that way I could check to see if the tie was working correctly.
		//player1turn = 1;
		//player2turn = 1;
		
		
		// Checks to see if player 1 will climb or drop, then calls the appropriate function. If rand
		// somehow does not return a 1 or 0, it ends the program.
		if(player1turn == 1){
			player1.climb();
		 }
		else if(player1turn == 0){
			player1.drop();
		 }
		else {
			cout << endl << "Error - climb/drop value for player1 is not 0 or 1" << endl;
			return 1;
		}

		
		
		// Does the same as the above code, just for player2.
		if (player2turn == 1) {
			player2.climb();
		}
		else if (player2turn == 0) {
			player2.drop();
		}
		else {
			cout << endl << "Error - climb/drop value for player2 is not 0 or 1" << endl;
			return 1;
		}





		//My test to make sure the a player does go below the ground.
		if (player1.getposition() < 0 || player2.getposition() < 0)
		{
			cout << "ERROR IN CODE" << endl;
			exit(1);
		}
		//animated wall with player labels
		cout << "---------------------------------------------------------------\n";
		for (int k = TOP_OF_WALL; k >= 0; k--)
		{
			if (k == 0 || k == 19)
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << setw(5) << k;
			if (player1.getposition() == k || (k == TOP_OF_WALL && player1.getposition() >= TOP_OF_WALL))
				cout << setw(15) << player1.getname();
			else
				cout << setw(15) << " ";

			if (player2.getposition() == k || (k == TOP_OF_WALL && player2.getposition() >= TOP_OF_WALL))
				cout << setw(15) << player2.getname();
			cout << endl;

		}
		cout << "---------------------------------------------------------------\n";
		Sleep(400); // pauses
		
		

		/*
		* Compares the positions of both players, and checks to see if player 1 has reached the top of the wall.
		* If player 1 has reached the top of the wall, player2 has as well and it assigns a tie.
		* Otherwise the win is assigned as it normally would be.
		* Check is done by a '>=' even though player shouldn't be able to have a level above 20, but just in case the
		* it checks to see if it's above 20 as well.
		*/
		if(player1.getposition() == player2.getposition() && player1.getposition() >= TOP_OF_WALL) {
			winner = true;
			cout << endl << "Tie! Win defaults to " << player1.getname() << endl;
		 }
		 
		 else if (player1.getposition() >= TOP_OF_WALL){
			winner = true;
			cout << endl << player1.getname() << " wins!" << endl;
		 }
		 else if(player2.getposition() >= TOP_OF_WALL){
			winner = true;
			cout << endl << player2.getname() << " wins!" << endl;
		 }


	}
	return 0;
}
//end of code