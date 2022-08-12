#ifndef SRC_CONTAINER_VECTOR_H_
#define SRC_CONTAINER_VECTOR_H_

#include "sequcontainer.h"

namespace s21 {
template <typename T>
class Vector : public SequContainer<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  size_type v_capacity;

 private:
  void set_value_safe(size_type pos, const_reference value) {
    if (pos < v_capacity) SequContainer<T>::set_value(pos, value);
  }

  void copy_content(Vector<T> *vec, T *newArr) {
    std::copy(vec->begin(), vec->end(), newArr);
  }

 public:
  Vector() : SequContainer<T>::SequContainer() { v_capacity = 0; }

  Vector(size_type n) : SequContainer<T>::SequContainer(n) { v_capacity = n; }

  Vector(std::initializer_list<value_type> const &items)
      : SequContainer<T>::SequContainer(items) {
    v_capacity = items.size();
  }

  Vector(const Vector &v) : SequContainer<T>::SequContainer(v) {
    v_capacity = v.v_capacity;
  }

  Vector(Vector &&v) {
    SequContainer<T>::move_content(v);
    v_capacity = v.v_capacity;
    v.v_capacity = 0;
  }

  ~Vector() { v_capacity = 0; }

  Vector<T> operator=(Vector &&v) {
    SequContainer<T>::move_content(v);
    v_capacity = v.v_capacity;
    v.v_capacity = 0;
    return this;
  }

  iterator insert(iterator pos, const_reference value) {
    T *newArr;
    T *newPointer = nullptr;
    size_type amount = SequContainer<T>::size();
    size_type newSize;
    if (amount == v_capacity) {
      newSize = amount * 2;
      newArr = new T[newSize];
      v_capacity = newSize;
    } else {
      newSize = amount + 1;
      newArr = new T[newSize];
    }
    SequContainer<T>::set_size(amount + 1);
    for (size_type i = 0, j = 0; i < SequContainer<T>::size(); i++, j++) {
      if (&(SequContainer<T>::get_value(i)) != pos) {
        newArr[i] = SequContainer<T>::get_value(j);
      } else {
        newArr[i] = value;
        newPointer = &newArr[i];
        j--;
      }
    }
    SequContainer<T>::assign_array(newArr);
    return newPointer;
  }

  void reserve(size_type size) {  // Capacity
    if (size > v_capacity) {
      T *newArr = new T[size];
      std::copy(SequContainer<T>::begin(), SequContainer<T>::end(), newArr);
      SequContainer<T>::assign_array(newArr);
      v_capacity = size;
    }
  }

  size_type capacity() { return v_capacity; }

  void shrink_to_fit() {
    size_type currentSize = SequContainer<T>::size();
    T *newArr = new T[currentSize];
    std::copy(SequContainer<T>::begin(), SequContainer<T>::end(), newArr);
    SequContainer<T>::assign_array(newArr);
    v_capacity = currentSize;
  }

  void push_back(const_reference value) {
    size_type current_size = SequContainer<T>::size();
    if (current_size == v_capacity) {
      v_capacity *= 2;
      T *newArr = new T[v_capacity];
      copy_content(this, newArr);
      newArr[current_size] = value;
      SequContainer<T>::assign_array(newArr);
    } else {
      set_value_safe(current_size, value);
    }
    SequContainer<T>::set_size(current_size + 1);
  }

  void swap(Vector &other) {
    T *temp = SequContainer<T>::begin();
    SequContainer<T>::set_pointer(other.begin());
    other.set_pointer(temp);

    size_type current_size = SequContainer<T>::size();
    size_type other_size = other.SequContainer<T>::size();
    other.SequContainer<T>::set_size(current_size);
    SequContainer<T>::set_size(other_size);
    std::swap(v_capacity, other.v_capacity);
  }
};
}  // namespace s21

#endif  // SRC_CONTAINER_VECTOR_H_
