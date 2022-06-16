#ifndef GVEC_H
#define GVEC_H
#include <algorithm>
#include <vector>

template <class T>
/* 2D vector structure */
struct gvec {
public:
  /// Array of elements of the vector.
  T num_arr[2];
  std::vector<std::vector<T>> num_vec;

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
  auto iter_a = a.num_vec.begin();
  for (auto iter_b = b.num_vec.begin(); iter_b != b.num_vec.end(); iter_b++) {
    ret.push_back(*iter_a + *iter_b);
    iter_a++;
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
  std::vector<T> c_num_vec;
  for (auto iter = a.num_vec.begin(); iter != a.num_vec.end(); iter++) {
    c_num_vec.push_back(*iter + b);
  }
  struct gvec<T> c(c_num_vec[0], c_num_vec[1]);
  return c;
}

/**
 * Multiply vector by a single number.
 * @param a Vector to multiply.
 * @param b Number used as factor.
 * @param resulting product.
 */
template <class T> gvec<T> gvec_mult(struct gvec<T> a, T b) {
  std::vector<T> vec;
  for (auto iter = a.num_vec.begin(); iter != a.num_vec.end(); iter++) {
    vec.push_back(*iter * b);
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
  return a.num_vec[0] * b.num_vec[0] + a.num_vec[1] * b.num_vec[1];
}

/**
 * Perform by-element vector product.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Resulting product.
 */
template <class T> gvec<T> gvec_bemult(struct gvec<T> a, struct gvec<T> b) {
  std::vector<T> vec;

  auto iter_a = a.num_vec.begin();
  for (auto iter_b = b.num_vec.begin(); iter_b != b.num_vec.end(); iter_b++) {
    vec.push_back(*iter_a * *iter_b);
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
  std::copy(a.num_vec.begin(), a.num_vec.end(), vec.begin());
  b.num_vec = vec;
}

/**
 * Assign array of values to a vector.
 * @param a Vector to assign to.
 * @param b Array to assign to vector.
 */
template <class T> void gvec_assign(gvec<T> *a, std::vector<T> b) {
  a->num_vec = b;
}

/**
 * Perform vector equality.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Equality status.
 */
template <class T> bool gvec_eq(gvec<T> a, gvec<T> b) {
  return std::equal(a.num_vec.begin(), a.num_vec.end(), b.num_vec.begin());
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
  this->num_vec = ret;
}
template <class T> gvec<T>::gvec() {
  std::vector<T> ret{0, 0};
  this->num_vec = ret;
}
template <class T> gvec<T>::gvec(std::vector<T> v) { this->num_vec = v; }

#endif
