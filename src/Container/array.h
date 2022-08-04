#ifndef SRC_CONTAINER_ARRAY_H_
#define SRC_CONTAINER_ARRAY_H_

#include "sequcontainer.h"

namespace s21 {
    template <class T, int n>
    class Array : public SequContainer<T> {
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using size_type = size_t; 

        private:
        void move_content(Array &a) {
            T* pointer = v.SequContainer<T>::get_pointer();

            SequContainer<T>::set_new_pointer(&pointer);
            v.SequContainer<T>::set_new_pointer(nullptr);
            
            SequContainer<T>::set_new_size(v.SequContainer<T>::size());
            v.SequContainer<T>::set_new_size(0);
        }

        public:
        Array() : SequContainer<T>::SequContainer() {}
        Array(std::initializer_list<value_type> const& items) : SequContainer<T>::SequContainer(items) {}
        Array(const Array &a) : SequContainer<T>::SequContainer(a) {}
        Array(Array &&a) {
            move_content(a);
        }
        ~Array() {}
        operator=(Array &&a) {
            move_content(a);
        }

        void swap(Array &other) {

        }
        void fill(const_reference value) {}

    };
}

#endif  // SRC_CONTAINER_ARRAY_H_
