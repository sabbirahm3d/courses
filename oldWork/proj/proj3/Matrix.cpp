#include <iostream>
#include <vector>
#include <cmath>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() : m_nrow(1), m_ncol(1)
{
  m_matrix = new double*[1];
  m_matrix[0] = new double[1];
  m_matrix[0][0] = 0.0;
}

Matrix::Matrix(int nrow, int ncol) {
  
  if (nrow > 0 && ncol > 0) {
    // create pointers to rows
    m_matrix = new double*[nrow];
    for (int i = 0; i < nrow; i++) {
      //create individual rows and initialize to 0.0
      m_matrix[i] = new double[ncol];
      for (int j = 0; j < ncol; j++)
	m_matrix[i][j] = 0.0;
    }
    m_nrow = nrow;
    m_ncol = ncol;
  } else {
    m_nrow = m_ncol = 1;
    m_matrix = new double*[1];
    m_matrix[0] = new double[1];
    m_matrix[0][0] = 0.0;
  }
    
}

Matrix::Matrix(const Matrix &m) {
 
  if (m.m_nrow > 0 && m.m_ncol > 0) {
    // create points to rows
    m_matrix = new double*[m.m_nrow];
    for (int i = 0; i < m.m_nrow; i++) {
      // create individual rows and copy values from m
      m_matrix[i] = new double[m.m_ncol];
      for (int j = 0; j < m.m_ncol; j++)
	m_matrix[i][j] = m.m_matrix[i][j];
    }
    m_nrow = m.m_nrow;
    m_ncol = m.m_ncol;
  } else {
    m_nrow = m_ncol = 0;
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < m_nrow; i++)
    delete [] m_matrix[i];
  delete [] m_matrix;
}

int Matrix::GetNumRows() const {
  return m_nrow;
}
 
int Matrix::GetNumCols() const {
  return m_ncol;
}

double Matrix::Get(int i, int j) const {
  
  if (i >= 0 && i < m_nrow && j >= 0 && j < m_ncol)
    return m_matrix[i][j];
  else {
    cerr << "Warning: Matrix::Get index bounds error, i = " << i << ", j = " << j << endl;
    return 0.0;
  }
}

void Matrix::Set(int i, int j, double value) {
  
  if (i >= 0 && i < m_nrow && j >= 0 && j < m_ncol)
    m_matrix[i][j] = value;
  else
    cerr << "Warning: Matrix::Set index bounds error, i = " << i << ", j = " << j << endl;
}     

vector<double> Matrix::Matvec(vector<double> x) const {
  vector<double> y;

  if (x.size() != m_ncol) {
    cerr << "Warning: in Matrix::Matvec, matrix and vector dimensions are incompatible." << endl;
  } else {
    // Loop over rows in matrix
    for (int i = 0; i < m_nrow; ++i) {
      double tmp = 0.0;
      // Loop over columns in matrix
      for (int j = 0; j < m_ncol; ++j)
	tmp += m_matrix[i][j]*x[j];
      y.push_back(tmp);
    }
  }

  return y;
}


Matrix& Matrix::operator=(const Matrix& m) {

  // protect against self-assignment
  if (this != &m) {

    // delete old data
    for (int i = 0; i < m_nrow; i++)
      delete [] m_matrix[i];
    delete [] m_matrix;
    
    if (m.m_nrow > 0 && m.m_ncol > 0) {
      // create row pointers
      m_matrix = new double*[m.m_nrow];
      for (int i = 0; i < m.m_nrow; i++) {
	// create individual rows and copy values from m
	m_matrix[i] = new double[m.m_ncol];
	for (int j = 0; j < m.m_ncol; j++)
	  m_matrix[i][j] = m.m_matrix[i][j];
      }
      m_nrow = m.m_nrow;
      m_ncol = m.m_ncol;
    } else {
      m_nrow = m_ncol = 0;
    }
  }

  return *this;
}
