#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "matrix.h"

// Parameter Constructor

template<class T>
Matrix<T>::Matrix() {

}

template<class T>
Matrix<T>::Matrix(unsigned int _rows, unsigned int _cols, const T &_initial) {
  mat.resize(_rows);
  for (unsigned int i=0; i<mat.size(); i++) {
    mat[i].resize(_cols, _initial);
  }
  rows = _rows;
  cols = _cols;
}

template<class T>
Matrix<T>::Matrix( int _rows,int _cols, const double& _initial, int bla) {
  mat.resize(_rows);
  for (unsigned int i=0; i<mat.size(); i++) {
    mat[i].resize(_cols, _initial);
  }
  rows = _rows;
  cols = _cols;
}


// Copy Constructor
template<class T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
  mat = rhs.mat;
  rows = rhs.get_rows();
  cols = rhs.get_cols();
}

// (Virtual) Destructor
template<class T>
Matrix<T>::~Matrix() {
    // add anything
}

// Assignment Operator
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  if (&rhs == this)
    return *this;

  unsigned int new_rows = rhs.get_rows();
  unsigned int new_cols = rhs.get_cols();

  mat.resize(new_rows);
  for (unsigned int i=0; i<mat.size(); i++) {
    mat[i].resize(new_cols);
  }

  for (unsigned int i=0; i<new_rows; i++) {
    for (unsigned int j=0; j<new_cols; j++) {
      mat[i][j] = rhs(i, j);
    }
  }
  rows = new_rows;
  cols = new_cols;

  return *this;
}

// Addition of two matrices
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] + rhs(i,j);
    }
  }

  return result;
}

// Cumulative addition of this matrix and another
template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs) {
  unsigned int rows = rhs.get_rows();
  unsigned int cols = rhs.get_cols();

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      this->mat[i][j] += rhs(i,j);
    }
  }

  return *this;
}

// Subtraction of this matrix and another
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
  unsigned int rows = rhs.get_rows();
  unsigned int cols = rhs.get_cols();
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] - rhs(i,j);
    }
  }

  return result;
}

// Cumulative subtraction of this matrix and another
template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs) {
  unsigned int rows = rhs.get_rows();
  unsigned int cols = rhs.get_cols();

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      this->mat[i][j] -= rhs(i,j);
    }
  }

  return *this;
}

// Left multiplication of this matrix and another
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
  unsigned int rows = rhs.get_rows();
  unsigned int cols = rhs.get_cols();
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      for (unsigned int k=0; k<rows; k++) {
        result(i,j) += this->mat[i][k] * rhs(k,j);
      }
    }
  }

  return result;
}

// Cumulative left multiplication of this matrix and another
template<class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs) {
  Matrix result = (*this) * rhs;
  (*this) = result;
  return *this;
}

// Calculate a transpose of this matrix
template<class T>
Matrix<T> Matrix<T>::transpose() {
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[j][i];
    }
  }

  return result;
}

// Matrix/scalar addition
template<class T>
Matrix<T> Matrix<T>::operator+(const T& rhs) {
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] + rhs;
    }
  }

  return result;
}

// Matrix/scalar subtraction
template<class T>
Matrix<T> Matrix<T>::operator-(const T& rhs) {
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] - rhs;
    }
  }

  return result;
}

// Matrix/scalar multiplication
template<class T>
Matrix<T> Matrix<T>::operator*(const T& rhs) {
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] * rhs;
    }
  }

  return result;
}

// Matrix/scalar division
template<class T>
Matrix<T> Matrix<T>::operator/(const T& rhs) {
  Matrix result(rows, cols, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] / rhs;
    }
  }

  return result;
}

// Multiply a matrix with a vector
template<class T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs) {
  std::vector<T> result(rhs.size(), 0.0);

  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result[i] = this->mat[i][j] * rhs[j];
    }
  }

  return result;
}

// Obtain a vector of the diagonal elements
template<class T>
std::vector<T> Matrix<T>::diag_vec() {
  std::vector<T> result(rows, 0.0);

  for (unsigned int i=0; i<rows; i++) {
    result[i] = this->mat[i][i];
  }

  return result;
}

// Access the individual elements
template<class T>
T& Matrix<T>::operator()(const unsigned int& row, const unsigned int& col) {
  return this->mat[row][col];
}

// Access the individual elements (const)
template<class T>
const T& Matrix<T>::operator()(const unsigned int& row, const unsigned int& col) const {
  return this->mat[row][col];
}

// Get the number of rows of the matrix
template<class T>
unsigned int Matrix<T>::get_rows() const {
  return this->rows;
}

// Get the number of columns of the matrix
template<class T>
unsigned int Matrix<T>::get_cols() const {
  return this->cols;
}

#endif MATRIX_CPP
