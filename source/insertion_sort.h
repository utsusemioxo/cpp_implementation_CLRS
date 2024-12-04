#pragma once
#include <functional>
#include <iterator>

template <typename Iterator,
          typename CompareType =
              std::greater<typename std::iterator_traits<Iterator>::value_type>>
void insert_sort(const Iterator begin, const Iterator end,
                 CompareType compare = CompareType{}) {
  if (std::distance(begin, end) <= 0)
    return;
  for (auto iter = begin + 1; iter != end; iter++) {
    auto key = *iter;
    auto sorted_iter_end = iter - 1;
    while (sorted_iter_end + 1 != begin && compare(*sorted_iter_end, key)) {
      *(sorted_iter_end + 1) = *sorted_iter_end;
      sorted_iter_end--;
    }
    *(sorted_iter_end + 1) = key;
  }
}