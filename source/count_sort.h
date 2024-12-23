#pragma once
#include <algorithm>
#include <vector>
namespace clrs {
namespace sort {
/**
 * @brief input value are integer in the range from 0 to k.
 * 
 */
class count_sort{
public:
  /**
   * @brief Construct a new Count Sort object
   * 
   * @param k maximum value in the input array
   */
  void operator()(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int max = 0;
    for (auto iter = begin; iter != end; iter++) {
      if (*iter > max) {
        max = *iter;
      }
    }
    m_count_vec = std::vector<int>(max + 1, 0);
    m_sorted_vec = std::vector<int>(std::distance(begin, end), 0);

    if (std::distance(begin, end) <=1)
      return;
    std::fill(m_count_vec.begin(), m_count_vec.end(), 0);
    std::fill(m_sorted_vec.begin(), m_sorted_vec.end(), 0);
    
    for (auto iter = begin; iter != end; iter++) {
      m_count_vec[*iter] += 1;
    }

    for (auto iter = m_count_vec.begin() + 1; iter != m_count_vec.end(); iter++) {
      *iter += *(iter - 1);
    }

    for (auto iter = end - 1; iter >= begin; iter--) {
      m_sorted_vec[m_count_vec[*iter] - 1] = *iter;
      m_count_vec[*iter]--;
    }

    for (auto iter = begin; iter != end; iter++) {
      *iter = m_sorted_vec[iter - begin];
    }
  }

private:
  int m_k;
  std::vector<int> m_count_vec;
  std::vector<int> m_sorted_vec;
};
}
}