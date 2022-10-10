#ifndef SRC_LIB_S21_ARRAY_H_
#define SRC_LIB_S21_ARRAY_H_

#include "s21_sequcontainer.h"

namespace s21 {
template <class T, size_t _Size>
class Array : public SequContainer<T> {
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = T *;
    using const_iterator = const T *;
    using size_type = size_t;

 private:
    value_type _A_elems[_Size + 1];

    void copy_content(const Array &other) {
        if (_Size != other.size()) throw std::out_of_range("Out of range!");
        SequContainer<T>::set_size(other.size());
        const T *_first = &other.front();
        const T *_last = _first + other.size();
        std::copy(_first, _last, _A_elems);
    }

 public:
    Array() {
        SequContainer<T>::set_size(_Size);
        for (int i = 0; i < _Size + 1; i++) _A_elems[i] = 0;
    }
    explicit Array(std::initializer_list<value_type> const &items) {
        if (items.size() != _Size) throw std::out_of_range("Out of range!");
        SequContainer<T>::set_size(_Size);
        auto it = items.begin();
        for (int i = 0; i < _Size; i++, it++) {
            _A_elems[i] = *it;
        }
        _A_elems[_Size] = T(0);
    }
    Array(const Array &a) { copy_content(a); }

    Array(Array &&a) { copy_content(a); }

    ~Array() {}

    Array<T, _Size> &operator=(const Array &a) {
        copy_content(a);
        return *this;
    }

    iterator begin() override { return _A_elems; }

    iterator end() override {
        _A_elems[_Size] = 0;
        return &_A_elems[_Size];
    }

    const_reference front() const override { return _A_elems[0]; }

    const_reference back() const override {
        const_iterator it = &front();
        if (_Size > 0)
            it = &front() + _Size - 1;
        return *it;
    }

    reference at(size_type pos) override {
        if (pos >= _Size) throw std::out_of_range("Out of range!");
        return _A_elems[pos];
    }

    reference operator[](size_type pos) override { return _A_elems[pos]; }

    iterator data() override { return _A_elems; }

    size_type max_size() override { return _Size; }

    void swap(Array &other) {
        value_type *_B_elems = other.data();
        for (int i = 0; i < _Size; i++) {
            std::swap(_A_elems[i], _B_elems[i]);
        }
    }
    void fill(const_reference value) {
        for (int i = 0; i < _Size; i++) {
            _A_elems[i] = value;
        }
    }
};
}  // namespace s21

#endif  // SRC_LIB_S21_ARRAY_H_

