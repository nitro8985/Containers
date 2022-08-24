#ifndef SRC_LIB_S21_BASE_QUEUE_H_
#define SRC_LIB_S21_BASE_QUEUE_H_

namespace s21 {
template <typename T>
class BaseQueue {
 public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

 private:
    class BaseQueueNode {
        friend class BaseQueue;
        T* value_ = nullptr;
        BaseQueueNode* prev_ = nullptr;
        BaseQueueNode* next_ = nullptr;
        BaseQueueNode() {
        }

        ~BaseQueueNode() {
            if (value_) {
                delete value_;
                value_ = nullptr;
            }
        }
    };
    BaseQueueNode *node_ = nullptr;
    BaseQueueNode *back_ = nullptr;
    BaseQueueNode *front_ = nullptr;
    size_type *size_ = nullptr;

 public:
    BaseQueue() { }
    explicit BaseQueue(std::initializer_list<value_type> const& items);
    BaseQueue(const BaseQueue& s);
    BaseQueue(BaseQueue&& s);
    ~BaseQueue() { delete_queue(); }

    BaseQueue<T> operator=(BaseQueue&& s);

    bool empty();
    size_type size();

    void push(const_reference value);
    void swap(BaseQueue& other);

 protected:
    const_reference back();
    const_reference front();
    void pop_back();
    void pop_front();

 private:
    void delete_queue();
    void copy(const BaseQueue& s);
};
}  // namespace s21

#include "s21_base_queue.tcc"

#endif  // SRC_LIB_S21_BASE_QUEUE_H_
