#ifndef SRC_CONTAINER_ARRAY_H_
#define SRC_CONTAINER_ARRAY_H_

#include "sequcontainer.h"

namespace s21 {
    template <class T,  size_t _Size>
    class Array : public SequContainer<T> {
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using size_type = size_t; 

        private:

        public:
        Array() : SequContainer<T>::SequContainer(_Size) {}
        Array(std::initializer_list<value_type> const& items) : SequContainer<T>::SequContainer(items, _Size) {}
        Array(const Array &a) : SequContainer<T>::SequContainer(a) {}
        Array(Array &&a) {
            move_content(a);
        }
        ~Array() {}
        Array<T, _Size> operator=(Array &&a) {
            SequContainer<T>::move_content(a);
            return this;
        }

        void swap(Array &other) {

        }
        void fill(const_reference value) {}

    };
}

#endif  // SRC_CONTAINER_ARRAY_H_
