/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: Humza Ahmed
 ** Date:   7/3/18
 ** Description: Implementation file for the Ant Class
 *********************************************************************/

#include "Ant.hpp"
#include <cstdlib>
#include <ctime>

//Default constructor that randomizes the ants location on the board
Ant::Ant (int totalRow, int totalCol){
    //Defaults ants orientation to Up
    antOrientation = 1;
    
    //Keeps track of the size of the board
    boardCols = totalCol - 1;
    boardRows = totalRow - 1;
    
    //Selects a random column
    srand(static_cast<unsigned int>(time(NULL))); // Seed the time
    int randCol = rand()%(totalCol)+0;
    
    //Selects a random row
    int randRow = rand()%(totalRow)+0;
    
    //Places the ant on the board
    //antLocation [randRow][randCol] = true;
    antRow = randRow;
    antCol = randCol;
}

//Constructor that places ant on a specific location on the board
Ant::Ant (int row, int col, int totalRow, int totalCol) {
    //Places the ant on the board
    antRow = row;
    antCol = col;
    
    //Defaults ants orientation to Up
    antOrientation = 1;
    
    //Keeps track of the size of the board and accounts for array
    boardCols = totalCol - 1;
    boardRows = totalRow - 1;
    
}

//This function will move the ant 1 space ahead depending on its locationa and orientation
void Ant::moveAnt () {
    int counter = 0;                //Counter to make sure this loop only runs once per move
    for (int i = 0; i < boardRows + 1; i++) {
        for (int p = 0; p < boardCols + 1; p++){
            if (i == antRow && p == antCol && counter == 0){
                switch (antOrientation){
                    case 1: {        //Moves ant 1 space up and reverses direction if edge is encountered
                        if (i - 1 < 0){
                            antOrientation = 3;
                            antRow++;
                            break;
                        }
                        else {
                            antRow--;
                            break;
                        }
                    }
                    case 2: {       //Moves ant 1 space to the right and reverses direction if edge is encountered
                        if (p + 1 > boardCols){
                            antOrientation = 4;
                            antCol--;
                            break;
                        }
                        else {
                            antCol++;
                            break;
                        }
                    }
                    case 3: {       //Moves ant 1 space down and reverses direction if edge is encountered
                        if (i + 1 > boardRows){
                            antOrientation = 1;
                            antRow--;
                            break;
                        }
                        else {
                            antRow++;
                            break;
                            }
                    }
                    case 4: {       //Moves ant 1 space to the left and reverses direction if edge is encountered
                        if (p - 1 < 0){
                            antOrientation = 2;
                            antCol++;
                            break;
                        }
                        else {
                            antCol--;
                            break;
                        }
                    }
                }
                counter++;
                break;
            }
        }
    }
}

//Returns the ants orientation
int Ant::getAntOrientation (){
    return antOrientation;
}


//Turns ant based on the color of the space on the board
void Ant::turnAnt(bool spaceColor){
    if (spaceColor == true){
        switch (antOrientation){
            case 1: {                   //Turns ant to the left if space is black
                antOrientation = 4;
                break;
            }
            case 2:{
                antOrientation = 1;
                break;
            }
            case 3:{
                antOrientation = 2;
                break;
            }
            case 4: {
                antOrientation = 3;
                break;
            }
        }
    }
    else if (spaceColor == false){
        switch (antOrientation){
            case 1: {                   //Turns ant to the right if space is white
                antOrientation = 2;
                break;
            }
            case 2:{
                antOrientation = 3;
                break;
            }
            case 3:{
                antOrientation = 4;
                break;
            }
            case 4: {
                antOrientation = 1;
                break;
            }
        }
    }
}

int Ant::getAntRow(){
    return antRow;
}

int Ant::getAntCol(){
    return antCol;
}




    
