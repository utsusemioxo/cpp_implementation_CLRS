#pragma once
#include <functional>
#include <iterator>
namespace clrs {
namespace sort {

/** @brief merge two adjacent sorted sub-array.
 * @param beg location of first element of array L.
 * @param mid point to next position to the last element array L,
 *            and position of the R array's first element.
 * @param end location next to last position of array R
 * @param cmp callable object for compare two elements.
 */
template <typename Iterator,
          typename CompareType =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge(Iterator beg, Iterator mid, Iterator end,
           CompareType compare = CompareType{}) {
  if (std::distance(beg, mid) <= 0 || std::distance(mid, end) <= 0)
    return;

  using ValueType = typename std::iterator_traits<Iterator>::value_type;
  // allocate temporary memory to store two array that need to merge
  std::vector<ValueType> arr_l(beg, mid);
  std::vector<ValueType> arr_r(mid, end);
  // iterator point to begin of left array
  Iterator iter_l = arr_l.begin();
  // iterator point to begin of right array
  Iterator iter_r = arr_r.begin();
  // iterator point to beginning of original array
  Iterator iter = beg;

  // start to merge
  while (iter != end) {
    // be careful when comparing iterators!
    if (iter_l == arr_l.end() && iter_r != arr_r.end()) {
      *iter = *iter_r;
      iter_r++;
    } else if (iter_l != arr_l.end() && iter_r == arr_r.end()) {
      *iter = *iter_l;
      iter_l++;
    } else if (iter_l == arr_l.end() && iter_r == arr_r.end()) {
      return;
    } else {
      if (compare(*iter_l, *iter_r)) {
        *iter = *iter_l;
        iter_l++;
      } else {
        *iter = *iter_r;
        iter_r++;
      }
    }
    // move to next position
    iter++;
  }
}

template <typename Iterator,
          typename CompareType =
              std::greater<typename std::iterator_traits<Iterator>::value_type>>
void merge_sort(Iterator begin, Iterator end,
                CompareType compare = CompareType{}) {
  if (std::distance(begin, end) <= 1)
    return;
  auto offset = std::distance(begin, end);
  Iterator mid = begin + std::floor(offset / 2);
  merge_sort(begin, mid, compare);
  merge_sort(mid, end, compare);
  merge(begin, mid, end);
}
} // namespace sort
} // namespace clrs