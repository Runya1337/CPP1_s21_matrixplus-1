#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix res(*this);
  res.SumMatrix(o);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix res(*this);
  res.SubMatrix(o);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix res(*this);
  res.MulMatrix(o);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

double& S21Matrix::operator()(int row, int col) { return matrix_[row][col]; }

double& S21Matrix::operator()(int row, int col) const {
  return matrix_[row][col];
}

bool S21Matrix::operator==(const S21Matrix& o) {
  bool result = true;
  result = this->isEqMatrix(o);
  return result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
  if (this != &o) {
    this->~S21Matrix();
    this->MemoryAllocated(o.rows_, o.cols_);
    this->MatrixCopy(o);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& o) noexcept {
  if (this != &o) {
    *this = o;
  }
  o.~S21Matrix();
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
  this->SumMatrix(o);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
  this->SubMatrix(o);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
  this->MulMatrix(o);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}