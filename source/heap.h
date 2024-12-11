#pragma once
#include <iomanip>
#include <ostream>
#include <vector>
#include <iostream>

namespace clrs {
namespace ds {

template <typename T> class MaxHeap {
public:
  std::vector<T> data;

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
  explicit MaxHeap(const std::vector<T> &elements) : data(elements) {
    build_max_heap();
    print_max_heap();
  }
  int parent(int i) { return std::floor((i - 1.0) / 2); }
  int left(int i) const { return 2 * i + 1; }
  int right(int i) const { return 2 * i + 2; }

  int max_non_leaf() const { return std::floor(size() / 2.0) - 1; }

  int size() const { return data.size(); }

  void print_max_heap() const {
    for (int i = 0; i <= max_non_leaf(); i++) {
      std::cout << data[i];
      std::cout << " left:" << data[left(i)];
      std::cout << " right:" << data[right(i)];
      std::cout << std::endl;
    }
  }

  void max_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < this->size() && data[l] > data[i]) {
      largest = l;
    } else {
      largest = i;
    }
    if (r < this->size() && data[r] > data[largest]) {
      largest = r;
    }
    if (largest != i) {
      // exchange A[i] with A[largest]
      T elem = data[i];
      data[i] = data[largest];
      data[largest] = elem;
      // recursive call
      max_heapify(largest);
    }
  }

  void build_max_heap() {
    int size = data.size();
    if (size == 1)
      return;
    for (int i = max_non_leaf(); i >= 0; i--) {
      max_heapify(i);
    }
  }

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const MaxHeap<U> &max_heap);
};

template <typename U>
std::ostream &operator<<(std::ostream &os, const MaxHeap<U> &max_heap) {
  os << "\n";
  int levels = std::ceil(std::log2(max_heap.size()) + 1);
  std::cout << "levels=" << levels << std::endl;
  int width = std::pow(2, levels) * 2;
  for (int i = 0, level = 0; i < max_heap.size(); level++) {
    int nodes = std::pow(2, level);
    int space = width / (nodes + 1);

    for (int j = 0; j < nodes && i < max_heap.size(); j++, i++) {
      os << std::setw(space) << max_heap.data[i];
    }
  }
  os << std::endl;
  return os;
}
} // namespace ds
} // namespace clrs