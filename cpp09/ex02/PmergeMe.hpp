#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <ostream>
#include <vector>

class PmergeMe {
public:
  // Constructors
  PmergeMe();
  PmergeMe(const PmergeMe &src);

  // Destructor
  ~PmergeMe();

  // Operator overloads
  PmergeMe &operator=(const PmergeMe &rhs);

  // Methods
  void parseArgs(int argc, char *argv[]);
  void mergeMe(void);

  const std::vector<int> &getVec(void) const;
  const std::deque<int> &getDeq(void) const;

  double getVecTime(void) const;
  double getDeqTime(void) const;

private:
  std::vector<int> vec;
  std::deque<int> deq;

  double vecTime;
  double deqTime;
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm);

#endif // PMERGE_ME_HPP
