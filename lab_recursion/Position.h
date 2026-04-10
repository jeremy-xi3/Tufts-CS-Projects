/*
 * Position.h
 *
 * CS15 Lab 05: Recursion
 *
 * Describes a Position object, which details a position in 2D: row/col
 * indices. Given a Position, can compute position to the north, south,
 * east, or west.
 *
 * Mark A. Sheldon, Tufts University, Fall 2017
 * 
 * Edited and updated by:
 *        Hameedah Lawal (Feb 2025) - changed from struct to class and added
 *                                    function contracts
 */

#ifndef _POSITION_H_
#define _POSITION_H_

class Position 
{
public:
    Position();
    Position(int r, int c);
    int getRow();
    int getCol();
    Position north();
    Position south();
    Position east();
    Position west();
    
private:
    int row;
    int col;
};

#endif
