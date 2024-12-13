#include "heap.h"
#include "insert_sort.h"
#include "matrix.h"
#include "matrix_multiply.h"
#include "merge_sort.h"
#include <gtest/gtest.h>
#include <iterator>
#include <vector>

using namespace clrs::sort;
TEST(InsertionSortTest, SortsEmptyVector) {
  std::vector<int> data{};
  insert_sort(data.begin(), data.end());

  EXPECT_EQ(data, (std::vector<int>{}));
}

TEST(InsertionSortTest, SortsOneToTen) {
  std::vector<int> data{};
  std::vector<int> gt_data{};
  for (int i = 0; i < 10; i++) {
    data.push_back(i);
    gt_data.push_back(i);
  }
  insert_sort(data.begin(), data.end());
  EXPECT_EQ(data, gt_data);
}

TEST(test_insert_sort, test_C_array) {
  int data1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int data2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int data3[10] = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4};
  int data4[1] = {5};
  int comparedata1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int comparedata2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int comparedata3[10] = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4};
  int comparedata4[1] = {5};

  std::sort(comparedata1, comparedata1 + 10);
  insert_sort(data1 + 0, data1 + 10);
  std::sort(comparedata2, comparedata2 + 10);
  insert_sort(data2 + 0, data2 + 10);
  std::sort(comparedata3, comparedata3 + 10);
  insert_sort(data3 + 0, data3 + 10);
  std::sort(comparedata4, comparedata4 + 1);
  insert_sort(data4 + 0, data4 + 1);
  EXPECT_EQ(std::vector<int>(data1, data1 + 10),
            std::vector<int>(comparedata1, comparedata1 + 10));
  EXPECT_EQ(std::vector<int>(data2, data2 + 10),
            std::vector<int>(comparedata2, comparedata2 + 10));
  EXPECT_EQ(std::vector<int>(data3, data3 + 10),
            std::vector<int>(comparedata3, comparedata3 + 10));
  EXPECT_EQ(std::vector<int>(data4, data4 + 1),
            std::vector<int>(comparedata4, comparedata4 + 1));
}

TEST(test_insert_sort, test_std_container) {
  std::vector<int> data1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> data2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> data3 = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4};
  std::vector<int> data4 = {5};
  std::vector<int> comparedata1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> comparedata2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> comparedata3 = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4};
  std::vector<int> comparedata4 = {5};

  std::sort(comparedata1.begin(), comparedata1.end());
  insert_sort(data1.begin(), data1.end());
  std::sort(comparedata2.begin(), comparedata2.end());
  insert_sort(data2.begin(), data2.end());
  std::sort(comparedata3.begin(), comparedata3.end());
  insert_sort(data3.begin(), data3.end());
  std::sort(comparedata4.begin(), comparedata4.end());
  insert_sort(data4.begin(), data4.end());
  EXPECT_EQ(data1, comparedata1);
  EXPECT_EQ(data2, comparedata2);
  EXPECT_EQ(data3, comparedata3);
  EXPECT_EQ(data4, comparedata4);
}

TEST(InsertionSortTest, SortsTenToOne) {
  std::vector<int> data{};
  std::vector<int> gt_data{};
  for (int i = 0; i < 10; i++) {
    data.push_back(10 - 1 - i);
    gt_data.push_back(i);
  }

  insert_sort(data.begin(), data.end());
  EXPECT_EQ(data, gt_data);
}

TEST(test_merge_sort, test_merge) {
  std::vector<int> data1 = {2, 1};
  std::vector<int> comparedata1 = {2, 1};
  std::sort(comparedata1.begin(), comparedata1.end());
  merge(data1.begin(),
        data1.begin() + std::distance(data1.begin(), data1.end()) / 2,
        data1.end());
  EXPECT_EQ(data1, comparedata1);
}

TEST(test_merge_sort, test_std_container) {
  std::vector<int> data1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> data2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> data3 = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4};
  std::vector<int> data4 = {5};
  std::vector<int> comparedata1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> comparedata2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> comparedata3 = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4};
  std::vector<int> comparedata4 = {5};

  merge_sort(data4.begin(), data4.end());
  std::sort(comparedata1.begin(), comparedata1.end());
  merge_sort(data1.begin(), data1.end());
  std::sort(comparedata2.begin(), comparedata2.end());
  merge_sort(data2.begin(), data2.end());
  std::sort(comparedata3.begin(), comparedata3.end());
  merge_sort(data3.begin(), data3.end());
  std::sort(comparedata4.begin(), comparedata4.end());
  EXPECT_EQ(data1, comparedata1);
  EXPECT_EQ(data2, comparedata2);
  EXPECT_EQ(data3, comparedata3);
  EXPECT_EQ(data4, comparedata4);
}

