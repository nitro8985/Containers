#include "s21_stack.h"

using namespace s21;

template <class T>
stack<T> stack<T>::operator=(stack&& s) {
    delete_stack();
    value_ = s.value_;
    s.value_ = nullptr;
    prev_ = s.prev_;
    s.prev_ = nullptr;
    stack_size_ = s.stack_size_;
    s.stack_size_ = nullptr;

    return *this;
}

template <class T>
stack<T> stack<T>::operator=(stack& s) {
    delete_stack();
    copy_stack(s);
    return *this;
}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const& items) {

}

template <typename T>
stack<T>::stack(const stack& s) {
    copy_stack(s);
}

template <class T>
stack<T>::stack(stack&& s) {
    delete_stack();
    value_ = s.value_;
    s.value_ = nullptr;
    prev_ = s.perv_;
    s.prev_ = nullptr;
    stack_size_ = s.stack_size_;
    s.stack_size_ = nullptr;
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() {
    return *value_;
}

template <typename T>
bool stack<T>::empty() {
    return *stack_size_ == 0;
}

template <typename T>
typename stack<T>::size_type stack<T>::size() {
    return stack_size_ == nullptr ? 0 : *stack_size_;
}

template <typename T>
void stack<T>::push(const_reference value) {
    stack<T> *new_stack = new stack();
    if (value_ != nullptr) {
        new_stack->value_ = new T();
        *(new_stack->value_) = *value_;
    } else {
        new_stack->value_ = nullptr;
        value_ = new T();
    }
    new_stack->prev_ = prev_;
    new_stack->stack_size_ = stack_size_;
    stack_size_ = new size_type(0);
    (*stack_size_)++;
    prev_ = new_stack;
    *value_ = value;
}

template <typename T>
void stack<T>::pop() {
    if (value_ && stack_size_ && size() > 0) {
        delete value_;
        value_ = nullptr;
        (*stack_size_)--;
        stack<T> *prev = prev_;
        *this = *prev_;
        delete prev;
    }
}

template <typename T>
void stack<T>::swap(stack& other) {
    std::swap(prev_, other.prev_);
    std::swap(value_, other.value_);
    std::swap(stack_size_, other.stack_size_);
}

template <typename T>
void stack<T>::delete_stack() {
    while(value_) {
        pop();
    }
    if (stack_size_ && size() == 0) {
        delete stack_size_;
        stack_size_ == nullptr;
    }
}

template <class T>
void stack<T>::copy_stack(const stack& s) {
    value_ = s.value_ ? new T(*s.value_) : nullptr;
    stack_size_ = s.stack_size_ ? new size_type(*s.stack_size_) : nullptr;
    prev_ = s.prev_;
    stack<T>** phead = &prev_;

    for (const stack<T>* st = s.prev_; st; st = st->prev_) {
        stack<T>* temp = new stack();
        temp->value_ = st->value_ ? new T(*st->value_) : nullptr;
        temp->stack_size_ = st->stack_size_ ? new size_type(*st->stack_size_) : nullptr;
        temp->prev_ = st->prev_;
        *phead = temp;
        phead = &temp->prev_;
    }

    *phead = nullptr;
}
