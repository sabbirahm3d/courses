#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

class Matrix {

 public:

  /* Matrix() - default constructor
     Preconditions: none
     Postconditions: creates empty, 1-by-1 Matrix.                    */

  Matrix();

  /* Matrix() - constructor
     Preconditions: none
     Postconditions: create a nrow-by-ncol Matrix, intialized to 0.0.
     If nrow or ncol is <= 0, creates a 1-by-1 Matrix.                */

  Matrix(int nrow, int ncol);

  /* Matrix() - copy constructor
     Preconditions: none
     Postconditions: creates a copy of the Matrix m.                  */

  Matrix(const Matrix &m);

  /* ~Matrix() - destructor
     Preconditions: none
     Postconditions none                                              */

  ~Matrix();

  /* GetNumRows() - get the number of rows
     Preconditions: none
     Postconditions: returns the number of rows in the Matrix.       */

  int GetNumRows() const;

  /* GetNumCols() - get the number of columns
     Preconditions: none
     Postconditions: returns the number of columns in the Matrix     */

  int GetNumCols() const;

  /* Get() - Get an element of the Matrix
     Preconditions: i and j are valid row and column indices.
     Postconditions: returns the [i][j] entry of Matrix; if either 
     i or j is invalid, prints a warning and returns 0.              */

  double Get(int i, int j) const;

  /* Set() - Set an element of the Matrix
     Preconditions: i and j are valid row and column indices.
     Postconditions: sets the [i][j] entry to val; if either i or j
     is in valid, prints a warning and leaves the Matrix entry
     unchanged.                                                      */

  void Set(int i, int j, double val);

  /* Matvec() - compute Matrix-vector product (M*x)                 
     Preconditions: the length of x is equal to the number of 
     columns in the matrix.
     Postconditions: returns the Matrix-vector product; if the 
     length of x is incompatible with the number of columns
     in the Matrix, prints a warning and returns an empty vector.   */

  vector<double> Matvec(vector<double> x) const;

  /* operator= - overloaded assignment operator
     preconditions: none
     postconditions: none                                           */

  Matrix& operator=(const Matrix& m);

 private:
  double **m_matrix;
  int m_nrow;
  int m_ncol;
};

#endif
