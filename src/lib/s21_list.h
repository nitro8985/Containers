#ifndef SRC_LIB_S21_LIST_H_
#define SRC_LIB_S21_LIST_H_

namespace s21 {
template <class T>
class List {
 public:
  struct Node {
    T value;
    Node* prev;
    Node* next;
  };

  class ListIterator {
   private:
    Node* current_;

   public:
    ListIterator() {current_ = nullptr;}
    Node* const get_current() { return current_; }
    void set_pos(Node* set_pos) { current_ = set_pos; }

    // iterator++
    ListIterator operator++(int) {
      ListIterator tmp = *this;
      current_ = current_->next;
      return tmp;
    }
    // ++iterator
    ListIterator& operator++() {
      current_ = current_->next;
      return *this;
    }

    // iterator--
    ListIterator operator--(int) {
      ListIterator tmp = *this;
      current_ = current_->prev;
      return tmp;
    }

    // --iterator
    ListIterator& operator--() {
      current_ = current_->prev;
      return *this;
    }

    void operator=(Node* other) { current_ = other; }

    ListIterator& operator=(const Node& other) {
      auto it = new ListIterator();
      it.current = other;
      *this = it;
      return *this;
    }

    ListIterator& operator=(Node&& other) {
      current_ = other;
      other = nullptr;
      return *this;
    }

    bool operator!=(const ListIterator& other) {
      return current_ != other.current_;
    }

    bool operator==(const ListIterator& other) {
      return get_current() == other.current_;
    }

    T& operator*() { return current_->value; }

    ~ListIterator() { current_ = nullptr; }
  };

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = const ListIterator;
  using size_type = size_t;

 private:
  size_t l_size_;
  Node *head_, *tail_;

 private:
  void init() {
    head_ = new Node;
    head_->next = head_;
    head_->prev = head_;
    tail_ = head_;
    set_size(0);
  }

  void set_head_value(const T &value) {
    head_->value = value;
    Node* endStub = new Node;
    endStub->next = head_;
    endStub->prev = head_;
    head_->next = endStub;
    head_->prev = endStub;
  }

  void add_element(const T &value) {
    if (0 == size()) {
      set_head_value(value);
    } else {
      Node* newElement = new Node;
      newElement->value = value;
      newElement->prev = tail_;
      newElement->next = tail_->next;
      tail_->next = newElement;
      tail_ = newElement;
      tail_->next->prev = tail_;
    }
    plus_size();
  }

  void destroy_list() {
    while (head_ != tail_) {
      pop_front();
    }
    if (l_size_ == 0) {
      delete tail_;
    } else {
      delete tail_->next;
      delete head_;
    }
  }

  void set_size(size_t new_size) { l_size_ = new_size; }
  void plus_size() { l_size_++; }
  void minus_size() { l_size_--; }

 public:
  size_t size() { return l_size_; }
  bool empty() { return size() == 0; }
  size_type max_size() {
    return std::allocator<s21::List<value_type>::Node>().max_size();
  }

  // Default constructor, creates empty list
  List() { init(); }

  // Parameterized constructor, creates the list of size n
  explicit List(size_type n) {
    init();
    while (n--) {
      add_element();
    }
    set_size(n);
  }

  // Initializer list constructor, creates list initizialized using
  // std::initializer_list
  explicit List(std::initializer_list<value_type> const& items) {
    init();
    for (auto elem : items) push_back(elem);
  }

  // Copy constructor
  List(const List& l) {
    init();
    iterator l_it, l_end;
    l_it = l.head_;
    l_end = l.tail_->next;
    while (l_it != l_end) push_back(*l_it++);
  }

  // Move constructor
  List(List&& l) {
    init();
    std::swap(l_size_, l.l_size_);
    std::swap(head_, l.head_);
    std::swap(tail_, l.tail_);
  }

  // Destructor
  ~List() { destroy_list(); }

  // Assignment operator overload for moving object
  List<T> operator=(List&& l) {
    destroy_list();
    head_ = l.head_;
    tail_ = l.tail_;
    set_size(l.size());
    return *this;
  }

