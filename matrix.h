#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template <class T>
class Matrix {
 private:
  std::vector<std::vector<T> > mat;
  unsigned int rows;
  unsigned int cols;

 public:
  Matrix();
  Matrix(unsigned int _rows, unsigned int _cols, const T& _initial);
  Matrix(const Matrix<T>& rhs);
  virtual ~Matrix();

  // Operator overloading, for "standard" mathematical matrix operations
  Matrix<T>& operator=(const Matrix<T>& rhs);

  // Matrix mathematical operations
  Matrix<T>  operator+ (const Matrix<T>& rhs);
  Matrix<T>& operator+=(const Matrix<T>& rhs);
  Matrix<T>  operator- (const Matrix<T>& rhs);
  Matrix<T>& operator-=(const Matrix<T>& rhs);
  Matrix<T>  operator* (const Matrix<T>& rhs);
  Matrix<T>& operator*=(const Matrix<T>& rhs);
  Matrix<T>  transpose();

  // Matrix/scalar operations
  Matrix<T> operator+(const T& rhs);
  Matrix<T> operator-(const T& rhs);
  Matrix<T> operator*(const T& rhs);
  Matrix<T> operator/(const T& rhs);

  // Matrix/vector operations
  std::vector<T> operator*(const std::vector<T>& rhs);
  std::vector<T> diag_vec();

  // Access the individual elements
  T& operator()(const unsigned int& row, const unsigned int& col);
  const T& operator()(const unsigned int& row, const unsigned int& col) const;

  // Access the row and column sizes
  unsigned int get_rows() const;
  unsigned int get_cols() const;

  double determinant(int n);
};


#include "matrix.cpp"

#endif // MATRIX_H
