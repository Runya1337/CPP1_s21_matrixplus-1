#ifndef CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& o);
  S21Matrix(S21Matrix&& o);
  S21Matrix(int size);
  S21Matrix& operator=(S21Matrix&& o) noexcept;
  S21Matrix& operator=(const S21Matrix& o);
  ~S21Matrix();

  S21Matrix operator+(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix& o);
  bool operator==(const S21Matrix& o);
  double& operator()(int row, int col);
  double& operator()(int row, int col) const;
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix& operator*=(const S21Matrix& o);
  S21Matrix& operator*=(const double num);

  int GetCols_();
  int GetRows_();
  void SetRows(const int pos);
  void SetCols(const int pos);
  void SetPlace(const int i, const int j, const double num);

  void Printmatrix();
  void SumMatrix(const S21Matrix& o);
  void SubMatrix(const S21Matrix& o);
  void EqualSize(const S21Matrix& o);

  void CheckNull() const;
  void EqualSquare();

  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& o);
  S21Matrix Transpose();
  double Determinant();
  void s21_get_matrix(int rows_index, int collumn_index, S21Matrix& result);
  double s21_two_size_matrix(S21Matrix& result);
  S21Matrix CalcComplements();
  void InitMatrix(const double* list_m);
  S21Matrix InverseMatrix();

  bool isEqMatrix(const S21Matrix& o);
  void MatrixCopy(const S21Matrix& o);

 private:
  void MemoryAllocated(int row, int col);
  int rows_, cols_;
  double** matrix_;
};

#endif  // CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_
