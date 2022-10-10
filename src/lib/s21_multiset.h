#ifndef SRC_LIB_S21_MULTISET_H_
#define SRC_LIB_S21_MULTISET_H_

#include "s21_binary_tree.h"

namespace s21 {

template <typename T, typename _tree = s21_binary_tree<T>>
class s21_multiset : public _tree {
 public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = typename _tree::iterator;
    using const_iterator = typename _tree::const_iterator;
    using size_type = size_t;

    s21_multiset() : s21_binary_tree<T>::s21_binary_tree() {}
    explicit s21_multiset(std::initializer_list<value_type> const &items)
        : _tree::s21_binary_tree(items) {}
    s21_multiset(const s21_multiset &s) { *this = s; }
    explicit s21_multiset(s21_multiset &&s) { *this = std::move(s); }
    ~s21_multiset() {}

    s21_multiset &operator=(const s21_multiset &s);
    s21_multiset &operator=(s21_multiset &&s);
    std::pair<iterator, bool> insert(const value_type &value);
    void merge(s21_multiset &other);
    iterator find(const value_type &key);
    bool contains(const value_type &key);
    template <typename... Args>
    std::pair<iterator, bool> emplace(Args &&...args);
    std::pair<iterator, iterator> equal_range(const value_type &key);
    iterator lower_bound(const value_type &key);
    iterator upper_bound(const value_type &key);
};

template <typename T, typename _tree>
s21_multiset<T, _tree> &s21_multiset<T, _tree>::operator=(
    const s21_multiset<T, _tree> &s) {
    if (*this != s) {
        _tree::clear();
        _tree::copy_tree(s);
    }
    return *this;
}

template <typename T, typename _tree>
s21_multiset<T, _tree> &s21_multiset<T, _tree>::operator=(
    s21_multiset<T, _tree> &&s) {
    if (*this != s) {
        _tree::swap(s);
        s.clear();
    }
    return *this;
}

template <typename T, typename _tree>
typename _tree::iterator s21_multiset<T, _tree>::find(const value_type &key) {
    iterator i;
    for (i = _tree::begin(); i != _tree::end(); ++i) {
        if (*i == key) {
            return i;
        }
    }
    return i;
}

template <typename T, typename _tree>
bool s21_multiset<T, _tree>::contains(const value_type &key) {
    for (iterator i = _tree::begin(); i != _tree::end(); ++i) {
        if ((*i) == key) {
            return true;
        }
    }
    return false;
}

template <typename T, typename _tree>
std::pair<typename s21_multiset<T, _tree>::iterator, bool>
s21_multiset<T, _tree>::insert(const value_type &value) {
    iterator i = _tree::add_node(value);
    return std::pair<typename s21_multiset<T, _tree>::iterator, bool>{
        i, contains(value)};
}

template <typename T, typename _tree>
void s21_multiset<T, _tree>::merge(s21_multiset<T, _tree> &other) {
    _tree::copy_tree(other);
    other.clear();
}

template <typename T, typename _tree>
template <typename... Args>
std::pair<typename s21_multiset<T, _tree>::iterator, bool>
s21_multiset<T, _tree>::emplace(Args &&...args) {
    s21_multiset<T, _tree> tmp({args...});
    std::pair<iterator, bool> ret;
    for (iterator i = tmp.begin(); i != tmp.end(); ++i) {
        ret = insert(*i);
    }
    return ret;
}

template <typename T, typename _tree>
std::pair<typename s21_multiset<T, _tree>::iterator,
          typename s21_multiset<T, _tree>::iterator>
s21_multiset<T, _tree>::equal_range(const value_type &key) {
    iterator start;
    iterator end;
    for (iterator i = _tree::begin(); i != _tree::end(); ++i) {
        if (*i == key) {
            start = i;
            while (*i == key) {
                ++i;
            }
            --i;
            end = i;
            break;
        }
    }
    return std::pair<iterator, iterator>(start, end);
}

template <typename T, typename _tree>
typename _tree::iterator s21_multiset<T, _tree>::lower_bound(
    const value_type &key) {
    iterator i;
    for (i = _tree::begin(); i != _tree::end(); ++i) {
        if (*i >= key) {
            return i;
        }
    }
    return i;
}

template <typename T, typename _tree>
typename _tree::iterator s21_multiset<T, _tree>::upper_bound(
    const value_type &key) {
    iterator i;
    for (i = _tree::begin(); i != _tree::end(); ++i) {
        if (*i > key) {
            return i;
        }
    }
    return i;
}
}  // namespace s21

#endif  // SRC_LIB_S21_MULTISET_H_
