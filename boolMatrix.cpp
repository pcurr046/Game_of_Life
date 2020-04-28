#include <iostream>
#include <cassert>
#include <iomanip>
#include "boolMatrix.h"



//definition of NUM_ROWS static member variable
//const int boolMatrix::NUM_ROWS = 20;
//definition of NUM_COLS static member variable
//const int boolMatrix::NUM_COLS = 20;

/********************************************************************************************
 * default constructor: initialize all of the array elements to false                       *
 ********************************************************************************************/
boolMatrix::boolMatrix(){
    for(int row = 0; row < boolMatrix::NUM_ROWS; row++){
        for(int col = 0; col < boolMatrix::NUM_COLS; col++){
            matrix[row][col]=false;
        }
    }
}
/********************************************************************************************    
 * This getter function returns the current contents of a single array element.             *
 * assert() is used to validate row and column and print exit message on console            *
 ********************************************************************************************/
bool boolMatrix::getElement(int row, int column) const{
    assert(row >= 0 && row < boolMatrix::NUM_ROWS && column >= 0 || column < boolMatrix::NUM_COLS);
    return matrix[row][column];
}

/********************************************************************************************
 * This setter function sets the contents of a single array element. It uses arguments to   * 
 * indicate the row and column of the array element that should be set, and the value to    *
 * which it should be set.                                                                  *
 ********************************************************************************************/
void boolMatrix::setElement(int row, int column, bool aliveOrDead){
    assert(row >= 0 || row > boolMatrix::NUM_ROWS ||  column >= 0 || column < boolMatrix::NUM_COLS);
    matrix[row][column] = aliveOrDead;
}
/********************************************************************************************
 * This function counts and returns the number of true values that exist in a given row.    *
 ********************************************************************************************/
int boolMatrix::rowCount(int row){
    assert(row >= 0 || row < boolMatrix::NUM_ROWS);
    int count = 0;
    for(int i = 0; i < boolMatrix::NUM_COLS; i++){
        if(matrix[row][i]){
            count++;
        }
    }
    return count;
}

/********************************************************************************************
 * This function counts and returns the number of true values that exist in a given column. *
 ********************************************************************************************/
int boolMatrix::colCount(int col){
    assert("Sorry, the program tried to access an element that doesn't exist. Exiting now."&&(col < 0 || col >= boolMatrix::NUM_COLS));
    int count = 0;
    for(int i = 0; i < boolMatrix::NUM_ROWS; i++){
        if(matrix[i][col]){
            count++;
        }
    }
    return count;
}

/********************************************************************************************
 * This function counts and return the number of true values that exist in the entire array.*
 ********************************************************************************************/
 int boolMatrix::totalCount(){
     int count = 0;
     for(int i = 0; i < boolMatrix::NUM_ROWS; i++){
         count += rowCount(i);
     }
    return count;
 }
/* 
neighborCount:Given two arguments that indicate the row and column of a particular cell in the matrix, this function returns the number of neighbors that have the value "true". Most positions in the grid have 8 neighbors like the center square in a tic-tac-toe game. The four corner positions have only 3 neighbors each. The remaining positions around the edge of the grid have 5 neighbors each. 
Additional neighborCount() Requirement: In this function you must use your "get()" function to access the matrix, instead of accessing your 2D array data member directly. So, if your data member is named "m", youll say "get(row, col)" instead of "m[row][col]". This will be a safer programming practice, since the get() function will do range checking for you (i.e., it will make sure that row and col are not out-of-bounds of the 2D array).
*/
int boolMatrix::neighborCount(int row, int column){
    int neighbor = 0;
    //bool element = getElement(row, column);
    if(row == 0){
        if(column == 0){
            neighbor = getElement(row, column+1) + getElement(row+1, column+1) + getElement(row+1, column);
        }
        if(column == (boolMatrix::NUM_COLS)-1){
            neighbor= getElement(row, column-1) + getElement(row+1, column-1) + getElement(row+1, column);
        }
        else{
            neighbor = getElement(row, column-1) + getElement(row+1, column-1) + getElement(row+1, column) + getElement(row, column+1) + getElement(row, column+1);
        }
    }
    if(row != 0 && row != (boolMatrix::NUM_ROWS)-1 ){
        if(column == 0){
            neighbor = getElement(row, column+1) + getElement(row+1, column) + getElement(row+1, column+1) + getElement(row-1, column) + getElement(row-1, column+1);
        }
        if(column == (boolMatrix::NUM_ROWS)-1){
            neighbor = getElement(row-1, column) + getElement(row-1, column-1) + getElement(row, column-1) + getElement(row+1, column-1) + getElement(row+1, column);
        }
        else{
            neighbor = getElement(row-1, column) + getElement(row-1, column+1) + getElement(row, column-1) + getElement(row, column+1) + getElement(row+1, column-1)+ getElement(row+1, column) + getElement(row+1, column+1);
        }
    }
    if(row == (boolMatrix::NUM_ROWS)-1 ){
        if(column == 0){
            neighbor = getElement(row-1, column) + getElement(row-1, column+1) + getElement(row, column+1);
        }
        if(column == (boolMatrix::NUM_COLS)-1){
            neighbor = getElement(row, column+1) + getElement(row+1, column+1) + getElement(row+1, column);
        }
        else{
            neighbor = getElement(row, column-1)  + getElement(row, column+1)+ getElement(row-1, column-1) + getElement(row-1, column) + getElement(row-1, column+1);
        }
    }
    return neighbor;
}

/********************************************************************************************
* Display the contents of the array, including the row and column indices. For each element *
* of the *array, a true value must be displayed as an asterisk ("*") and a false value must *
* be displayed as a space.                                                                  *
//This member function is the only one that displays output. It should be formatted as demonstrated here. Make sure that the row and column labels still work correctly if the constants (NUM_ROWS and NUM_COLS) are set to something different, say, 30 instead of 20.
*********************************************************************************************/
void boolMatrix::printMatrix() const{
    std::cout << std::endl;
    for(int row = -1; row < boolMatrix::NUM_ROWS; row++){
        for(int col = -1; col < boolMatrix::NUM_COLS; col++){
            if((col == -1) && (row == -1)){
                std::cout << "  ";
            }
            if( (col == -1) && (row != -1)){
                std::cout << std::setw(2) << row;
            }
            if( (row == -1) && (col != -1)){
                std::cout << col%10;
            }
            if((row != -1) && (col != -1)){
                if (getElement(row, col)){
                    std::cout << "*";
                }
                else{
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}

