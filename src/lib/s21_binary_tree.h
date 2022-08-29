#ifndef SRC_LIB_S21_BINARY_TREE_H_
#define SRC_LIB_S21_BINARY_TREE_H_
#include <iostream>

namespace s21 {
template <typename T>
class s21_binary_tree {
 private:
    class node {
     public:
        T key_;
        node *left_;
        node *right_;
        node *parent_;
        node() : left_(nullptr), right_(nullptr), parent_(nullptr) {}
        explicit node(T key)
            : key_(key), left_(nullptr), right_(nullptr), parent_(nullptr) {}
        bool operator==(const node &other) { return key_ == other.key_; }
        bool operator!=(const node &other) { return !(*this == other); }
        node &operator=(const node &other) {
            if (*this != other) {
                key_ = other.key_;
                left_ = other.left_;
                right_ = other.right_;
                parent_ = other.parent_;
            }
            return *this;
        }
        node &operator=(node &&other) {
            if (*this != other) {
                key_ = other.key_;
                left_ = other.left_;
                right_ = other.right_;
                parent_ = other.parent_;
                other.left_ = nullptr;
                other.right_ = nullptr;
                other.parent_ = nullptr;
            }
            return *this;
        }
    };

 public:
    class iterator {
     public:
        node *p_;

     protected:
        s21_binary_tree *tree_;
        bool allocd_ = false;

     public:
        iterator() : p_(nullptr), tree_(nullptr) {}
        iterator(node *a, s21_binary_tree *tree) : p_(a), tree_(tree) {}
        iterator(const iterator &a) { *this = a; }
        iterator(iterator &&a) { *this = std::move(a); }
        ~iterator() {
            if (allocd_) {
                delete p_;
            }
        }

        bool operator==(const iterator &a) { return p_ == a.p_; }
        bool operator!=(const iterator &a) { return !(*this == a); }
        iterator &operator=(const iterator &a) {
            p_ = a.p_;
            tree_ = a.tree_;
            return *this;
        }

        iterator &operator=(iterator &&a) {
            p_ = std::move(a.p_);
            tree_ = std::move(a.tree_);
            allocd_ = a.allocd_;
            a.p_ = nullptr;
            a.tree_ = nullptr;
            return *this;
        }

        T &operator*() {
            if (p_ == nullptr) {
                p_ = new node;
                allocd_ = true;
            }
            return p_->key_;
        }

        iterator &operator++() {
            node *p;
            if (p_ == nullptr) {
                p_ = tree_->root_;
                if (p_ == nullptr) {
                    throw std::out_of_range("Tree is empty");
                }
                while (p_->left_) {
                    p_ = p_->left_;
                }
            } else if (p_->right_ != nullptr) {
                p_ = p_->right_;
                while (p_->left_ != nullptr) {
                    p_ = p_->left_;
                }
            } else {
                p = p_->parent_;
                while (p != nullptr && p_ == p->right_) {
                    p_ = p;
                    p = p->parent_;
                }
                p_ = p;
            }
            p = nullptr;
            return *this;
        }

        iterator &operator++(int a) { return ++*this; }

        iterator &operator--() {
            node *p;
            if (p_ == nullptr) {
                p_ = tree_->root_;
                if (p_ == nullptr) {
                    throw std::out_of_range("Tree is empty");
                }
                while (p_->right_) {
                    p_ = p_->right_;
                }
            } else if (p_->left_ != nullptr) {
                p_ = p_->left_;
                while (p_->right_ != nullptr) {
                    p_ = p_->right_;
                }
            } else {
                p = p_->parent_;
                while (p != nullptr && p_ == p->left_) {
                    p_ = p;
                    p = p->parent_;
                }
                p_ = p;
            }
            p = nullptr;
            return *this;
        }

        iterator &operator--(int a) { return --*this; }
    };

    class const_iterator : public iterator {
        const_iterator() : iterator() {}
        const_iterator(const const_iterator &other) : iterator(other) {}
        const_iterator(const_iterator &&other) : iterator(std::move(other)) {}
        ~const_iterator() {}
        const T &operator*() { return this.p_->key_; }
    };

 protected:
    s21_binary_tree();
    explicit s21_binary_tree(T key);
    explicit s21_binary_tree(std::initializer_list<T> const &items);
    s21_binary_tree(const s21_binary_tree<T> &other);
    s21_binary_tree(s21_binary_tree<T> &&other);
    ~s21_binary_tree();

    node *search(T key);
    void delete_node(T key);
    node *find_min();
    node *find_max();
    void copy_tree(node *other);
    void copy_tree(const s21_binary_tree &other);
    iterator add_node(T key);
    iterator find_node(T key);
    bool compare(node *first, node *second);

