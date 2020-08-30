//---------------------------------------------------
// Purpose:     Implementation of the Tic4 class
//
// Author:      Patrick Karangwa 
//---------------------------------------------------

#include "tic4.h"

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Tic4::Tic4()
{
   ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Tic4::~Tic4()
{
   // Intentionally empty
}

//---------------------------------------------------
// Clear the Tic4 board
//---------------------------------------------------
void Tic4::ClearBoard()
{
   // Initialize Tic4 board
   for (int c = 0; c < SIZE; c++)
   for (int r = 0; r < SIZE; r++)
      board[r][c] = ' ';
   board_count = 0;
}

//---------------------------------------------------
// Set value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::SetBoard(const int row, const int col, const char player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE) ||
       (board[row][col] != ' '))
      return false;

   // Set value of board
   board[row][col] = player;
   board_count++;
   return true;
}

//---------------------------------------------------
// Get value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::GetBoard(const int row, const int col, char & player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE))
      return false;

   // Get value of board
   player = board[row][col];
   return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Tic4::CheckWin(const char player)
{
   // Check all the rows
   for (int r = 0; r < SIZE; r++)
   {
      // Count player pieces
      int count = 0;
      for (int c = 0; c < SIZE; c++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         return true;
   }

   // Check all the cols
   for (int c = 0; c < SIZE; c++)
   {
      // Count player pieces
      int count = 0;
      for (int r = 0; r < SIZE; r++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         return true;
   }

   // Check first diagonal
   int count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      return true;
    
   // Check second diagonal
   count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = SIZE-1-r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      return true;
    
   // The player did not win
   return false;
}

//---------------------------------------------------
// Print the Tic4 board
//---------------------------------------------------
void Tic4::PrintBoard()
{
   // Draw column numbers
   cout << "\n     ";
   for (int c = 0; c < SIZE; c++)
      cout << c << "   ";
   cout << "\n";

   // Print the Tic4 board
   for (int r = 0; r < SIZE; r++)
   {
      // Draw dashed line
      cout << "   +";
      for (int c = 0; c < SIZE; c++)
         cout << "---+";
      cout << "\n";

      // Draw board contents
      cout << " " << r << " | ";
      for (int c = 0; c < SIZE; c++)
         cout << board[r][c] << " | ";
      cout << "\n";
   }

   // Draw dashed line
   cout << "   +";
   for (int c = 0; c < SIZE; c++)
      cout << "---+";
   cout << "\n\n";
}

//---------------------------------------------------
// Check if board is full
//---------------------------------------------------
bool Tic4::IsFull()
{
   return (board_count == SIZE * SIZE);
}

//---------------------------------------------------
// Simple AI method
//---------------------------------------------------
bool Tic4::SimpleAI(const char player)
{
   cout << "Simple AI." << endl; 
   for(int r = 0; r < SIZE; r++)
   {
      for(int c = 0; c < SIZE; c++)
      {
         if(board[r][c] == ' ')
         {
            board[r][c] = player;
            board_count++;
            cout << r << " " << c << endl;
            return true;
         }
      }
   }
   return false;
}

//---------------------------------------------------
// Random AI method
//---------------------------------------------------
bool Tic4::RandomAI(const char player)
{
   cout << "Random AI." << endl;
   for(int r = 0; r < SIZE; r++)
   {
      for(int c = 0; c < SIZE; c++)
      {
         srand(time(NULL));
         r = random() % SIZE;
         c = random() % SIZE;
         if(board[r][c] == ' ')
         {
            board[r][c] = player;
            board_count++;
            cout << r << " " << c << endl;
            return true;
         }
      }
   }
   return false;
}

//---------------------------------------------------
// Clever AI method
//---------------------------------------------------
bool Tic4::CleverAI(const char player)
{
   cout << "Clever AI." << endl;
   int r, c;
   //Checking the first diagonal
   for(r = 0; r < SIZE; r++)
   {
      c = r;
      if(board[r][c] == ' ')
      {
         board[r][c] = player;
         board_count++;
         cout << "First Diagonal: " << endl;
         cout << r << " " << c << endl;
         return true;
      }
   }

   //Checking the second diagonal
   for(r = 0; r < SIZE; r++)
   {
      c = SIZE-1-r;
      if(board[r][c] == ' ')
      {
         board[r][c] = player;
         board_count++;
         cout << "Second Diagonal: " << endl;
         cout << r << " " << c << endl;
         return true;
      }
   }

   //Scanning the rows and columns
   for(r = 0; r < SIZE; r++)
   {
      for(c =0; c < SIZE; c++)
      {
         if(board[r][c] == ' ')
         {
            board[r][c] = player;
            board_count++;
            cout << "Rows and columns: " << endl;
            cout << r << " " << c << endl;
            return true;
         }
      }
   }
   return false;
}

//---------------------------------------------------
// Fancy AI method
//---------------------------------------------------
bool Tic4::FancyAI(const char player)
{
   srand(time(NULL));
   if((random() % 3) == 0)
   {
      SimpleAI(player);
      return true;
   }
   else if((random() % 3) == 1)
   {
      RandomAI(player);
      return true;
   }
   else if((random() % 3) == 2)
   {
      CleverAI(player);
      return true;
   }
   return false;
}