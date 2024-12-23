#pragma once
#include <iomanip>
#include <iterator>
#include <ostream>
#include <vector>
#include <iostream>

namespace clrs {
namespace sort {

template <typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
class sort_heap {
public:
  Iterator m_heap_root;
  std::size_t m_heap_size;

public:
  void operator()(Iterator begin, Iterator end) {
    build_max_heap(begin, end);
    for (size_t i = m_heap_size - 1; i >= 1; i--) {
      std::swap(*(begin + i), *begin);
      m_heap_size--;
      heapify(0);
    }
  }

private:
  /*
   * Index example: 0~9 is heap element index, not value of key
   *       0
   *      / \
   *     1   2
   *    / \ / \
   *   3  4 5  6
   *  /\  /
   * 7 8 9
   * size = 10, leaves: 5~9, non-leaves: 0~4
   */
  int parent(std::size_t index) { return (index - 1) >> 1; }
  int left(std::size_t index) const { return (index << 1) + 1; }
  int right(std::size_t index) const { return (index << 1) + 2; }

  void print_max_heap() const {
    // for (int i = 0; i <= max_non_leaf(); i++) {
    //   std::cout << data[i];
    //   std::cout << " left:" << data[left(i)];
    //   std::cout << " right:" << data[right(i)];
    //   std::cout << std::endl;
    // }
  }

  void heapify(std::size_t index) {
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l < m_heap_size && *(m_heap_root + l) > *(m_heap_root + index)) {
      largest = l;
    } else {
      largest = index;
    }
    if (r < m_heap_size && *(m_heap_root + r) > *(m_heap_root + largest)) {
      largest = r;
    }
    if (largest != index) {
      // exchange A[i] with A[largest]
      std::swap(*(m_heap_root + index), *(m_heap_root + largest));
      // recursive call
      heapify(largest);
    }
  }

  void build_max_heap(Iterator begin, Iterator end) {
    m_heap_root = begin;
    m_heap_size = std::distance(begin, end);
    for (int i  = (m_heap_size >> 1) - 1; i >= 0; i--) {
      heapify(i);
    }
  }

};
} // namespace sort
} // namespace clrs