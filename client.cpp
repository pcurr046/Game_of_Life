//Patricia Curry
//CS 10B - Sujan Sarkar
//Project 3
//file: client.cpp

#include <iostream>
#include <fstream>
#include <cctype>
#include "boolMatrix.h"
using namespace std;

void getFileData(/*in*/ifstream &inFile, /*out*/boolMatrix &laif);
//function gets data from file and sets the laif object data accordingly
void getGenerations(/*out*/ int& numGenerations);
//function collects newGenerations int from user through console
void determineNextGeneration(/*inout*/ boolMatrix& life);
//function determins next generation of life
void determineFateOfSingleCell(/*in*/ const boolMatrix& life,/*out*/ boolMatrix& life2, /*in*/int row,/*in*/ int col);
//function determines the fate of one single cell found at row-col
void printResults(/*in*/ const boolMatrix& life);
//function goes through life's grid and prints it

int main() {
    boolMatrix life;
    string fileName;
    ifstream inFile;
    fileName = "lifedata.txt";
    int numGenerations;
    inFile.open(fileName, ios::in); //open the file
    if(!inFile.fail()){             //checks if file successfully opened
        cout << fileName << " was successfully open." << endl;
        getFileData(inFile, life);
        getGenerations(numGenerations);
        for (int count = 0; count < numGenerations; count++){
            determineNextGeneration(life);
        }
        inFile.close();
        cout << "Here's the grid after " << numGenerations << " generations have passed:" << endl;
        printResults(life);
        cout << "Above are the final generation game of life statistics." << endl;
    }
    else{
        cout << "File failed to open. Please check your directory data." << endl;
    }
    return 0;
}


/********************************************************************************************
 * This function prints the grid of an boolMatrix object and other grid statistics          *
 ********************************************************************************************/
void printResults(const boolMatrix& laif){
    laif.printMatrix();
    cout << "Total alive in row 10 = " << laif.rowCount(10) << endl;
    cout << "Total alive in col 10 = " << laif.colCount(10) << endl;
    cout << "Total dead in row 16 = " << boolMatrix::NUM_ROWS - laif.rowCount(16) << endl;
    cout << "Total dead in col 1 = " << boolMatrix::NUM_COLS - laif.colCount(1) << endl;
    cout << "Total alive = " << laif.totalCount() << endl;
    cout << "Total dead = " << boolMatrix::NUM_ROWS*boolMatrix::NUM_COLS - laif.totalCount() << endl;
}


/********************************************************************************************
 * This function reads data from file and sets the called elements of laif boolMatrix object*
 * according to the file data                                                               *
 ********************************************************************************************/
void getFileData(ifstream &inFile, boolMatrix &laif){
    while(inFile){
        int row, column;
        bool status = true;
        inFile >> row;
        inFile >> column;
        if(row < 0 || row >= boolMatrix::NUM_ROWS ||  column < 0 || column >= boolMatrix::NUM_COLS){
            continue;
        }
        else{
            laif.setElement(row, column, status);
        }
    }
}

/********************************************************************************************
 * This function get's the number of generations from user though the console               *
 ********************************************************************************************/
void getGenerations(/*out*/ int& numGenerations){
    int generations;
    cout << "How many generations should elapse? " << endl;
    cin >> generations;
    while(generations < 0 || cin.fail()){
        if(cin.fail()){
            cin.clear();
        }
        cin >> generations;
    }
    numGenerations = generations;
}

/********************************************************************************************
 * This function determins if what the new grid will like in the next generation, based on  *
 * decisions made in determineFateOfSingleCell(w,x,y,z). Function stores new generation in  *
 * life2 variable and copies life2 into life when the generation is complete. Since life is *
 * passed by reference, the information will be updated throughout the program.             *
 ********************************************************************************************/
void determineNextGeneration(/*inout*/ boolMatrix& life){
    boolMatrix life2;
    for(int row = 0; row < boolMatrix::NUM_ROWS; row++){
        for(int col = 0; col < boolMatrix::NUM_COLS; col++){
            determineFateOfSingleCell( life, life2, row, col);
        }
    }
    for(int rowz = 0; rowz < boolMatrix::NUM_ROWS; rowz++){
        for(int colz = 0; colz < boolMatrix::NUM_COLS; colz++){
            bool status = life2.getElement(rowz, colz);
            life.setElement(rowz, colz, status);
        }
    }
}

/********************************************************************************************
 * This function decides the fate of a single cell by taking in the position of the cell in *
 * the grid and analizing how many alive neighbors it has and it's own status(live or dead) *
 * Dead cells that have exactly 3 alive neighbors in the last generation, will come to life *
 * in this generation. Alive cells that have two or three live neighbors will stay alive    *
 * Everybody else will die or stay dead.                                                    *
 ********************************************************************************************/
void determineFateOfSingleCell(/*in*/ const boolMatrix& life,/*out*/ boolMatrix& life2, /*in*/int row,/*in*/ int col){
     bool alive = true, dead = false;
    if(life.getElement(row, col)){
        if((life.neighborCount(row, col)==2) || (life.neighborCount(row, col)==3)){
            life2.setElement(row, col, alive);
        }
        else{
            life2.setElement(row, col, dead);
        }
    }
    else if(!(life.getElement(row, col))){
        if(life.neighborCount(row, col)==3){
            life2.setElement(row, col, alive);
        }
        else{
            life2.setElement(row, col, dead);
        }
    }
}