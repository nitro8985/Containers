#ifndef SRC_LIB_S21_SET_H_
#define SRC_LIB_S21_SET_H_

#include "s21_binary_tree.h"

namespace s21 {

template <typename T>
class s21_set : public s21_binary_tree<T> {
 public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = T *;
    using const_iterator = const T *;
    using size_type = size_t;

 private:
 public:
    s21_set() : s21_binary_tree<T>::s21_binary_tree() {}
    ~s21_set() {}
};
}  // namespace s21

#endif  // SRC_LIB_S21_SET_H_
