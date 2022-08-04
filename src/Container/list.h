#ifndef SRC_CONTAINER_LIST_H_
#define SRC_CONTAINER_LIST_H_

#include "sequcontainer.h"

namespace s21 {
    template <class T>
    class List : public SequContainer<T> {
        public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using size_type = size_t;
        struct Node {
            T* value;
            Node* prev;
            Node* next;
        };

        private:
        Node* head, *tail;

        private:
        void add_element() {
            Node *temp = new Node;
            temp->value = nullptr;
            temp->prev = tail;
            tail->next = temp;
            temp->next = nullptr;
            tail = temp;
        }

        public:
        List() : SequContainer<T>::SequContainer() {
            tail->value = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
            head = tail;
        }
        List(size_type n) : SequContainer<T>::SequContainer(n) {
            head->value = nullptr;
            head->prev = nullptr;
            head->next = tail;
            tail->value = nullptr;
            tail->next = nullptr;
            tail->prev = head;

            while (n--) {
                add_element();
            }
        }
        List(std::initializer_list<value_type> const& items) : SequContainer<T>::SequContainer(items) {

        }

        List(const List& l) : SequContainer<T>::SequContainer(l) {

        }
        List(List&& l) : SequContainer<T>::SequContainer(l) {

        }
        ~List() {

        }
        // const_reference front() override {  // Element access
        // }
        // const_reference back() override {
        // }
        // iterator insert(iterator pos, const_reference value) {}

        // void push_back(const_reference value) override {
            
        // }

        void push_front(const_reference value) {

        }
        void pop_front() {

        }
        void merge() {}
        void splice() {}
        void reverse() {}
        void unique() {}
        void sort() {}

    };
}

#endif  // SRC_CONTAINER_LIST_H_