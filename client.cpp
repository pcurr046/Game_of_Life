#include <iostream>
#include <fstream>
#include <cctype>
#include "boolMatrix.h"
using namespace std;

void getFileData(/*in*/ifstream &inFile, /*out*/boolMatrix &laif);
void getGenerations(/*out*/ int& numGenerations);
void determineNextGeneration(/*inout*/ boolMatrix& life);
void determineFateOfSingleCell(/*in*/ const boolMatrix& life,/*out*/ boolMatrix& life2, /*in*/int row,/*in*/ int col);
void printResults(/*in*/ const boolMatrix& life);

int main() {
    boolMatrix life;
    string fileName;
    ifstream inFile;
    fileName = "lifedata.txt";
    int numGenerations;
    //open the file
    inFile.open(fileName, ios::in);
    if(!inFile.fail()){ //checks if file successfully opened
        cout << fileName << " was successfully open.";
        getFileData(inFile, life);
        getGenerations(numGenerations);
        for (int count = 0; count < numGenerations; count++){
            cout << "GENERATION " << count << endl;
            printResults(life);
            determineNextGeneration(life);
        }
        inFile.close();
        printResults(life);
    }
    else{
        cout << "File failed to open. Please check your directory data." << endl;
    }
    return 0;
}

void printResults(const boolMatrix& laif){
    laif.printMatrix();
    cout << "Total alive in row 10 = " << laif.rowCount(10) << endl;
    cout << "Total alive in col 10 = " << laif.colCount(10) << endl;
    cout << "Total dead in row 16 = " << boolMatrix::NUM_ROWS - laif.rowCount(16) << endl;
    cout << "Total dead in col 1 = " << boolMatrix::NUM_COLS - laif.colCount(1) << endl;
    cout << "Total alive = " << laif.totalCount() << endl;
    cout << "Total dead = " << boolMatrix::NUM_ROWS*boolMatrix::NUM_COLS - laif.totalCount() << endl;
}



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