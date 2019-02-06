/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: Humza Ahmed
 ** Date:   7/3/18
 ** Description: Header file for the Ant Class
 *********************************************************************/

#ifndef Ant_hpp
#define Ant_hpp
//#include "AntBoard.hpp"

class Ant
{
private:
    int antOrientation;                     //1. Up 2. Right 3. Down 4. Left
    int boardRows;                          //Total rows on the board
    int boardCols;                          //Total cols on the board
    int antRow;                             //Ants row on the board
    int antCol;                             //Ants column on the board

public:
    //Constructors for random placement of ant and user placement
    Ant (int totalRow, int totalCol);
    Ant (int antRow, int antCol, int totalRow, int totalCol);
    
    void moveAnt ();
    int getAntOrientation ();
    void turnAnt (bool);
    int getAntRow();
    int getAntCol();
    
    
    
    
};

#endif /* Ant_hpp */
