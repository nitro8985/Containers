#ifndef SRC_LIB_S21_STACK_H_
#define SRC_LIB_S21_STACK_H_

#include "IConttainer.h"

namespace s21 {

    template <class T>
    class stack: IConttainer<T> {
     public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;

     public:
        stack() {}
        stack(std::initializer_list<value_type> const& items);
        stack(const stack& s);
        stack(stack&& s);
        ~stack() {
            delete_stack();
        }

        stack<T> operator=(stack&& s);
        stack<T> operator=(stack& s);

        const_reference top();

        bool empty();
        size_type size();

        void push();
        void pop();
        void swap(stack& other);
     private:
      T* value = nullptr;
      stack<T>* prev = nullptr;
      size_type stack_size = 0;

     private:
        void delete_stack();
        void copy_stack(const stack& s);
    };
} // namespace s21

#include "s21_stack.inl"

#endif  // SRC_LIB_S21_STACK_H_
