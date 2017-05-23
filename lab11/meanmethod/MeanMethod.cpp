#include "MeanMethod.h"
#include <numeric>
#include <complex>

template <class T>
T MeanMethod::Mean(std::vector<T> v) {
    T average = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
    return average;
}
