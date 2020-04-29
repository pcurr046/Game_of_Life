//Patricia Curry
//CS 10B - Sujan Sarkar
//Project 3
//file: boolMatrix.cpp

#include <iostream>
#include <cassert>
#include <iomanip>
#include "boolMatrix.h"

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
    assert(row >= 0);
    assert(row < boolMatrix::NUM_ROWS);
    assert(column >= 0);
    assert(column < boolMatrix::NUM_COLS);
    return matrix[row][column];
}

/********************************************************************************************
 * This setter function sets the contents of a single array element. It uses arguments to   * 
 * indicate the row and column of the array element that should be set, and the value to    *
 * which it should be set.                                                                  *
 ********************************************************************************************/
void boolMatrix::setElement(int row, int column, bool aliveOrDead){
    assert(row >= 0 && row < boolMatrix::NUM_ROWS && column >= 0 && column < boolMatrix::NUM_COLS);
    matrix[row][column] = aliveOrDead;
}

/********************************************************************************************
 * This function counts and returns the number of true values that exist in a given row.    *
 ********************************************************************************************/
int boolMatrix::rowCount(int row) const{
    assert(row >= 0 && row < boolMatrix::NUM_ROWS);
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
int boolMatrix::colCount(int col) const{
    assert(col >= 0 && col < boolMatrix::NUM_COLS);
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
 int boolMatrix::totalCount() const{
     int count = 0;
     for(int i = 0; i < boolMatrix::NUM_ROWS; i++){
         count += rowCount(i);
     }
    return count;
 }

/******************************************************************************************** 
 * This function counts how many alive("true") neighbors a select position in the grid has  *
 * with the help on control structures and returns a integer to reflect the number.         *
 * Function piggy backs of the getElement function and has special conditions to count      *
 * number of neighbors based on the position in the grid.                                   *
 ********************************************************************************************/
int boolMatrix::neighborCount(int row, int column) const{
    int neighbor = 0;
    if(row == 0){
        if(column == 0){
            neighbor = getElement(row, column+1) + getElement(row+1, column+1) + getElement(row+1, column);
        }
        else if(column == ((boolMatrix::NUM_COLS)-1)){
            neighbor = getElement(row, column-1) + getElement(row+1, column-1) + getElement(row+1, column);
        }
        else{
            neighbor = getElement(row, column-1) + getElement(row+1, column-1) + getElement(row+1, column) + getElement(row+1, column+1) + getElement(row, column+1);
        }
    }
    if((row != 0) && (row != ((boolMatrix::NUM_ROWS)-1))){
        if(column == 0){
            neighbor = getElement(row, column+1) + getElement(row+1, column) + getElement(row+1, column+1) + getElement(row-1, column) + getElement(row-1, column+1);
        }
        else if(column == ((boolMatrix::NUM_ROWS)-1)){
            neighbor = getElement(row-1, column) + getElement(row-1, column-1) + getElement(row, column-1) + getElement(row+1, column-1) + getElement(row+1, column);
        }
        else{
            neighbor = getElement(row-1, column) + getElement(row-1, column+1) + getElement(row, column-1) + getElement(row, column+1) + getElement(row+1, column-1)+ getElement(row+1, column) + getElement(row+1, column+1) + getElement(row-1, column-1);
        }
    }
    if(row == ((boolMatrix::NUM_ROWS)-1)){
        if(column == 0){
            neighbor = getElement(row-1, column) + getElement(row-1, column+1) + getElement(row, column+1);
        }
        else if(column == ((boolMatrix::NUM_COLS)-1)){
            neighbor = getElement(row, column-1) + getElement(row-1, column) + getElement(row-1, column-1);
        }
        else{
            neighbor = getElement(row, column-1)  + getElement(row, column+1)+ getElement(row-1, column-1) + getElement(row-1, column) + getElement(row-1, column+1);
        }
    }
    return neighbor;
}

/*********************************************************************************************
 * Display the contents of the array, including the row and column indices. For each element *
 * of the *array, a true value must be displayed as an asterisk ("*") and a false value must *
 * be displayed as a space.                                                                  *
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