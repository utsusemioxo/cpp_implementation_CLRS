#include "count_sort.h"
#include "heap.h"
#include "insert_sort.h"
#include "matrix.h"
#include "matrix_multiply.h"
#include "merge_sort.h"
#include "priority_queue.hpp"
#include "quick_sort.hpp"
#include <gtest/gtest.h>
#include <iterator>
#include <queue>
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
  clrs::ds::Mat<int> mat(3, 4, 0);
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
  clrs::ds::Mat<int> mat(3, 4, 0);
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
  clrs::ds::Mat<int> sub_0_0_2_3_gt(2, 3, 0);
  sub_0_0_2_3_gt(0, 0) = 1;
  sub_0_0_2_3_gt(0, 1) = 2;
  sub_0_0_2_3_gt(0, 2) = 3;
  sub_0_0_2_3_gt(1, 0) = 5;
  sub_0_0_2_3_gt(1, 1) = 6;
  sub_0_0_2_3_gt(1, 2) = 7;
  // std::cout << "sub_0_0_1_2_gt:\n";
  // std::cout << sub_0_0_1_2_gt;
  clrs::ds::Mat<int> sub_0_0_2_3(mat, 0, 0, 2, 3);
  // std::cout << "sub_0_0_1_2:\n";
  // std::cout << sub_0_0_1_2;
  EXPECT_EQ(sub_0_0_2_3, sub_0_0_2_3_gt);
}

TEST(test_matrix_multiply, test_brut_force) {
  clrs::ds::Mat<int> A(2, 2, 0);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  clrs::ds::Mat<int> B(2, 2, 0);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  clrs::ds::Mat<int> C(2, 2, 0);
  clrs::op::matrix_multiply(A, B, C, 2);
  clrs::ds::Mat<int> C_gt(2, 2, 0);
  C_gt(0, 0) = 7;
  C_gt(0, 1) = 10;
  C_gt(1, 0) = 15;
  C_gt(1, 1) = 22;
  EXPECT_EQ(C, C_gt);
}

TEST(test_matrix_multiply, test_divide_conquer) {
  clrs::ds::Mat<int> A(2, 2, 0);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  clrs::ds::Mat<int> B(2, 2, 0);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  clrs::ds::Mat<int> C(2, 2, 0);
  clrs::op::matrix_multiply_recursive(A, 0, 0, B, 0, 0, C, 0, 0, 2);
  clrs::ds::Mat<int> C_gt(2, 2, 0);
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

TEST(test_priority_queue, test_max_priority_queue) {
  clrs::ds::priority_queue<int> priority_queue;
  priority_queue.max_heap_insert(1);
  priority_queue.max_heap_insert(4);
  priority_queue.max_heap_insert(2);
  priority_queue.max_heap_insert(3);
  priority_queue.max_heap_insert(9);
  priority_queue.max_heap_insert(7);
  priority_queue.max_heap_insert(8);
  priority_queue.max_heap_insert(10);
  priority_queue.max_heap_insert(14);
  priority_queue.max_heap_insert(16);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 16);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 14);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 10);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 9);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 8);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 7);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 4);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 3);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 2);
  EXPECT_EQ(priority_queue.max_heap_extract_max(), 1);
}

// TEST(test_quick_sort, test_quick_sort_partition) {
//   std::vector<int> vec = {2, 8, 7, 1, 3, 5, 6, 4};
//   auto it1 = clrs::sort::partition(vec.begin(), vec.end());
//   std::vector<int> gt = {2, 1, 3, 4, 7, 5, 6, 8};
//   // EXPECT_EQ(vec, gt);
// }

// TEST(test_quick_sort, test_quick_sort_partition2) {
//   std::vector<int> vec = {2, 1, 3};
//   auto it2 = clrs::sort::partition(vec.begin(), vec.end());
//   std::vector<int> gt = {2, 1, 3};
//   EXPECT_EQ(vec, gt);
// }

// TEST(test_quick_sort, test_quick_sort_partition3) {
//   std::vector<int> vec = {5, 7, 8, 6};
//   auto it2 = clrs::sort::partition(vec.begin(), vec.end());
//   std::vector<int> gt = {5, 6, 7, 8};
//   EXPECT_EQ(vec, gt);
// }

TEST(test_quick_sort, test_quick_sort_sort) {
  std::vector<int> vec = {2, 8, 7, 1, 3, 5, 6, 4};
  clrs::sort::quick_sort(vec.begin(), vec.end());
  std::vector<int> gt = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(vec, gt);
}

TEST(test_quick_sort, test_quick_sort_sort2) {
  std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  clrs::sort::quick_sort(vec.begin(), vec.end());
  std::vector<int> gt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(vec, gt);
}

TEST(test_quick_sort, test_quick_sort_sort3) {
  std::vector<int> vec = {10, 10, 10, 10, 10, 5, 5, 5, 5, 5};
  clrs::sort::quick_sort(vec.begin(), vec.end());
  std::vector<int> gt = {5, 5, 5, 5, 5, 10, 10, 10, 10, 10};
  EXPECT_EQ(vec, gt);
}

TEST(test_count_sort, test_vector1) {
  std::vector<int> vec = {10, 10, 10, 10, 10, 5, 5, 5, 5, 5};
  clrs::sort::count_sort sort;
  sort(vec.begin(), vec.end());
  std::vector<int> gt = {5, 5, 5, 5, 5, 10, 10, 10, 10, 10};
  EXPECT_EQ(vec, gt);
}

TEST(test_count_sort, test_vector2) {
  std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  clrs::sort::count_sort sort;
  sort(vec.begin(), vec.end());
  std::vector<int> gt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(vec, gt);
}

TEST(test_count_sort, test_vector3) {
  std::vector<int> vec = {2, 8, 7, 1, 3, 5, 6, 4};
  clrs::sort::count_sort sort;
  sort(vec.begin(), vec.end());
  std::vector<int> gt = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(vec, gt);
}

TEST(test_count_sort, test_vector4) {
  std::vector<int> vec = {2, 5, 3, 0, 2, 3, 0, 3};
  clrs::sort::count_sort sort;
  sort(vec.begin(), vec.end());
  std::vector<int> gt = {0, 0, 2, 2, 3, 3, 3, 5};
  EXPECT_EQ(vec, gt);
}