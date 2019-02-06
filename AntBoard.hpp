/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: Humza Ahmed
 ** Date:   7/3/18
 ** Description: Header file for the Board Class
 *********************************************************************/

#ifndef AntBoard_hpp
#define AntBoard_hpp
#include "Ant.hpp"

class AntBoard
{
private:
    bool** board;
    int totalRows, totalCols;
    
    
public:
    //Constructor
    AntBoard (int rowTotal, int columnTotal);
    
    //Destructor
    ~AntBoard();
    
    bool getSpaceColor (int row, int column);
    void spaceChange (int row, int column);
    
};

#endif /* AntBoard_hpp */
