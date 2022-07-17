#include "s21_stack.h"

using namespace s21;

template <class T>
stack<T> stack<T>::operator=(stack&& s) {
    delete_stack();
    // std::swap(*this, s);
    value = s.value;
    s.value = nullptr;
    prev = s.prev;
    s.prev = nullptr;
    stack_size = s.stack_size;
    s.stack_size = 0;

    return *this;
}

template <class T>
stack<T> stack<T>::operator=(stack& s) {
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
    
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() {}

template <typename T>
bool stack<T>::empty() {
    return true;
}

template <typename T>
typename stack<T>::size_type stack<T>::size() {
    return stack_size;
}

template <typename T>
void stack<T>::push() {
    
}

template <typename T>
void stack<T>::pop() {
    if (value && stack_size > 0) {
        delete value;
        value = nullptr;
        stack<T> *head = this;
        *this = *prev;
        delete head;
        stack_size--;
    }
}

template <typename T>
void stack<T>::swap(stack& other) {
    
}

template <typename T>
void stack<T>::delete_stack() {
    while(value) {
        pop();
    }
}

template <class T>
void stack<T>::copy_stack(const stack& s) {
    value = s.value ? new T(*s.value) : nullptr;
    prev = s.prev;
    stack<T>** phead = &prev;

    for (const stack<T>* st = s.prev; st; st = st->prev) {
        stack<T>* temp = new stack();
        temp->value = new T(*st->value);
        temp->prev = st->prev;
        temp->stack_size = st->stack_size;
        *phead = temp;
        phead = &temp->prev;
    }

    *phead = nullptr;
}
