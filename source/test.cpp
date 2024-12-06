#include "insert_sort.h"
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