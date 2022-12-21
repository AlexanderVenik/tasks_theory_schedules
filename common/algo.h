#ifndef TASKS_THEORY_SCHEDULES_ALGO_H
#define TASKS_THEORY_SCHEDULES_ALGO_H

#include <vector>

namespace algorithm {
namespace transposing {

template <typename T>
void transposeVector(std::vector<std::vector<T>>& matrix) {
  for (int i = 0; i < 5; ++i) {
    for (int j = i; j < 5; ++j) {
      std::swap(matrix[i][j], matrix[j][i]);
    }
  }
}
}

}

#endif  //TASKS_THEORY_SCHEDULES_ALGO_H
