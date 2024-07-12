#include "s21_matrix_oop.h"

void S21Matrix::MemoryAllocated(int row, int col) {
  if (row <= 0 || col <= 0) {
    throw std::invalid_argument("Нулевая матрица невозможна");
  }
  rows_ = row;
  cols_ = col;
  matrix_ = new double*[rows_]();
  for (int place = 0; place < rows_; place++) {
    matrix_[place] = new double[cols_]();
  }
}

void S21Matrix::MatrixCopy(const S21Matrix& o) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
}

void S21Matrix::Printmatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int S21Matrix::GetRows_() { return rows_; }

int S21Matrix::GetCols_() { return cols_; }

void S21Matrix::SetRows(const int row_size) {
  CheckNull();
  S21Matrix buff(row_size, cols_);
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i >= rows_ - 1) {
        buff.matrix_[i][j] = 0;
      } else {
        buff.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = buff;
}

void S21Matrix::SetCols(const int col_size) {
  CheckNull();
  S21Matrix buff(rows_, col_size);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < col_size; j++) {
      if (j >= cols_ - 1) {
        buff.matrix_[i][j] = 0;
      } else {
        buff.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = buff;
}

void S21Matrix::SumMatrix(const S21Matrix& o) {
  CheckNull();
  o.CheckNull();
  EqualSize(o);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + o.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& o) {
  CheckNull();
  o.CheckNull();
  EqualSize(o);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - o.matrix_[i][j];
    }
  }
}

void S21Matrix::EqualSize(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::invalid_argument("Матрицы разных размеров не равны");
  }
}

void S21Matrix::EqualSquare() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Матрица не квадратная");
  }
}

void S21Matrix::CheckNull() const {
  if (matrix_ == nullptr || rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Матрица никуда не указывает или размеры неверны");
  }
}

void S21Matrix::SetPlace(const int i, const int j, const double num) {
  if (i >= rows_ || j >= cols_ || j < 0 || i < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  matrix_[i][j] = num;
}

void S21Matrix::MulNumber(const double num) {
  CheckNull();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::InitMatrix(const double* list_m) {
  int count = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = list_m[count];
      count++;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& o) {
  CheckNull();
  o.CheckNull();
  if (cols_ != o.rows_) {
    throw std::out_of_range("Размеры матриц не подходят для умножения");
  }
  S21Matrix buff(rows_, o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < o.cols_; j++) {
      for (int l = 0; l < o.rows_; l++) {
        buff.matrix_[i][j] += matrix_[i][l] * o.matrix_[l][j];
      }
    }
  }
  *this = buff;
}

bool S21Matrix::isEqMatrix(const S21Matrix& o) {
  bool result = true;
  CheckNull();
  o.CheckNull();
  EqualSize(o);
  for (int i = 0; i < rows_ && result; i++) {
    for (int j = 0; j < cols_ && result; j++) {
      if (fabs(matrix_[i][j] - o.matrix_[i][j]) > 1e-7) {
        result = false;
      }
    }
  }
  return result;
}