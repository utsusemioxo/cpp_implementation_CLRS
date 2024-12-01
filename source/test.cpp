#include "insertion_sort.h"
#include <gtest/gtest.h>
#include <vector>

TEST(InsertionSortTest, SortsEmptyVector) {
  std::vector<int> data{};
  insertionSort(data);

  EXPECT_EQ(data, (std::vector<int>{}));
}