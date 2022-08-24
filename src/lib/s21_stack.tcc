#include "s21_stack.h"

namespace s21 {

template <typename T>
typename stack<T>::const_reference stack<T>::top() {
    return BaseQueue<T>::back();
}

template <typename T>
void stack<T>::pop() {
    BaseQueue<T>::pop_back();
}
}  // namespace s21