  virtual iterator begin() {
    s21::List<T>::ListIterator obj;
    obj.set_pos(head_);
    return obj;
  }

  virtual iterator end() {
    s21::List<T>::ListIterator obj;
    obj.set_pos(tail_->next);
    return obj;
  }

  // Element access
  const_reference front() { return head_->value; }

  const_reference back() { return tail_->value; }

  iterator insert(iterator pos, const_reference value) {
    if (pos == begin()) {
      push_front(value);
    } else if (pos == end()) {
      push_back(value);
    } else {
      Node* newElement = new Node;
      Node* cur = pos.get_current();
      newElement->value = value;
      cur->prev->next = newElement;
      newElement->prev = cur->prev;
      cur->prev = newElement;
      newElement->next = cur;
      plus_size();
      tail_->next->value = size();
      --pos;
    }
    return pos;
  }

  void push_back(const_reference value) {
    add_element(value);
    tail_->next->value = size();
  }

  void push_front(const_reference value) {
    if (0 == size()) {
      set_head_value(value);
    } else {
      Node* newElement = new Node;
      newElement->value = value;
      newElement->next = head_;
      head_->prev = newElement;
      newElement->prev = head_->prev;
      head_ = newElement;
    }
    plus_size();
    tail_->next->value = size();
  }

  void erase(iterator pos) {
    if (pos == begin()) {
      pop_front();
    } else if (pos != end()) {
      Node* cur = pos.get_current();
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      delete cur;
      minus_size();
      tail_->next->value = size();
    }
  }

  void pop_front() {
    if (!(empty())) {
      if (l_size_ == 1) {
        delete head_->next;
        head_ = tail_;
        set_size(0);
      } else {
        iterator it = begin();
        head_ = head_->next;
        tail_->next->next = head_->next;
        delete it.get_current();
        minus_size();
        tail_->next->value = size();
      }
    }
  }

  void pop_back() {
    if (!(empty())) {
      if (l_size_ == 1) {
        delete head_->next;
        head_ = tail_;
        set_size(0);
      } else {
        iterator it = end();
        --it;
        tail_->prev->next = tail_->next;
        tail_->next->prev = tail_->prev;
        tail_ = tail_->prev;
        delete it.get_current();
        minus_size();
        tail_->next->value = size();
      }
    }
  }

  void merge(List<T>& other) {
    if (&other != this) {
      for (auto it : other) push_back(it);
      sort();
      other.clear();
    }
  }

  void clear() {
    destroy_list();
    init();
  }

  void splice(const_iterator pos, List& other) {
    size_t this_size = size();
    size_t other_size = other.size();
    if (this != &other && this_size && other_size) {
      for (auto it : other) insert(pos, it);
      set_size(this_size + other_size);
      other.clear();
    }
  }

  void reverse() {
    size_t list_size = size();
    if (list_size > 1) {
      iterator it_begin = begin();
      iterator it_end = --end();
      for (size_t i = 0; i < list_size / 2; i++) {
        std::swap(*it_begin, *it_end);
        ++it_begin;
        --it_end;
      }
    }
  }

  void unique() {
    for (iterator it = begin(); it != --end(); ++it) {
      Node* cur = it.get_current();
      if (cur->value == cur->next->value) {
        s21::List<T>::ListIterator del;
        del.set_pos(cur->next);
        erase(del);
      }
    }
  }

  void sort() {
    iterator it = begin();
    size_t l_size = size() - 1;
    for (size_t i = 0; i < l_size; i++) {
      for (size_t j = 0; j < l_size; j++) {
        Node* cur = it.get_current();
        if (cur->value > cur->next->value) {
          cur = it.get_current();
          std::swap(cur->value, cur->next->value);
        }
        ++it;
      }
      it = begin();
    }
  }

  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args) {
    return insert(pos, T(args...));
  }

  template <typename... Args>
  void emplace_back(Args&&... args) {
    add_element(T(args...));
  }

  template <typename... Args>
  void emplace_front(Args&&... args) {
    push_front(T(args...));
  }
};
}  // namespace s21

#endif  // SRC_LIB_S21_LIST_H_
