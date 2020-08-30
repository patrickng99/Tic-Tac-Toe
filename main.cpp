//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      Patrick Karangwa
//---------------------------------------------------

#include "tic4.h"
#include "tic4.cpp"

//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
int main()
{
   // Declare variables
   Tic4 game;
   int row, col;

   // Play game
   cout << "\nWelcome to 4x4 tic-tac-toe\n";
   game.PrintBoard();
   while (!game.IsFull())
   {
      // Get X move
      cout << "Player X, enter your move (row, column): ";
      cin >> row >> col;
      while (game.SetBoard(row, col,'X') == false)
      {
         cout << "Player X, your move: ";
         cin >> row >> col;
      }
      game.PrintBoard();

      // Check if X wins
      if (game.CheckWin('X'))
      {
         cout << "X wins!\n\n";
         return 0;
      }

      while(game.FancyAI('O') == false)
      {
         game.FancyAI('O');
      }

      game.PrintBoard();

      // Check if O wins
      if (game.CheckWin('O'))
      {
         cout << "O wins!\n\n";
         return 0;
      }
   }
   cout << "Sorry, nobody wins.\n\n";
   return 0;
}