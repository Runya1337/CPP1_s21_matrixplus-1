#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
  MemoryAllocated(rows_, cols_);
}

S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  MemoryAllocated(rows_, cols_);
}

S21Matrix::S21Matrix(int size) {
  rows_ = size;
  cols_ = size;
  MemoryAllocated(rows_, cols_);
}

S21Matrix::S21Matrix(S21Matrix&& o)
    : rows_(o.rows_), cols_(o.cols_), matrix_(o.matrix_) {
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix_ = nullptr;
}

S21Matrix::S21Matrix(const S21Matrix& o) : rows_(o.rows_), cols_(o.cols_) {
  MemoryAllocated(rows_, cols_);
  MatrixCopy(o);
}

S21Matrix::~S21Matrix() {
  for (int place = 0; place < rows_; place++) {
    delete[] matrix_[place];
    matrix_[place] = nullptr;
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}
