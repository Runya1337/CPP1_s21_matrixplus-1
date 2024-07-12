#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  CheckNull();
  S21Matrix buff(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      buff.matrix_[j][i] = matrix_[i][j];
    }
  }
  return buff;
}

double S21Matrix::Determinant() {
  CheckNull();
  EqualSquare();
  if (rows_ == 1) {
    return matrix_[0][0];
  } else if (rows_ == 2 && cols_ == 2) {
    return s21_two_size_matrix(*this);
  }
  double result = 0;
  S21Matrix tmp(cols_ - 1, rows_ - 1);
  for (int i = 0; i < cols_; i++) {
    s21_get_matrix(0, i, tmp);
    if (i % 2 == 0) {
      result -= matrix_[0][i] * tmp.Determinant();
    } else {
      result += matrix_[0][i] * tmp.Determinant();
    }
  }
  return -result;
}
void S21Matrix::s21_get_matrix(int rows_index, int collumn_index,
                               S21Matrix& result) {
  int result_row = 0;
  int result_collumn = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i == rows_index || j == collumn_index) {
        continue;
      } else {
        result.matrix_[result_row][result_collumn] = matrix_[i][j];
        result_collumn++;
        if (result_collumn == result.cols_) {
          result_row++;
          result_collumn = 0;
        }
      }
    }
  }
}

S21Matrix S21Matrix::CalcComplements() {
  CheckNull();
  EqualSquare();
  S21Matrix result(rows_, cols_);
  if (rows_ == 1 && cols_ == 1) {
    result.matrix_[0][0] = 1;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        double determinant = 0;
        S21Matrix minor_t(rows_ - 1, cols_ - 1);
        s21_get_matrix(i, j, minor_t);
        determinant = minor_t.Determinant();
        //   printf("Место%d, Детерминант%lf\n", (i*j) + j, determinant);
        result.matrix_[i][j] = pow(-1, (i + 1 + j + 1)) * determinant;
        minor_t.~S21Matrix();
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = 0;
  double div = 0;
  S21Matrix res(rows_, cols_);
  CheckNull();
  det = Determinant();
  if (det == 0) {
    throw std::out_of_range(
        "Incorrect input, determinant should not be zero ONE PIECE");
  }
  *this = CalcComplements();
  *this = Transpose();
  Printmatrix();
  div = 1.0 / det;
  MulNumber(div);
  return *this;
}

double S21Matrix::s21_two_size_matrix(S21Matrix& result) {
  return (result.matrix_[0][0] * result.matrix_[1][1] -
          result.matrix_[0][1] * result.matrix_[1][0]);
}
