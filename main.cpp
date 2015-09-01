#include <iostream>
#include "matrix.h"

int main(int argc, char **argv) {

  Matrix<double> mat1(2, 2, 1.0);
  Matrix<double> mat2(2, 2, 2.0);

  mat1(0,1) = 0.5;
  Matrix<double> mat3 = mat1 + mat2;

  std::cout << mat3;
  std::cout << mat3.transpose();
  std::cout << mat3.determinant(mat3.get_cols());
  return 0;
}
