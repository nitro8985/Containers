#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

#include "IConttainer.h"

namespace s21 {

    template <typename T>
    class Stack: IConttainer<T> {
     public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using size_type = size_t;

        Stack();
        Stack(std::initializer_list<value_type> const& items) = 0;
        Stack(const Stack& i_container) = 0;
        Stack(const Stack&& i_container) = 0;

        iterator begin() override;
        iterator end() override;
        bool empty() override;
        size_type size() override;
        size_type max_size() override;
        void clear() override;
    };
} // namespace s21

#endif  // SRC_LIB_STACK_H_
