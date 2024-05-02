#include "PmergeMe.hpp"

#include <algorithm>
#include <cerrno>

#define INSERTION_THRESHOLD 16 // Threshold for switching to insertion sort

template <typename T> void insertionSort(T begin, T end) {
  for (T i = begin + 1; i != end; ++i) {
    typename T::value_type key = *i;
    T j = std::upper_bound(begin, i, key);

    std::rotate(j, i, i + 1);
  }
}

template <typename T>
void mergeInsertionSort(T &data, typename T::iterator begin,
                        typename T::iterator end) {
  int size = std::distance(begin, end);

  if (size <= INSERTION_THRESHOLD) {
    insertionSort(begin, end);
  } else {
    // Divide the range into two halves
    typename T::iterator mid = begin + (size / 2);

    // Sort each half recursively using merge-insertion sort
    mergeInsertionSort(data, begin, mid);
    mergeInsertionSort(data, mid, end);

    // Merge the sorted halves using merge sort
    std::inplace_merge(begin, mid, end);
  }
}

PmergeMe::PmergeMe(void) : vecTime(0.0), deqTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe &src)
    : vec(src.vec), deq(src.deq), vecTime(0.0), deqTime(0.0) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    this->vec = rhs.vec;
    this->deq = rhs.deq;

    this->vecTime = rhs.vecTime;
    this->deqTime = rhs.deqTime;
  }

  return *this;
}

void PmergeMe::parseArgs(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    char *endptr;
    int n = std::strtol(argv[i], &endptr, 10);
    if (errno == ERANGE || *endptr != '\0' || n < 0) {
      throw std::exception();
    }

    this->vec.push_back(n);
    this->deq.push_back(n);
  }
}

void PmergeMe::mergeMe(void) {
  clock_t start, end;

  start = clock();
  mergeInsertionSort(this->vec, vec.begin(), vec.end());
  end = clock();

  this->vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  start = clock();
  mergeInsertionSort(this->deq, deq.begin(), deq.end());
  end = clock();

  this->deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

const std::vector<int> &PmergeMe::getVec(void) const { return this->vec; }

const std::deque<int> &PmergeMe::getDeq(void) const { return this->deq; }

double PmergeMe::getVecTime(void) const { return this->vecTime; }

double PmergeMe::getDeqTime(void) const { return this->deqTime; }

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm) {
  os << "Vector: ";
  for (std::vector<int>::const_iterator it = pm.getVec().begin();
       it != pm.getVec().end(); it++) {
    os << *it << " ";
  }

  os << "| " << "Deque: ";
  for (std::deque<int>::const_iterator it = pm.getDeq().begin();
       it != pm.getDeq().end(); it++) {
    os << *it << " ";
  }

  return os;
}
