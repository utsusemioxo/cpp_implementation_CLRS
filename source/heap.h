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
  explicit sort_heap(Iterator iter, std::size_t heap_size) : m_heap_root(iter), m_heap_size(heap_size) {
    build_max_heap();
    print_max_heap();
  }
  int parent(std::size_t index) { return (index - 1) >> 1; }
  int left(std::size_t index) const { return (index << 1) + 1; }
  int right(std::size_t index) const { return (index << 1) + 2; }

  // int max_non_leaf() const { return std::floor(size() / 2.0) - 1; }

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

  void build_max_heap() {
    // int size = data.size();
    // if (size == 1)
    //   return;
    // for (int i = max_non_leaf(); i >= 0; i--) {
    //   max_heapify(i);
    // }
  }

};
} // namespace sort
} // namespace clrs