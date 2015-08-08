#include <iostream>
#include "matrix.h"

int main(int argc, char **argv) {
  Matrix<double> mat1(2, 2, 1.0);
  Matrix<double> mat2(2, 2, 2.0);

  Matrix<double> mat3 = mat1 + mat2;

  for (int i=0; i<mat3.get_rows(); i++) {
    for (int j=0; j<mat3.get_cols(); j++) {
      std::cout << mat3(i,j) << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
