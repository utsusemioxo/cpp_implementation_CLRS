#pragma once
#include <limits>
#include <utility>
#include <vector>
#include <iostream>

namespace clrs {
namespace ds {

template <typename T> class priority_queue {
  private:
  std::vector<T> m_data;
  std::size_t m_heap_size{0};
  public:
  T max_heap_maximum() {
    if (m_heap_size < 1) {
      std::cerr << "heap underflow" << std::endl;
    }
    T ret = m_data[0];
    return ret;
  }

  T max_heap_extract_max() {
    T top_priority_elem = max_heap_maximum();
    m_data[0] = m_data[m_heap_size - 1];
    m_heap_size -= 1;
    heapify(0);
    // for (int i = 0; i < (m_heap_size >> 1); i++) {
    //   std::cout << "\n" << m_data[i] << "\n";
    //   std::cout << "\tleft: " << m_data[left(i)] << "\n";
    //   std::cout << "\tright: " << m_data[right(i)] << "\n";
    // }
    return top_priority_elem;
  }

  void max_heap_insert(T elem) {
    m_heap_size += 1;
    if (m_data.size() == m_heap_size) {
      // no room for new element
      std::cerr << "heap overflow" << std::endl;
      return;
    }
    m_data.push_back(elem);
    if (m_heap_size == 1)
      return;

    T k = elem;
    *(m_data.begin() + m_heap_size - 1) = std::numeric_limits<T>::min();
    max_heap_increase_key(m_heap_size - 1, k);
  }

  
  void max_heap_increase_key(std::size_t index, T k) {
    if (k < *(m_data.begin() + index)) {
      std::cerr << "new key is smaller than current key" << std::endl;
    }
    *(m_data.begin() + index) = k;

    while (index > 0 && m_data[parent(index)] <= m_data[index]) {
      std::swap(m_data[parent(index)], m_data[index]);
      index = parent(index);
    }
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