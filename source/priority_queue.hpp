#pragma once
#include <vector>
#include <iostream>

namespace clrs {
namespace ds {

template <typename T> class priority_queue {
  private:
  std::vector<T> m_data;
  std::size_t m_heap_size;
  public:
  T top_priority() {
    if (m_heap_size < 1) {
      std::cout << "heap overflow" << std::endl;
    }
    T ret = m_data[1];
    return ret;
  }

  T extract_top_priority() {
    T top_priority_elem = top_priority();
    m_data[0] = m_data[m_heap_size - 1];
    m_heap_size -= 1;
    heapify(0);
    return top_priority_elem;
  }

  int parent(std::size_t index) { return (index - 1) >> 1; }
  int left(std::size_t index) const { return (index << 1) + 1; }
  int right(std::size_t index) const { return (index << 1) + 2; }
  void heapify(std::size_t index) {
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l < m_heap_size && *(m_data.begin() + l) > *(m_data.begin() + index)) {
      largest = l;
    } else {
      largest = index;
    }
    if (r < m_heap_size && *(m_data.begin() + r) > *(m_data.begin() + largest)) {
      largest = r;
    }
    if (largest != index) {
      std::swap(*(m_data.begin() + index), *(m_data.begin() + largest));
      heapify(largest);
    }
  }
};
} // namespace ds
} // namespace clrs