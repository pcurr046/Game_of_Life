//Patricia Curry
//CS 10B - Sujan Sarkar
//Project 3
//file: boolMatrix.h
/******************************************************************************************************************
 * This is the specification file for class boolMatrix.                                                           *
 * The class invariant is defined in this case by the integer values representing rows and columns                *
 * that apply to the matrix private variable. The values must be greater or equal to zero and less                *  
 * than the static constant integer variables NUM_ROWS and NUM_COLS, row and columns each within                  *  
 * their corresponding range at all time during class operations.                                                 *
 * The class invariant is guaranteed by the placement of various assert() functions, parameterized                *      
 * accordingly to ensure denial of incorectly creation or modification of object.                                 *
 * The class specification will be as follows:                                                                    * 
 * class boolMatrix{                                                                                              *
 *   public:                                                                                                      *
 *       static const int NUM_ROWS = 20;                                                                          *
 *       static const int NUM_COLS = 20;                                                                          *
 *                                                                                                                *
 *       boolMatrix();                                                                                            *
 *       //Pre:  function call                                                                                    *
 *       //Post: initializes the object with the private member array elements to a value of false                *
 *       //default constructor                                                                                    *
 *                                                                                                                *                                                                                                                
 *       bool getElement(int row, int column) const;                                                              * 
 *       //Pre:  row and column have been initialized to a valid int                                              * 
 *       //Post: returns tru or false held at a specific position in the two-D array                              * 
 *                                                                                                                *
 *       void setElement(int row, int column, bool aliveOrDead);                                                  * 
 *       //Pre:  row and column have been created and initialized to valid int && aliveOrDead is set to valid     *
 *       //Post: set content of single 2D array element                                                           * 
 *                                                                                                                *
 *       int rowCount(int row) const;                                                                             * 
 *       //Pre:  row has been declared and initialized                                                            * 
 *       //Post: returns the number of trues in row row                                                           * 
 *                                                                                                                *
 *       int colCount(int col) const;                                                                             * 
 *       //Pre:  col has been declared and initialized                                                            * 
 *       //Post: returns the number of trues in column col                                                        * 
 *                                                                                                                *
 *       int totalCount() const;                                                                                  * 
 *       //Pre:  function call/object called on has been created                                                  * 
 *       //Post: returns the number of trues in an object grid                                                    * 
 *                                                                                                                *       
 *       int neighborCount(int row, int column) const;                                                            * 
 *       //Pre:  row and column have been declared and initialized                                                * 
 *       //Post: returns the number of alive neighbours of a specific position                                    * 
 *                                                                                                                *
 *       void printMatrix() const;                                                                                * 
 *       //Pre:  function call on an existing object                                                              * 
 *       //Post: display the contents of the  grid, including the row and column indices.                         * 
 *                                                                                                                *       
 *   private:                                                                                                     * 
 *       bool matrix[NUM_ROWS][NUM_COLS];                                                                         * 
 *};                                                                                                              * 
 ******************************************************************************************************************/
#ifndef BOOLMATRIX_H    //include guard
#define BOOLMATRIX_H
class boolMatrix{
    public:
        static const int NUM_ROWS = 20;
        static const int NUM_COLS = 20;
        
        boolMatrix();
        bool getElement(int row, int column) const;
        void setElement(int row, int column, bool aliveOrDead);
        int rowCount(int row) const;
        int colCount(int col) const;
        int totalCount() const;
        int neighborCount(int row, int column) const;
        void printMatrix() const;
    private:
        bool matrix[NUM_ROWS][NUM_COLS];

};
#endif