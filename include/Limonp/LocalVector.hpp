#ifndef LIMONP_LOCAL_VECTOR_HPP
#define LIMONP_LOCAL_VECTOR_HPP

#include <iostream>
#include <vector>

namespace Limonp {
using namespace std;

template <class T>
class LocalVector : public vector<T> {
 public:
  LocalVector() {}
  LocalVector(typename vector<T>::const_iterator begin,
              typename vector<T>::const_iterator end)
      : vector<T>(begin, end) {}
  LocalVector(const T* begin, const T* end) : vector<T>(begin, end) {}
  LocalVector(size_t size, const T& t) : vector<T>(size, t) {}
};

template <class T>
ostream & operator << (ostream& os, const LocalVector<T>& vec) {
  if(vec.empty()) {
    return os << "[]";
  }
  os<<"[\""<<vec[0];
  for(size_t i = 1; i < vec.size(); i++) {
    os<<"\", \""<<vec[i];
  }
  os<<"\"]";
  return os;
}

}

#endif
