#ifndef SRC_LIB_S21_STACK_H_
#define SRC_LIB_S21_STACK_H_

#include "s21_base_queue.h"

namespace s21 {

    template <typename T>
    class stack: public BaseQueue<T> {
     public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;

     public:
        stack(): BaseQueue<T>::BaseQueue() { }
        stack(std::initializer_list<value_type> const& items): BaseQueue<T>::BaseQueue(items) { }
        stack(const stack& s): BaseQueue<T>::BaseQueue(s) { }
        stack(stack&& s): BaseQueue<T>::BaseQueue(std::move(s)) { }
        ~stack() { }

        const_reference top();
        void pop();
    };
} // namespace s21

#include "s21_stack.inl"

#endif  // SRC_LIB_S21_STACK_H_