 public:
    iterator begin();
    iterator end();
    size_t size();
    size_t max_size();
    void erase(iterator pos);
    void clear();
    bool empty();
    void swap(s21_binary_tree<T> &other);
    bool operator==(const s21_binary_tree<T> &other);
    bool operator!=(const s21_binary_tree<T> &other);
    s21_binary_tree<T> &operator=(const s21_binary_tree<T> &other);
    s21_binary_tree<T> &operator=(s21_binary_tree<T> &&other);

 private:
    void clear(node *leaf);
    iterator add_node(T key, node *leaf);
    node *search(T key, node *leaf);
    node *find_min(node *leaf);
    node *find_max(node *leaf);
    void hang_up_right_subtree(node *curr, node *parent);
    void hang_up_left_subtree(node *curr, node *parent);

    node *root_;
    size_t size_;
};

template <typename T>
s21_binary_tree<T>::s21_binary_tree() : root_(nullptr), size_(0) {}

template <typename T>
s21_binary_tree<T>::s21_binary_tree(T key) : size_(0) {
    root_ = new node(key);
    size_++;
}

template <typename T>
s21_binary_tree<T>::s21_binary_tree(std::initializer_list<T> const &items)
    : root_(nullptr), size_(0) {
    if (items.size()) {
        for (auto i = 0; i < items.size(); i++) {
            add_node(items.begin()[i]);
        }
    }
}

template <typename T>
s21_binary_tree<T>::s21_binary_tree(const s21_binary_tree &other)
    : root_(nullptr), size_(0) {
    *this = other;
}

template <typename T>
s21_binary_tree<T>::s21_binary_tree(s21_binary_tree &&other) {
    *this = std::move(other);
}

template <typename T>
s21_binary_tree<T>::~s21_binary_tree() {
    if (root_) {
        clear();
    }
}

template <typename T>
void s21_binary_tree<T>::clear(node *leaf) {
    if (leaf != nullptr) {
        clear(leaf->left_);
        clear(leaf->right_);
    }
    delete leaf;
}

template <typename T>
void s21_binary_tree<T>::clear() {
    clear(root_);
    root_ = nullptr;
    size_ = 0;
}

template <typename T>
bool s21_binary_tree<T>::empty() {
    return root_ == nullptr;
}

template <typename T>
void s21_binary_tree<T>::swap(s21_binary_tree<T> &other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
}

template <typename T>
void s21_binary_tree<T>::erase(typename s21_binary_tree<T>::iterator pos) {
    if (search(*pos)) {
        delete_node(pos.p_->key_);
        size_--;
    }
}

template <typename T>
typename s21_binary_tree<T>::iterator s21_binary_tree<T>::add_node(T key,
                                                                   node *leaf) {
    if (key < leaf->key_) {
        if (leaf->left_ != nullptr) {
            add_node(key, leaf->left_);
        } else {
            leaf->left_ = new node(key);
            leaf->left_->parent_ = leaf;
        }
    } else {
        if (leaf->right_ != nullptr) {
            add_node(key, leaf->right_);
        } else {
            leaf->right_ = new node(key);
            leaf->right_->parent_ = leaf;
        }
    }
    return find_node(key);
}

template <typename T>
typename s21_binary_tree<T>::iterator s21_binary_tree<T>::add_node(T key) {
    if (root_) {
        add_node(key, root_);
        size_++;
    } else {
        root_ = new node(key);
        size_++;
    }
    return find_node(key);
}

template <typename T>
typename s21_binary_tree<T>::iterator s21_binary_tree<T>::find_node(T key) {
    iterator ret(search(key), this);
    return ret;
}

template <typename T>
typename s21_binary_tree<T>::node *s21_binary_tree<T>::search(T key,
                                                              node *leaf) {
    if (leaf == nullptr || key == leaf->key_) {
        return leaf;
    }
    if (key < leaf->key_) {
        return search(key, leaf->left_);
    }
    return search(key, leaf->right_);
}

template <typename T>
typename s21_binary_tree<T>::node *s21_binary_tree<T>::search(T key) {
    return search(key, root_);
}

template <typename T>
void s21_binary_tree<T>::delete_node(T key) {
    node *curr = search(key);
    if (!curr) return;
    node *parent = curr->parent_;
    if (curr->left_ == nullptr && curr->right_ == nullptr) {  // no children
        if (parent && (parent->left_ == curr)) {
            parent->left_ = nullptr;
        }
        if (parent && (parent->right_ == curr)) {
            parent->right_ = nullptr;
        }
        if (curr == root_) {
            delete root_;
            root_ = nullptr;
            return;
        }
        delete curr;
        curr = nullptr;
        return;
    }
    if (curr->left_ == nullptr) {  // right child only
        hang_up_right_subtree(curr, parent);
        if (curr == root_) {
            root_ = root_->right_;
            return;
        }
        delete curr;
        curr = nullptr;
        return;
    }
    if (curr->right_ == nullptr) {  // left child only
        hang_up_left_subtree(curr, parent);
        if (curr == root_) {
            root_ = root_->left_;
            return;
        }
        delete curr;
        curr = nullptr;
        return;
    }
    node *replace = curr->right_;  // both children
    while (replace->left_) {
        replace = replace->left_;
    }
    T replace_key = replace->key_;
    delete_node(replace_key);
    curr->key_ = replace_key;
}

template <typename T>
void s21_binary_tree<T>::hang_up_right_subtree(node *curr, node *parent) {
    if (parent && (parent->left_ == curr)) {
        parent->left_ = curr->right_;
        parent->left_->parent_ = parent;
    }
    if (curr->parent_ && (parent->right_ == curr)) {
        parent->right_ = curr->right_;
        parent->right_->parent_ = parent;
    }
    if (!parent) {
        curr->right_->parent_ = nullptr;
    }
}

template <typename T>
void s21_binary_tree<T>::hang_up_left_subtree(node *curr, node *parent) {
    if (parent && (parent->left_ == curr)) {
        parent->left_ = curr->left_;
    }
    if (parent && (parent->right_ == curr)) {
        parent->right_ = curr->left_;
    }
    if (!parent) {
        curr->left_->parent_ = nullptr;
    }
}

template <typename T>
typename s21_binary_tree<T>::node *s21_binary_tree<T>::find_min() {
    return find_min(root_);
}

template <typename T>
typename s21_binary_tree<T>::node *s21_binary_tree<T>::find_min(node *leaf) {
    if (leaf) {
        while (leaf->left_) {
            leaf = leaf->left_;
        }
    }
    return leaf;
}

template <typename T>
typename s21_binary_tree<T>::node *s21_binary_tree<T>::find_max() {
    return find_max(root_);
}

template <typename T>
typename s21_binary_tree<T>::node *s21_binary_tree<T>::find_max(node *leaf) {
    if (leaf) {
        while (leaf->right_) {
            leaf = leaf->right_;
        }
    }
    return leaf;
}

template <typename T>
bool s21_binary_tree<T>::compare(node *first, node *second) {
    if (first && second) {
        if (*first == *second) {
            compare(first->left_, second->left_);
            compare(first->right_, second->right_);
        } else {
            return false;
        }
        return true;
    }
    return false;
}

template <typename T>
void s21_binary_tree<T>::copy_tree(node *other) {
    if (other) {
        add_node(other->key_);
        copy_tree(other->left_);
        copy_tree(other->right_);
    }
}

template <typename T>
void s21_binary_tree<T>::copy_tree(const s21_binary_tree &other) {
    if (*this != other) {
        // root_ = other.root_;
        copy_tree(other.root_);
    }
}

template <typename T>
typename s21_binary_tree<T>::iterator s21_binary_tree<T>::begin() {
    if (root_ != nullptr) {
        iterator res(find_min(), this);
        return res;
    } else {
        iterator fu(nullptr, this);
        return fu;
    }
}

template <typename T>
typename s21_binary_tree<T>::iterator s21_binary_tree<T>::end() {
    if (root_ != nullptr) {
        iterator res(find_max()->right_, this);
        return res;
    } else {
        iterator fu(nullptr, this);
        return fu;
    }
}

template <typename T>
size_t s21_binary_tree<T>::size() {
    return size_;
}

template <typename T>
size_t s21_binary_tree<T>::max_size() {
    return std::allocator<
               std::pair<typename s21_binary_tree<T>::node, size_t>>()
        .max_size();
}

template <typename T>
bool s21_binary_tree<T>::operator==(const s21_binary_tree<T> &other) {
    if (size_ == other.size_) {
        return compare(root_, other.root_);
    } else {
        return false;
    }
}

template <typename T>
bool s21_binary_tree<T>::operator!=(const s21_binary_tree<T> &other) {
    return !(*this == other);
}

template <typename T>
s21_binary_tree<T> &s21_binary_tree<T>::operator=(
    const s21_binary_tree<T> &other) {
    if (*this != other) {
        clear();
        copy_tree(other);
    }
    return *this;
}

template <typename T>
s21_binary_tree<T> &s21_binary_tree<T>::operator=(s21_binary_tree<T> &&other) {
    if (*this != other) {
        swap(other);
        other.clear();
    }
    return *this;
}

}  // namespace s21

#endif  // SRC_LIB_S21_BINARY_TREE_H_
