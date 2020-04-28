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
    
       // readGrid(life);
    //getGenerations(numGenerations);
    //for (int count = 0; count < numGenerations; count++){
    //    determineNextGeneration(life);
    //}
        inFile.close();
   
    //life.setElement(0,0,true);
    //cout << life.getElement(0,0) << endl;
    printResults(life);

    }
    else{
        cout << "File failed to open. Please check your directory data." << endl;
    }
    return 0;
}

void printResults(const boolMatrix& laif){
    laif.printMatrix();
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

