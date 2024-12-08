#pragma once
#include "matrix.h"

namespace clrs {
namespace op {
/**
 * @brief 3 nested loop brut force matrix multiply
 *
 * @tparam T
 * @param A n x n matrix
 * @param B n x n matrix
 * @param C n x n all-zero matrix
 * @param n col and row size
 */
template <typename T>
void matrix_multiply(const matrix::Mat<T> &A, const matrix::Mat<T> &B,
                     matrix::Mat<T> &C, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}

/**
 * @brief A, B, C are n x n matrices and n is an exact power of 2.
 *
 * @tparam T
 * @param A
 * @param row_A
 * @param col_A
 * @param B
 * @param row_B
 * @param col_B
 * @param C
 * @param row_C start row of C
 * @param col_C start col of C
 * @param n is power of 2, when n = 1, do scalar multiply
 */
template <typename T>
void matrix_multiply_recursive(const matrix::Mat<T> &A, size_t row_A,
                               size_t col_A, const matrix::Mat<T> &B,
                               size_t row_B, size_t col_B, matrix::Mat<T> &C,
                               size_t row_C, size_t col_C, size_t n) {
  // 1x1 matrix
  if (n == 1) {
    // Base Case
    C(row_C, col_C) += A(row_A, col_A) * B(row_B, col_B);
    return;
  } else {
    // Divide
    // partition A, B and C into n/2 x n/2 submatrices
    size_t new_size = n / 2;
    // Conquer
    matrix_multiply_recursive(A, row_A, col_A, B, row_B, col_B, C, row_C, col_C,
                              new_size);
    matrix_multiply_recursive(A, row_A, col_A, B, row_B, col_B + new_size, C,
                              row_C, col_C + new_size, new_size);
    matrix_multiply_recursive(A, row_A + new_size, col_A, B, row_B, col_B, C,
                              row_C + new_size, col_C, new_size);
    matrix_multiply_recursive(A, row_A + new_size, col_A, B, row_B,
                              col_B + new_size, C, row_C + new_size,
                              col_C + new_size, new_size);
    matrix_multiply_recursive(A, row_A, col_A + new_size, B, row_B + new_size,
                              col_B, C, row_C, col_C, new_size);
    matrix_multiply_recursive(A, row_A, col_A + new_size, B, row_B + new_size,
                              col_B + new_size, C, row_C, col_C + new_size,
                              new_size);
    matrix_multiply_recursive(A, row_A + new_size, col_A + new_size, B,
                              row_B + new_size, col_B, C, row_C + new_size,
                              col_C, new_size);
    matrix_multiply_recursive(A, row_A + new_size, col_A + new_size, B,
                              row_B + new_size, col_B + new_size, C,
                              row_C + new_size, col_C + new_size, new_size);
  }
}
} // namespace op
} // namespace clrs