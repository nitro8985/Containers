#ifndef SRC_LIB_S21_SEQUCONTAINER_H_
#define SRC_LIB_S21_SEQUCONTAINER_H_

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
    void move_content(SequContainer *s) {
        const_iterator pointer = s->get_pointer();
        assign_array(pointer);
        s->assign_array(nullptr);
        set_size(s->size());
        s->set_size(0);
    }

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
            return arr[pos];
    }

    iterator get_pointer() { return arr; }

 public:
    SequContainer() {
        cont_size = 0;
        arr = nullptr;
    }

    explicit SequContainer(size_type n) {
        cont_size = n;
        if (n > 0) {
            arr = new T[n + 1]();
        } else {
            arr = nullptr;
        }
    }

    explicit SequContainer(std::initializer_list<value_type> const &items) {
        cont_size = items.size();
        arr = new T[cont_size + 1]();
        std::copy(items.begin(), items.end(), arr);
    }

    SequContainer(const SequContainer &s) {
        cont_size = s.cont_size;
        arr = new T[cont_size + 1];
        std::copy(s.arr, s.arr + cont_size, arr);
    }

    ~SequContainer() { delete[] arr; }

    virtual const_reference front() const {  // Element access
        return arr[0];
    }

    virtual const_reference back() const { return arr[cont_size - 1]; }

    virtual iterator begin() {  // Iterators
        return &arr[0];
    }

    virtual iterator end() { return arr + cont_size; }

    virtual reference at(size_type pos) { return get_value(pos); }

    virtual reference operator[](size_type pos) { return get_value(pos); }

    virtual iterator data() { return iterator(get_pointer()); }

  bool empty() {
    if (cont_size == 0)
      return true;
    else
      return false;
  }

    size_type size() const { return cont_size; }

    virtual size_type max_size() {
        return std::allocator<value_type>().max_size();
    }

    virtual void clear() {
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
        --cont_size;
    }

    virtual void pop_back() {
        arr[cont_size] = value_type();
        --cont_size;
    }

    virtual SequContainer<T> operator=(SequContainer<T> &&s) {
        move_content(&s);
        cont_size = s.size();
        arr = s.get_pointer();
        return *this;
    }
};
}  // namespace s21

#endif  // SRC_LIB_S21_SEQUCONTAINER_H_
