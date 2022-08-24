#include "s21_base_queue.h"

namespace s21 {

template <typename T>
BaseQueue<T>::BaseQueue(std::initializer_list<value_type> const& items) {
    size_t size = items.size();
    for (const T *t = items.begin(); size > 0 && t < items.end(); t++) {
        push(*t);
    }
}

template <typename T>
BaseQueue<T>::BaseQueue(const BaseQueue& s) {
    copy(s);
}

template <class T>
BaseQueue<T>::BaseQueue(BaseQueue&& s) {
    delete_queue();
    swap(s);
}

template <class T>
BaseQueue<T> BaseQueue<T>::operator=(BaseQueue&& s) {
    delete_queue();
    swap(s);
    return *this;
}

template <typename T>
typename BaseQueue<T>::const_reference BaseQueue<T>::front() {
    const_reference null_result = 0;
    if (front_) {
        if (front_->value_) {
            return *front_->value_;
        }
    }
    return null_result;
}

template <typename T>
typename BaseQueue<T>::const_reference BaseQueue<T>::back() {
    const_reference null_result = 0;
    if (back_) {
        if (back_->value_) {
            return *back_->value_;
        }
    }
    return null_result;
}

template <typename T>
bool BaseQueue<T>::empty() {
    return size_ == nullptr || *size_ == 0;
}

template <typename T>
typename BaseQueue<T>::size_type BaseQueue<T>::size() {
    return size_ == nullptr ? 0 : *size_;
}

template <typename T>
void BaseQueue<T>::push(const_reference value) {
    BaseQueueNode *new_node = new BaseQueueNode();
    new_node->value_ = new T(value);
    if (!size_) {
        size_ = new size_type(1);
        front_ = new_node;
    } else {
        (*size_)++;
        node_->next_ = new_node;
        new_node->prev_ = node_;
    }
    back_ = new_node;
    node_ = new_node;
}

template <typename T>
void BaseQueue<T>:: pop_back() {
    if (node_ && size_) {
        (*size_)--;
        BaseQueueNode *current_node = node_;
        node_ = node_->prev_;
        back_ = node_;
        if (empty()) {
            front_ = nullptr;
        }
        current_node->prev_ = nullptr;
        delete current_node;
    }
}

template <typename T>
void BaseQueue<T>:: pop_front() {
    if (node_ && size_) {
        (*size_)--;
        BaseQueueNode *current_node = front_;
        front_ = current_node->next_;
        if (empty()) {
            back_ = nullptr;
            node_ = nullptr;
        } else {
            front_->prev_ = nullptr;
        }
        current_node->prev_ = nullptr;
        delete current_node;
    }
}

template <typename T>
void BaseQueue<T>::swap(BaseQueue& other) {
    std::swap(node_, other.node_);
    std::swap(front_, other.front_);
    std::swap(front_, other.front_);
    std::swap(size_, other.size_);
}

template <typename T>
void BaseQueue<T>::delete_queue() {
    while (node_) {
        pop_back();
    }
    node_ = nullptr;
    if (size_ && size() < 1) {
        delete size_;
        size_ = nullptr;
    }
}

template <class T>
void BaseQueue<T>::copy(const BaseQueue& s) {
    if (node_ == nullptr) {
        node_ = new BaseQueueNode();
    }
    node_->value_ = s.node_->value_ ? new T(*s.node_->value_) : nullptr;
    size_ = s.size_ ? new size_type(*s.size_) : nullptr;
    back_ = node_;

    BaseQueueNode* previous_node = s.node_->prev_;
    BaseQueueNode* current_node = node_;
    while (previous_node) {
        BaseQueueNode* temp = new BaseQueueNode();
        temp->value_ = new T(*previous_node->value_);
        temp->next_ = current_node;
        temp->prev_ = current_node->prev_;
        current_node->prev_ = temp;
        current_node = temp;
        previous_node = previous_node->prev_;
    }
    front_ = current_node;
}
}  // namespace s21
