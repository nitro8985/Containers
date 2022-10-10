#include "s21_queue.h"

namespace s21 {

template <typename T>
typename queue<T>::const_reference queue<T>::back() {
    return BaseQueue<T>::back();
}

template <typename T>
typename queue<T>::const_reference queue<T>::front() {
    return BaseQueue<T>::front();
}

template <typename T>
void queue<T>::pop() {
    BaseQueue<T>::pop_front();
}
}  // namespace s21
