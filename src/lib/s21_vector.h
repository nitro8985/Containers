#ifndef SRC_LIB_S21_VECTOR_H_
#define SRC_LIB_S21_VECTOR_H_

#include <memory>
#include "s21_sequcontainer.h"

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
    void set_size(size_type size) { SequContainer<T>::set_size(size); }

    void copy_content(Vector<T> *vec, T *newArr) {
        std::copy(vec->begin(), vec->end(), newArr);
    }

 public:
    Vector() : SequContainer<T>::SequContainer() { v_capacity = 0; }

    explicit Vector(size_type n) : SequContainer<T>::SequContainer(n) {
        v_capacity = n;
    }

    explicit Vector(std::initializer_list<value_type> const &items)
        : SequContainer<T>::SequContainer(items) {
        v_capacity = items.size();
    }

    Vector(const Vector &v) : SequContainer<T>::SequContainer(v) {
        v_capacity = v.v_capacity;
    }

    Vector(Vector &&v) {
        SequContainer<T>::move_content(&v);
        v_capacity = v.v_capacity;
        v.v_capacity = 0;
    }

    ~Vector() { v_capacity = 0; }

    Vector<T> operator=(Vector &&v) {
        SequContainer<T>::move_content(&v);
        v_capacity = v.v_capacity;
        v.v_capacity = 0;
        return this;
    }

    iterator insert(iterator pos, const_reference value) {
        return emplace(pos, value);
    }

    void reserve(size_type size) {  // Capacity
        if (size > v_capacity) {
            T *newArr = new T[size];
            std::copy(SequContainer<T>::begin(), SequContainer<T>::end(),
                      newArr);
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

    void push_back(const_reference value) { emplace_back(value); }

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

    template <class... Args>
    iterator emplace(const_iterator position, Args &&...args) {
        size_type amount = SequContainer<T>::size();
        T *pointer = nullptr;
        set_size(amount + 1);
        size_type newSize = SequContainer<T>::size();
        T *temp = SequContainer<T>::data();
        if (v_capacity == amount) {
            v_capacity *= 2;
            T *newArr = new T[v_capacity];
            for (size_type i = 0, j = 0; i < newSize; ++i, ++j) {
                if (&temp[i] != position) {
                    newArr[i] = temp[j];
                } else {
                    newArr[i] = T(args...);
                    pointer = &newArr[i];
                    j--;
                }
            }
            SequContainer<T>::assign_array(newArr);
        } else {
            for (size_type i = newSize - 1;; --i) {
                if (&temp[i] == position) {
                    temp[i] = T(args...);
                    break;
                }
                temp[i] = temp[i - 1];
            }
        }
        return pointer;
    }

    template <class... Args>
    void emplace_back(Args &&...args) {
        size_type amount = SequContainer<T>::size();
        if (amount == v_capacity) {
            v_capacity *= 2;
            T *newArr = new T[v_capacity]();
            copy_content(this, newArr);
            newArr[amount] = T(args...);
            SequContainer<T>::assign_array(newArr);
        } else {
            auto *temp = SequContainer<T>::data();
            temp[amount] = T(args...);
        }
        set_size(amount + 1);
    }
};
}  // namespace s21

#endif  // SRC_LIB_S21_VECTOR_H_
