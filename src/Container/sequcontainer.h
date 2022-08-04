#ifndef SRC_CONTAINER_SEQUCONTAINER_H_
#define SRC_CONTAINER_SEQUCONTAINER_H_

#include "container.h"

namespace s21 {
template <typename T>
class SequContainer : public Container<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  size_type cont_size;
  T *arr;

 protected:
  void set_size(const size_type &size) { cont_size = size; }

  void assign_array(const_iterator newArr) {
    if (newArr) {
      if (arr != nullptr) delete[] arr;
      arr = iterator(newArr);
    } else {
      arr = nullptr;
    }
  }

  void set_pointer(T *pointer) { arr = pointer; }

  reference get_value(size_type pos) {
    if (pos < cont_size)
      return arr[pos];
    else
      throw std::out_of_range("Wrong index");
  }

  void set_value(size_type pos, const_reference value) { arr[pos] = value; }
  const_iterator get_pointer() { return arr; }

 public:
  SequContainer() {
    cont_size = 0;
    arr = nullptr;
  }

  SequContainer(size_type n) {
    cont_size = n;
    if (n > 0) {
      arr = new T[n]();
    } else {
      arr = nullptr;
    }
  }

  SequContainer(std::initializer_list<value_type> const &items) {
    cont_size = items.size();
    arr = new value_type[items.size()];
    int i = 0;
    std::copy(items.begin(), items.end(), arr);
  }

  SequContainer(const SequContainer &s) {
    cont_size = s.cont_size;
    arr = new T[cont_size];
    std::copy(s.arr, s.arr + cont_size, arr);
  }

  ~SequContainer() {
    delete[] arr;
    cont_size = 0;
  }

  virtual const_reference front() {  // Element access
    return arr[0];
  }

  virtual const_reference back() { return arr[cont_size - 1]; }

  virtual iterator begin() {  // Iterators
    return &arr[0];
  }

  virtual iterator end() { return arr + cont_size; }

  reference at(size_type pos) {  // Element access
    return get_value(pos);
  }

  reference operator[](size_type pos) { return get_value(pos); }

  iterator data() { return iterator(get_pointer()); }

  bool empty() {
    if (cont_size == 0)  // Capacity
      return true;
    else
      return false;
  }

  size_type size() { return cont_size; }

  size_type max_size() { return std::allocator<value_type>().max_size(); }

  virtual void clear() {  // Modifiers
    if (arr) {
      delete[] arr;
      arr = nullptr;
      cont_size = 0;
    }
  }

  void erase(iterator pos) {
    for (; pos != end() - 1; pos++) {
      *pos = *(pos + 1);
    }
    arr[cont_size - 1] = 0;
    cont_size--;
  }

  virtual void push_back() {}

  virtual void pop_back() {
    arr[cont_size] = 0;
    cont_size--;
  }

  virtual void swap() {}
};
}  // namespace s21

#endif  // SRC_CONTAINER_SEQUCONTAINER_H_