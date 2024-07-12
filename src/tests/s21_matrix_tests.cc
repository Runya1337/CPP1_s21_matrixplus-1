#include "s21_matrix_tests.h"

namespace CPP1_S21_MATRIXPLUS {

/*############### CONSTRUCTOR ################*/

TEST(TestConstructorParam, test_1) {
  S21Matrix A(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);
  ASSERT_EQ(A(2, 2), 3);
}

TEST(TestMemoryAllocatedZero, test_1) { EXPECT_ANY_THROW(S21Matrix A(0, 0)); }

TEST(TestSetCols, test_1) {
  S21Matrix A(3, 3);
  A.SetCols(2);
  ASSERT_EQ(A.GetCols_(), 2);
}

TEST(TestSetRows, test_1) {
  S21Matrix A(3, 3);
  A.SetRows(2);
  ASSERT_EQ(A.GetRows_(), 2);
}

TEST(TestDeterminant4x4, test_1) {
  S21Matrix A(4, 4);
  double det = A.Determinant();
  ASSERT_EQ(det, 0);
}

TEST(TestDeterminant5x5, test_1) {
  S21Matrix A(5, 5);

  double det = A.Determinant();
  ASSERT_EQ(det, 0);
}

TEST(TestMullMatrixOtherMatrix, test_1) {
  S21Matrix A(3, 3);
  S21Matrix B(4, 4);
  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(TestCheckNullMAtrix, test_1) {
  S21Matrix A(3, 3);
  A.~S21Matrix();
  EXPECT_ANY_THROW(A.CheckNull());
}

TEST(TestSetPlace, test_1) {
  S21Matrix A(3, 3);
  A.SetPlace(0, 0, 1);
  ASSERT_EQ(A(0, 0), 1);
}

TEST(TestSetPlacethrow, test_1) {
  S21Matrix A(3, 3);
  EXPECT_ANY_THROW(A.SetPlace(4, 4, 1));
}

TEST(TestGetPlace, test_1) {
  const S21Matrix A(3, 3);
  ASSERT_EQ(A(0, 0), 0);
}

TEST(TestConstructorSize, test_1) {
  S21Matrix A(3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);
  ASSERT_EQ(A(2, 2), 3);
}

TEST(TestConstructorCopy, test_1) {
  S21Matrix A(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);
  S21Matrix B(A);
  ASSERT_TRUE(A.isEqMatrix(B));
}

TEST(MoveConstructor, test_1) {
  S21Matrix A(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);

  S21Matrix res = A;
  S21Matrix B(std::move(A));

  EXPECT_EQ(B.GetRows_(), 3);
  EXPECT_EQ(B.GetCols_(), 3);
  EXPECT_EQ(A.GetRows_(), 0);
  EXPECT_EQ(A.GetCols_(), 0);

  EXPECT_TRUE(B.isEqMatrix(res));
}

/*############### BASE FUNC ################*/

TEST(TestEq, test_1) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_1[1] = {5};
  S21Matrix A(5, 5);
  A.InitMatrix(list_numbers);
  S21Matrix B(1, 1);
  B.InitMatrix(list_numbers_1);
  EXPECT_ANY_THROW(A.isEqMatrix(B));
}

TEST(TestEq, test_2) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.InitMatrix(list_numbers);
  B.InitMatrix(list_numbers);
  ASSERT_TRUE(A.isEqMatrix(B));
}

TEST(TestEq, test_3) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  B.InitMatrix(list_numbers);
  EXPECT_FALSE(A.isEqMatrix(B));
}

TEST(TestEq, test_4) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 1;
  B(0, 0) = -1;
  EXPECT_FALSE(A.isEqMatrix(B));
}

TEST(TestSum, test_1) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {10, 14, 2, -8, 2, 0, 4, 0, 6};
  S21Matrix A(3, 3);
  A.InitMatrix(list_numbers);
  S21Matrix B(A);
  B.InitMatrix(list_numbers);
  A.SumMatrix(B);
  S21Matrix C(3, 3);
  C.InitMatrix(list_numbers_answer);

  ASSERT_TRUE(A.isEqMatrix(C));
}

