/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: Humza Ahmed
 ** Date:   7/3/18
 ** Description: Implementation file for the Board Class
 *********************************************************************/

#include "AntBoard.hpp"

//Constructor that sets the Board to a 2d boolean array of a user specified size
AntBoard::AntBoard (int rowTotal, int columnTotal) {
    //Initializes the board to all white spaces
    board = new bool* [rowTotal];
    for (int i = 0; i < rowTotal; i++)
        board[i] = new bool[columnTotal];
    
    
    totalRows = rowTotal - 1;           //keeps track of board size and accounts for array
    totalCols = columnTotal - 1;
}

//returns the color of the space for the row and column provided
bool AntBoard::getSpaceColor(int row, int column) {
    return board [row][column];
}

//changes the color of the space for the row and column provided
void AntBoard::spaceChange(int row, int column) {
    if (board [row][column] == false)
        board [row][column] = true;
    else if (board [row][column] == true)
        board [row][column] = false;
}

//Destructor
AntBoard::~AntBoard(){
    for (int i = 0; i < totalRows + 1; i++)
        delete [] board[i];
    delete [] board;
}