TEST(test_matrix, test_element_access) {
  clrs::matrix::Mat<int> mat(3, 4, 0);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(0, 2) = 3;
  mat(0, 3) = 4;
  mat(1, 0) = 5;
  mat(1, 1) = 6;
  mat(1, 2) = 7;
  mat(1, 3) = 8;
  mat(2, 0) = 9;
  mat(2, 1) = 10;
  mat(2, 2) = 11;
  mat(2, 3) = 12;
  EXPECT_EQ(mat(0, 0), 1);
  EXPECT_EQ(mat(0, 1), 2);
  EXPECT_EQ(mat(0, 2), 3);
  EXPECT_EQ(mat(0, 3), 4);
  EXPECT_EQ(mat(1, 0), 5);
  EXPECT_EQ(mat(1, 1), 6);
  EXPECT_EQ(mat(1, 2), 7);
  EXPECT_EQ(mat(1, 3), 8);
  EXPECT_EQ(mat(2, 0), 9);
  EXPECT_EQ(mat(2, 1), 10);
  EXPECT_EQ(mat(2, 2), 11);
  EXPECT_EQ(mat(2, 3), 12);
}

TEST(test_matrix, test_sub_matrix) {
  clrs::matrix::Mat<int> mat(3, 4, 0);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(0, 2) = 3;
  mat(0, 3) = 4;
  mat(1, 0) = 5;
  mat(1, 1) = 6;
  mat(1, 2) = 7;
  mat(1, 3) = 8;
  mat(2, 0) = 9;
  mat(2, 1) = 10;
  mat(2, 2) = 11;
  mat(2, 3) = 12;
  // std::cout << "Mat:\n";
  // std::cout << mat;
  clrs::matrix::Mat<int> sub_0_0_2_3_gt(2, 3, 0);
  sub_0_0_2_3_gt(0, 0) = 1;
  sub_0_0_2_3_gt(0, 1) = 2;
  sub_0_0_2_3_gt(0, 2) = 3;
  sub_0_0_2_3_gt(1, 0) = 5;
  sub_0_0_2_3_gt(1, 1) = 6;
  sub_0_0_2_3_gt(1, 2) = 7;
  // std::cout << "sub_0_0_1_2_gt:\n";
  // std::cout << sub_0_0_1_2_gt;
  clrs::matrix::Mat<int> sub_0_0_2_3(mat, 0, 0, 2, 3);
  // std::cout << "sub_0_0_1_2:\n";
  // std::cout << sub_0_0_1_2;
  EXPECT_EQ(sub_0_0_2_3, sub_0_0_2_3_gt);
}

TEST(test_matrix_multiply, test_brut_force) {
  clrs::matrix::Mat<int> A(2, 2, 0);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  clrs::matrix::Mat<int> B(2, 2, 0);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  clrs::matrix::Mat<int> C(2, 2, 0);
  clrs::op::matrix_multiply(A, B, C, 2);
  clrs::matrix::Mat<int> C_gt(2, 2, 0);
  C_gt(0, 0) = 7;
  C_gt(0, 1) = 10;
  C_gt(1, 0) = 15;
  C_gt(1, 1) = 22;
  EXPECT_EQ(C, C_gt);
}

TEST(test_matrix_multiply, test_divide_conquer) {
  clrs::matrix::Mat<int> A(2, 2, 0);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  clrs::matrix::Mat<int> B(2, 2, 0);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  clrs::matrix::Mat<int> C(2, 2, 0);
  clrs::op::matrix_multiply_recursive(A, 0, 0, B, 0, 0, C, 0, 0, 2);
  clrs::matrix::Mat<int> C_gt(2, 2, 0);
  C_gt(0, 0) = 7;
  C_gt(0, 1) = 10;
  C_gt(1, 0) = 15;
  C_gt(1, 1) = 22;
  EXPECT_EQ(C, C_gt);
}

TEST(test_heap, test_max_heapify) {
  std::vector<int> vec = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  std::vector<int> gt_vec = {1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
  // std::vector<int> vec = {1, 2, 3};
  clrs::sort::sort_heap<std::vector<int>::iterator> sorter;
  sorter(vec.begin(), vec.end());
  // for (auto elem : vec) {
  //   std::cout << elem << " ";
  // }
  // std::cout << std::endl;
  EXPECT_EQ(vec, gt_vec);
}