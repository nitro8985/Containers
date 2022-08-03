#ifndef SRC_LIB_S21_QUEUE_H_
#define SRC_LIB_S21_QUEUE_H_

#include "s21_base_queue.h"

namespace s21 {

    template <typename T>
    class queue: public BaseQueue<T> {
     public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;

     public:
        queue(): BaseQueue<T>::BaseQueue() { }
        queue(std::initializer_list<value_type> const& items): BaseQueue<T>::BaseQueue(items) { }
        queue(const queue& s): BaseQueue<T>::BaseQueue(s) { }
        queue(queue&& s): BaseQueue<T>::BaseQueue(std::move(s)) { }
        ~queue() { }

        const_reference back();
        const_reference front();
        void pop();
    };
} // namespace s21

#include "s21_queue.inl"

#endif  // SRC_LIB_S21_QUEUE_H_
