# Tic-Tac-Toe

The purpose of this project was to implement a text-based user interface of the game "Tic-Tac-Toe". Unlike the regular 3x3 board for the game, this game has a 4x4 to add more difficulty to the game and make it more fun. The game allows single user play against designed algorithms. The algorithms for the gameplay were implemented in the following methods:

SimpleAI: This is a method that takes in one parameter (the player character) and scans the 4x4 board from top to bottom and from left to right to find the first empty location. The AI will store the player character in this location and return true. If no location if found, the method returns false. 

RandomAI: This method takes in the player character as a parameter and randomly selects locations on the board until an empty location is found. It will store the location and return true, or otherwise return false if no location is found. 

CleverAI: This method also takes in the player character as a parameter and does a two-pass search for a location to move. First, it searched the two diagonals in the board for an empty location. Second, it searches the non-diagonal locations to find an empty location. The method will then store the player character in the location and return true, or else return false if no location is found. 

FancyAI: This method takes in one parameter and randomly selects one of the other three methods above to make the AI's move. This is the method that is running by default throughout the game since it makes use of all the methods. The method will return true if the method is successful, and false if no location is found. 
