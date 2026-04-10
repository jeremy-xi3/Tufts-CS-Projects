/*
 * Position.cpp
 *
 * CS15 Lab 05: Recursion
 * 
 * Implementation of a Position class that can compute a given position's 
 * north, south, east, or west directions.
 *
 * Mark A. Sheldon, Tufts University, Fall 2017
 * 
 */

#include "Position.h"

/* Default Constructor 
 *    Purpose: Construct an instance of a position at (0,0)
 * Parameters: None
 *    Returns: None
 */
Position::Position()
{
    row = 0;
    col = 0;
}

/* Parametrized Constructor 
 *    Purpose: Construct an instance of a position at (r, c)
 * Parameters: int -- row and col of position
 *    Returns: None
 */
Position::Position(int r, int c)
{
    row = r;
    col = c;
}

/* getRow 
 *    Purpose: Getter for row
 * Parameters: None
 *    Returns: int -- the current row
 */
int Position::getRow()
{
    return row;
}

/* getCol 
 *    Purpose: Getter for column
 * Parameters: None
 *    Returns: int -- the current column
 */
int Position::getCol()
{
    return col;
}

/* north 
 *    Purpose: Create and compute the Position north of (row, col)
 * Parameters: None
 *    Returns: None
 */
Position Position::north()
{   
    // TODO: YOUR CODE HERE
    // This is a stub -- remove entire body, then implement
    return Position(row - 1, col);
}

/* south 
 *    Purpose: Create and compute the Position south of (row, col)
 * Parameters: None
 *    Returns: None
 */
Position Position::south()
{   
    // TODO: YOUR CODE HERE
    // This is a stub -- remove entire body, then implement
    return Position(row + 1, col);
}

/* east 
 *    Purpose: Create and compute the Position east of (row, col)
 * Parameters: None
 *    Returns: None
 */
Position Position::east()
{
    // TODO: YOUR CODE HERE
    // This is a stub -- remove entire body, then implement
    return Position(row, col + 1);
}

/* west 
 *    Purpose: Create and compute the Position west of (row, col)
 * Parameters: None
 *    Returns: None
 */
Position Position::west()
{
    // TODO: YOUR CODE HERE
    // This is a stub -- remove entire body, then implement
    return Position(row, col - 1);
}
