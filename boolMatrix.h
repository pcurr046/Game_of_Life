//specification file for class boolMatrix
#ifndef BOOLMATRIX_H    //include guard
#define BOOLMATRIX_H
class boolMatrix{
    public:
        static const int NUM_ROWS = 20;
        static const int NUM_COLS = 20;
        
        boolMatrix();
        //default constructor: initialize all of the array elements to false

        bool getElement(int row, int column) const;
        //return the current contents of a single array element. 

        void setElement(int row, int column, bool aliveOrDead);
        //set the contents of a single array element 

        int rowCount(int row);
        //returns the number of true values that exist in "row" given row. 

        int colCount(int col);
        //returns the number of true values that exist in "col" given column. 

        int totalCount();
        //returns the number of true values that exist in the entire array.
        
        int neighborCount(int row, int column);
        //this function returns the number of neighbors that have the value "true".

        void printMatrix() const;
        //display the contents of the array, including the row and column indices. 

    private:
        bool matrix[NUM_ROWS][NUM_COLS];

};
#endif