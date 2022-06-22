#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
/* 2D vector structure */
struct gvec {
public:
  /// Array of elements of the vector.
  std::vector<T> vec;

  gvec<T> operator+(gvec<T> a);
  gvec<T> operator-(gvec<T> a);
  gvec<T> operator+(T a);
  gvec<T> operator-(T a);
  T operator*(gvec<T> a);
  gvec<T> operator*(T a);
  bool operator==(const gvec<T> a);
  bool operator==(const T a[2]);

  gvec<T>(T a, T b);
  gvec<T>();
  gvec<T>(std::vector<T> v);
};

/// Vector of doubles.
typedef gvec<double> dvec;
/// Vector of integers.
typedef gvec<int> ivec;

/**
 * Perform vector addition.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Resulting addition.
 */
template <class T> gvec<T> gvec_add(struct gvec<T> a, struct gvec<T> b) {
  std::vector<T> ret;
  for (auto iter_a = a.vec.begin(), iter_b = b.vec.begin();
       iter_b != b.vec.end(); iter_a++, iter_b++) {
    ret.push_back(*iter_a + *iter_b);
  }
  return gvec<T>(ret);
}

/**
 * Perform vector and single number addition.
 * @param a Vector to add to.
 * @param b Adding single number.
 * @return resulting addition.
 */
template <class T> gvec<T> gvec_add(struct gvec<T> a, T b) {
  std::vector<T> vec;
  for (auto i = a.vec.begin(); i != a.vec.end(); i++) {
    vec.push_back(*i + b);
  }
  return gvec<T>(vec);
}

/**
 * Multiply vector by a single number.
 * @param a Vector to multiply.
 * @param b Number used as factor.
 * @param resulting product.
 */
template <class T> gvec<T> gvec_mult(struct gvec<T> a, T b) {
  std::vector<T> vec;
  for (auto i = a.vec.begin(); i != a.vec.end(); i++) {
    vec.push_back(*i * b);
  }
  return gvec<T>(vec);
}

/**
 * Perform vector dot product.
 * @param a lhs row vector.
 * @param b rhs column vector.
 * @return Resulting dot product.
 */
template <class T> T gvec_mult(struct gvec<T> a, struct gvec<T> b) {
  return a.vec[0] * b.vec[0] + a.vec[1] * b.vec[1];
}

/**
 * Perform by-element vector product.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Resulting product.
 */
template <class T> gvec<T> gvec_bemult(struct gvec<T> a, struct gvec<T> b) {
  std::vector<T> vec;

  for (auto i_a = a.vec.begin(), i_b = b.vec.begin(); i_a != a.vec.end();
       i_a++, i_b++) {
    vec.push_back((*i_a) * (*i_b));
  }

  return gvec<T>(vec);
}

/**
 * Assign value to a vector.
 * @param a vector to assign to.
 * @param b vector to copy.
 */
template <class T> void gvec_assign(gvec<T> a, gvec<T> b) {
  std::vector<T> vec;
  std::copy(a.vec.begin(), a.vec.end(), vec.begin());
  b.vec = vec;
}

/**
 * Assign array of values to a vector.
 * @param a Vector to assign to.
 * @param b Array to assign to vector.
 */
template <class T> void gvec_assign(gvec<T> *a, std::vector<T> b) {
  a->vec.assign(b.begin(), b.end());
}

/**
 * Perform vector equality.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Equality status.
 */
template <class T> bool gvec_eq(gvec<T> a, gvec<T> b) {
  return std::equal(a.vec.begin(), a.vec.end(), b.vec.begin());
}

template <class T> gvec<T> gvec<T>::operator+(gvec<T> a) {
  return gvec_add(*this, a);
}
template <class T> gvec<T> gvec<T>::operator-(gvec<T> a) {
  return gvec_add(*this, a * (-1));
}
template <class T> gvec<T> gvec<T>::operator+(T a) {
  return gvec_add(*this, a);
}
template <class T> gvec<T> gvec<T>::operator-(T a) {
  return gvec_add(*this, a * (-1));
}
template <class T> T gvec<T>::operator*(gvec<T> a) {
  return gvec_mult(*this, a);
}
template <class T> gvec<T> gvec<T>::operator*(T a) {
  return gvec_mult(*this, a);
}
template <class T> bool gvec<T>::operator==(const gvec<T> a) {
  return gvec_eq(*this, a);
}
template <class T> bool gvec<T>::operator==(const T a[2]) {
  gvec<T> b(a[0], a[1]);
  return gvec_eq(*this, b);
}
template <class T> gvec<T>::gvec(T a, T b) {
  std::vector<T> ret{a, b};
  this->vec.assign(ret.begin(), ret.end());
}
template <class T> gvec<T>::gvec() { this->vec.assign(2, 0); }
template <class T> gvec<T>::gvec(std::vector<T> v) {
  this->vec.assign(v.begin(), v.end());
}