TEST(TestSum, test_2) {
  S21Matrix A;
  S21Matrix B(2, 2);
  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(TestSub, test_1) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  S21Matrix A(3, 3);
  A.InitMatrix(list_numbers);
  S21Matrix B(A);
  A.SubMatrix(B);
  S21Matrix C(3, 3);
  ASSERT_TRUE(A.isEqMatrix(C));
}

TEST(TestSub, test_2) {
  S21Matrix A;
  S21Matrix B(2, 2);
  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(TestMulNumber, test_1) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {10, 14, 2, -8, 2, 0, 4, 0, 6};
  S21Matrix A(3, 3);
  A.InitMatrix(list_numbers);
  A.MulNumber(2);
  S21Matrix C(3, 3);
  C.InitMatrix(list_numbers_answer);
  ASSERT_TRUE(A.isEqMatrix(C));
}

TEST(TestMulMatrix, test_1) {
  double list_numbers_A[6] = {5, 7, 1, -4, 1, 0};
  double list_numbers_B[6] = {5, 7, 1, -4, 1, 0};
  double list_numbers_Answer[9] = {-3, 42, 5, 21, 3, 1, 5, 7, 1};
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  S21Matrix C(3, 3);
  A.InitMatrix(list_numbers_A);
  B.InitMatrix(list_numbers_B);
  C.InitMatrix(list_numbers_Answer);
  A.MulMatrix(B);
  ASSERT_TRUE(A.isEqMatrix(C));
}

TEST(TestTranspose, test_1) {
  double list_numbers_A[4] = {5, 7, 1, -4};
  double list_numbers_Answer[4] = {5, 1, 7, -4};
  S21Matrix A(2, 2);
  S21Matrix C(2, 2);
  A.InitMatrix(list_numbers_A);
  C.InitMatrix(list_numbers_Answer);
  S21Matrix t = A.Transpose();
  ASSERT_TRUE(C.isEqMatrix(t));
}

TEST(TestDeterminant, test_1) {
  S21Matrix A(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);
  EXPECT_EQ(A.Determinant(), 97);
}

TEST(TestDeterminant, test_3) {
  S21Matrix A(3, 4);
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(TestDeterminant, test_4) {
  S21Matrix A(1, 1);
  A(0, 0) = 100;

  EXPECT_EQ(A.Determinant(), 100);
}

TEST(TestCalcComplements, test_1) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {3, 12, -2, -21, 13, 14, -1, -4, 33};
  A.InitMatrix(list_numbers);
  res.InitMatrix(list_numbers_answer);
  S21Matrix B = A.CalcComplements();
  EXPECT_TRUE(B.isEqMatrix(res));
}

TEST(TestCalcComplements, test_2) {
  S21Matrix A(2, 2);
  S21Matrix res(2, 2);
  double list_numbers[4] = {5, 7, 1, -4};
  res(0, 0) = -4;
  res(0, 1) = -1;
  res(1, 0) = -7;
  res(1, 1) = 5;

  A.InitMatrix(list_numbers);
  S21Matrix B = A.CalcComplements();
  EXPECT_TRUE(B.isEqMatrix(res));
}

TEST(TestCalcComplements, test_3) {
  S21Matrix A(4, 2);
  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(InverseMtarix, test_1) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);

  res(0, 0) = 1;
  res(0, 1) = -1;
  res(0, 2) = 1;
  res(1, 0) = -38;
  res(1, 1) = 41;
  res(1, 2) = -34;
  res(2, 0) = 27;
  res(2, 1) = -29;
  res(2, 2) = 24;

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  S21Matrix B = A.InverseMatrix();

  EXPECT_TRUE(B.isEqMatrix(res));
}

