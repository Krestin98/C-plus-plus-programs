/*Author: Krestin Ebraheem
Purpose: This program creates a two player tic tac toe game. */

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <numeric>
#include <vector>
#include <array>

using namespace std;
const int SIZE = 3;

// function to initialize the array

  void grid1(array < array<char, SIZE>, SIZE> &g)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			g[i][j] = ' ';
		}
	}
}
  //function to print the grid, (with spaces) and put the X or O inside

   void print(array < array<char, SIZE>, SIZE> g)
{
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "+---+---+---+" << endl;

		for (int j = 0; j < SIZE; ++j)
		{
			if (g[i][j] == 'x')
				cout << "| x ";
			else if (g[i][j] == 'o')
				cout << "| o ";
			else
			    cout << "|" << "   ";
		}
		   cout << "|" << endl;

	}
	    cout << "+---+---+---+" << endl;
}

   //Function to check if all columns and rows have three x's or three o's, as well as three diagonals
  
    bool winner(array<array<char, SIZE>, SIZE> a1, char&player)
   {
	   for (int row = 0; row < SIZE; ++row)
	   {

		   for (int column = 0; column < SIZE; ++column)
		   {
			   //row checking

			   if (a1[0][0] == player && a1[0][1] == player && a1[0][2] == player ||
				   a1[1][0] == player && a1[1][1] == player && a1[1][2] == player ||
				   a1[2][0] == player && a1[2][1] == player && a1[2][2] == player)

				   return true;

			   //diagonal checking

			   else if (a1[0][0] == player && a1[1][1] == player && a1[2][2] == player ||
				   a1[2][0] == player && a1[1][1] == player && a1[0][2] == player)
				   
				   return true;
				  
			   //column checking

			   else if (a1[0][0] == player && a1[1][0] == player && a1[2][0] == player ||
				   a1[0][1] == player && a1[1][1] == player && a1[2][1] == player ||
				   a1[0][2] == player && a1[1][2] == player && a1[2][2] == player)
				   //cout << player << " " << "wins";
				   return true;
		   }
		      
		   return false;

				
		}
  }
	//function to check for a tie in the game

	bool tie(array<array<char, SIZE>, SIZE> a1)
	{
		for (int row = 0; row < SIZE; ++row)
		{

			for (int column = 0; column < SIZE; ++column)
			{


				if (a1[row][column] != 'x' && a1[row][column] != 'o')
					return false;

			}
		}
		return true;
	}

int main()
{
	int row;
	int column;
	
	array<array<char, SIZE>, SIZE> g; //declaring the 2-dimensional array

	cout << "Welcome to Tic Tac Toe" << endl << endl;
	
	//initializing the array and printing the grid
	  
	grid1(g);
	
	print(g);
		
	char player = 'x';
	
	 while (true)
	{
		 //start game

		cout << player << "'s turn " << endl
			<< "Pick a row (1, 2, 3):" << endl;
		cin >> row; 

		cout << "Pick a column (1, 2, 3):" << endl;
		cin >> column;
		
		//row -1 and column-1 to adjust the columns to start at 1 not 0 for instance
		
		//checking condition to make sure the user doesn't use a location  twice

		     if (g[row - 1][column - 1] == 'x' || g[row - 1][column - 1] == 'o')
			{
				 cout << "Invalid move\n";
				 print(g);
				 continue;
			}
		//assigning user input to be added to the array and grid

		g[row-1][column-1] = player;
		print(g);
		
		//calling function and displaying winner
		if (winner(g, player))
		{
			cout << endl;
			cout << player << " " << "wins\n\n";
			break;
		}
		//calling function and displaying a tie
		if (tie(g))
		{
			cout << "its a tie\n";
			break;
		}

		//Switching turns between x and o
		if (player == 'x')
			player = 'o';
		else
			player = 'x';
		
	}
	    //end game
	    cout << "Game over! " << endl << endl;

	   
	return 0;
}

