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
 * @param B
 * @param C
 * @param n is power of 2
 */
template <typename T>
void matrix_multiply_recursive(const matrix::Mat<T> &A, const matrix::Mat<T> &B,
                               matrix::Mat<T> &C, size_t n) {
  // 1x1 matrix
  if (n == 1) {
  }
}
} // namespace op
} // namespace clrs