TEST(InverseMtarix, test_2) {
  S21Matrix A(4, 2);
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(InverseMatrix, test_3) {
  S21Matrix A;
  S21Matrix res;
  res(0, 0) = 0.1;
  A(0, 0) = 10;
  S21Matrix B = A.InverseMatrix();
  EXPECT_TRUE(B.isEqMatrix(res));
}

TEST(InverseMtarix, test_4) {
  S21Matrix A(2, 2);
  EXPECT_ANY_THROW(A.InverseMatrix());
}

/*############### OVERLOAD OPERATOR ################*/

TEST(Copyoperator, test_1) {
  S21Matrix A(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);
  S21Matrix result = A;
  EXPECT_TRUE(A.isEqMatrix(result));
}

TEST(Moveoperator, test_1) {
  S21Matrix A(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  A.InitMatrix(list_numbers);
  S21Matrix B = std::move(A);

  EXPECT_EQ(A.GetRows_(), 0);
  EXPECT_EQ(A.GetCols_(), 0);
  EXPECT_EQ(B.GetRows_(), 3);
  EXPECT_EQ(B.GetCols_(), 3);
}

TEST(TestoperatorPlus, test_1) {
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {10, 14, 2, -8, 2, 0, 4, 0, 6};
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix res(3, 3);
  A.InitMatrix(list_numbers);
  B.InitMatrix(list_numbers);
  res.InitMatrix(list_numbers_answer);
  S21Matrix C = A + B;
  EXPECT_TRUE(C.isEqMatrix(res));
}

TEST(TestoperatorPlusEq, test_1) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {10, 14, 2, -8, 2, 0, 4, 0, 6};
  res.InitMatrix(list_numbers_answer);
  A.InitMatrix(list_numbers);
  S21Matrix C(A);
  C += A;
  EXPECT_TRUE(C.isEqMatrix(res));
}

TEST(TestoperatorMinus, test_1) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {10, 14, 2, -8, 2, 0, 4, 0, 6};
  S21Matrix C(3, 3);
  C.InitMatrix(list_numbers_answer);
  A.InitMatrix(list_numbers);
  S21Matrix orig = C - A;
  EXPECT_TRUE(orig.isEqMatrix(A));
}

TEST(TestoperatorMinusEq, test_1) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);
  double list_numbers[9] = {5, 7, 1, -4, 1, 0, 2, 0, 3};
  double list_numbers_answer[9] = {10, 14, 2, -8, 2, 0, 4, 0, 6};
  S21Matrix C(3, 3);
  C.InitMatrix(list_numbers_answer);
  res.InitMatrix(list_numbers);
  A.InitMatrix(list_numbers);
  C -= A;
  EXPECT_TRUE(C.isEqMatrix(res));
}

TEST(TestoperatorMulMatrix, test_1) {
  S21Matrix A;
  S21Matrix res;
  res(0, 0) = 10;
  A(0, 0) = 5;
  S21Matrix C;
  C(0, 0) = 2;
  S21Matrix origin = C * A;
  EXPECT_EQ(origin(0, 0), res(0, 0));
}

TEST(TestoperatorMulNum, test_1) {
  S21Matrix A;
  S21Matrix res;
  res(0, 0) = 10;
  A(0, 0) = 5;

  double val = 2;
  S21Matrix origin = A * val;

  EXPECT_EQ(origin(0, 0), res(0, 0));
}

TEST(TestoperatorEq, test_1) {
  S21Matrix A(2, 2);
  S21Matrix B(A);

  EXPECT_TRUE(A == B);
}

TEST(TestoperatorMulEqval, test_1) {
  S21Matrix A;
  S21Matrix res;
  res(0, 0) = 10;
  A(0, 0) = 5;

  double val = 2;
  A *= val;

  EXPECT_EQ(A(0, 0), res(0, 0));
}

TEST(TestoperatorMultEqmat, test_1) {
  S21Matrix A;
  S21Matrix res;
  res(0, 0) = 10;
  A(0, 0) = 5;
  S21Matrix C;
  C(0, 0) = 2;
  C *= A;
  EXPECT_EQ(C(0, 0), res(0, 0));
}

/*############### GET&SET ################*/

TEST(TestSetcolsrows, test_2) {
  S21Matrix A(1, 1);
  S21Matrix res(2, 2);
  A.SetCols(2);
  A.SetRows(2);

  EXPECT_TRUE(A.isEqMatrix(res));
}

}  // namespace CPP1_S21_MATRIXPLUS