/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: Humza Ahmed
 ** Date:   7/3/18
 ** Description: This file contains the main and menu functions for the Langton's
 Ant program.
 *********************************************************************/
#include "Ant.hpp"
#include "AntBoard.hpp"
#include <iostream>
#include <limits>


void printBoard(Ant*,AntBoard*,int, int);

int main() {
    int menuSelection = 0, totalRows = 0, totalCols = 0, steps = 0, antRow = 0, antCol = 0;
    Ant *antPtr = NULL;
    
    //Starting Menu with input validation
    while (menuSelection == 0 ){
        std::cout << "1. Start Langton's Ant Simulation" << std::endl;
        std::cout << "2. Start Langton's Ant Simulation with a random starting location" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cin >> menuSelection;
        if (std::cin.fail () || menuSelection < 1 || menuSelection > 3){
            std::cin.clear();
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Error: Invalid Entry! Please enter 1, 2, or 3." << std:: endl;
            menuSelection = 0;
        }
    }
    
    while (menuSelection == 1 || menuSelection == 2) {
        //Starting prompts to get user input on size of board/ant location (if necessary)
        std::cout << "Welcome to the Langton's Ant simulator!" << std::endl;
        std::cout << "What size board would you like to use?" << std::endl;
        
        //Gets rows while performing input validation
        while (totalRows == 0){
            std::cout << "Number of rows?: ";
            std::cin >> totalRows;
            if (std::cin.fail() || totalRows <= 0){
                std::cin.clear();
                std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Error: Invalid Entry! Please enter a positive integer greater than 0" << std::endl;
            }
        }
        
        //Gets columns while performing input validation
        while (totalCols == 0){
            std::cout << "Number of columns?: ";
            std::cin >> totalCols;
            if (std::cin.fail() || totalCols <= 0){
                std::cin.clear();
                std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Error: Invalid Entry! Please enter a positive integer greater than 0" << std::endl;
            }
        }
        
        //Gets steps while performing input validation
        while (steps == 0){
            std::cout << "How many steps would you like to simulate?" << std::endl;
            std::cin >> steps;
            if (std::cin.fail() || steps <= 0){
                std::cin.clear();
                std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Error: Invalid Entry! Please enter a positive integer greater than 0" << std::endl;
            }
        }
        
        //Decides whether or not to randomize location of ant based on user selection
        if (menuSelection == 2){
            antPtr = new Ant(totalRows,totalCols);
        }
        else if (menuSelection == 1){
            std::cout << "Where would you like to place the ant?" << std::endl;
            
            //Gets row location of ant while performing input validation
            while (1){
                std::cout << "Row?" << std::endl;
                std::cin >> antRow;
                if (antRow <= 0 || antRow > totalRows){
                    std::cout << "Error: Invalid Entry! Please enter an integer between 1 and " << totalRows << std::endl;
                }
                else
                    break;
            }
            
            //Gets column location of ant while performing input validation
            while (1){
                std::cout << "Column?" << std::endl;
                std::cin >> antCol;
                if (antRow <= 0 || antCol > totalCols){
                    std::cout << "Error: Invalid Entry! Please enter an integer between 1 and " << totalCols << std::endl;
                }
                else{
                    antCol--;           //Decrements columns and rows to account for array.
                    antRow--;
                    break;
                }
            }
            
            antPtr = new Ant(antRow, antCol, totalRows, totalCols);
        }
        
        //Creates the board object
        AntBoard *boardPtr;
        boardPtr = new AntBoard(totalRows, totalCols);
    
        //Simulation loop
        for (int i = 0; i < steps; i++){
            printBoard (antPtr, boardPtr, totalRows,totalCols);
            for (int p = 0; p < totalRows; p++){
                for ( int k = 0; k < totalCols; k++){
                    if (antPtr->getAntCol() == k && antPtr->getAntRow() == p){
                        antPtr->turnAnt(boardPtr->getSpaceColor(p, k));
                        boardPtr->spaceChange(p, k);
                    }
                }
            }
            antPtr->moveAnt();
        }
        
        menuSelection = 0;
        
        //Deletes dynamically allocated memory
        delete antPtr;
        delete boardPtr;
        antPtr = NULL;
        boardPtr = NULL;
        totalCols = 0;          //Resets cols rows and steps back to 0 so the loop executes properly when
        totalRows = 0;          //playing again
        steps = 0;
        
        
        while (menuSelection == 0 ){
            std::cout << "1. Play again?" << std::endl;
            std::cout << "2. Play again with a randomized location?" << std::endl;
            std::cout << "3. Quit" << std::endl;
            std::cin >> menuSelection;
            if (menuSelection != 1 && menuSelection != 2 && menuSelection != 3){
                std::cout << "Error: Invalid Entry! Please enter 1, 2, or 3." << std:: endl;
                menuSelection = 0;
            }
        }
        
        
        
        
        
        
        
        
    }
    
    return 0;
}

//prints the board
void printBoard (Ant *ant, AntBoard* board, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int p = 0; p < cols; p++){
            if (ant->getAntCol() == p && ant->getAntRow() == i)//checks the boards to see if the ant is in that location
                std::cout << "& ";
            else if (board->getSpaceColor(i, p) == true)         //checks the color of the space if black will print #
                std::cout << "# ";
            else if (board->getSpaceColor(i, p) == false)        //white spaces are 0
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    
}



