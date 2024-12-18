#pragma once
#include <functional>
#include <iterator>
namespace clrs {
namespace sort {

template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
Iterator partition(Iterator begin, Iterator end, CompareType compare = CompareType{}) {
  using ValueType = typename std::iterator_traits<Iterator>::value_type;
  Iterator i = begin - 1;
  Iterator j = begin;
  Iterator r = end - 1;
  ValueType pivot_element = *r; // use last element as pivot
  // compare elements in [begin, end - 2] with pivot_element
  for(;j != r;j++) {
    if (compare(*j , pivot_element)) {
      i = i + 1;
      std::swap(*i, *j);
    }
  }
  std::swap(*(i + 1), *r);
  return i + 1; 
}

template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
void quick_sort(Iterator begin, Iterator end, CompareType compare = CompareType{}) {
  if (std::distance(begin, end) > 1) {
    Iterator q = partition(begin, end);
    quick_sort(begin, q);
    quick_sort(q + 1, end);
  }
}

}
}