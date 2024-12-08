#pragma once
#include <iomanip>
#include <ostream>
#include <vector>

namespace clrs {
namespace matrix {
// a simple dense matrix implmentation
template <typename T> class Mat {
private:
  // store matrix data
  std::vector<T> data;
  // store matrix size
  size_t rows, cols;

public:
  /**
   * @brief Construct a new row-major Mat object
   *
   * @param rows
   * @param cols
   * @param initial
   */
  explicit Mat(size_t rows, size_t cols, T initial = T{})
      : rows(rows), cols(cols), data(rows * cols, initial) {}

  Mat(const Mat &other, size_t row_beg, size_t col_beg, size_t row_end,
      size_t col_end)
      : rows(row_end - row_beg), cols(col_end - col_beg) {
    this->data = std::move(std::vector<T>(rows * cols, T{}));
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; ++j) {
        (*this)(i, j) = other(row_beg + i, col_beg + j);
      }
    }
  }

  /**
   * @brief access element at (row, col). row and col starts at 0. no bound
   * check.
   *
   * @param row starts at 0
   * @param col starts at 0
   * @return T&
   */
  T &operator()(const size_t row, const size_t col) {
    return data[row * cols + col];
  }

  /**
   * @brief const access element at (row, col)
   *
   * @param row starts at 0
   * @param col starts at 0
   * @return const T&
   */
  const T &operator()(const size_t row, const size_t col) const {
    return data[row * cols + col];
  }

  friend bool operator==(const Mat<T> &lhs, const Mat<T> &rhs) {
    if (lhs.data.size() != rhs.data.size()) {
      return false;
    }
    if (lhs.cols != rhs.cols || lhs.rows != rhs.rows) {
      return false;
    }
    for (size_t i = 0; i < lhs.rows; ++i) {
      for (size_t j = 0; j < lhs.cols; ++j) {
        if (lhs(i, j) != rhs(i, j))
          return false;
      }
    }
    return true;
  }

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const Mat<U> &matrix);
};

/**
 * @brief Overload << operator
 *
 * @tparam U
 * @param os
 * @param matrix
 * @return std::ostream&
 */
template <typename U>
std::ostream &operator<<(std::ostream &os, const Mat<U> &matrix) {
  os << '\n';
  for (size_t i = 0; i < matrix.rows; ++i) {
    for (size_t j = 0; j < matrix.cols; ++j) {
      os << std::setw(5) << matrix(i, j);
    }
    os << '\n';
  }
  return os;
}

} // namespace matrix
} // namespace clrs