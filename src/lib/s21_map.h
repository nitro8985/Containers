#ifndef SRC_LIB_S21_MAP_H_
#define SRC_LIB_S21_MAP_H_

#include "s21_binary_tree.h"

namespace s21 {

template <typename Key, typename T,
          typename _tree = s21_binary_tree<std::pair<Key, T>>>
class s21_map : public _tree {
 public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = typename _tree::iterator;
    using const_iterator = typename _tree::const_iterator;
    using size_type = size_t;

    s21_map() : _tree::s21_binary_tree() {}
    explicit s21_map(std::initializer_list<value_type> const &items)
        : _tree::s21_binary_tree(items) {}
    s21_map(const s21_map &m) { *this = m; }
    s21_map(s21_map &&m) : _tree::s21_binary_tree(std::move(m)) {}
    ~s21_map() {}

    s21_map &operator=(const s21_map &m);
    s21_map &operator=(s21_map &&m);
    T &at(const Key &key);
    T &operator[](const Key &key);

    std::pair<iterator, bool> insert(const value_type &value);
    std::pair<iterator, bool> insert(
        const Key &key, const T &obj);  // STL MAP DOESN'T DO THAT!!!

    std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
    template <typename... Args>
    std::pair<iterator, bool> emplace(Args &&...args);

    void merge(s21_map &other);
    bool contains(const Key &key);

 private:
    iterator find_key(const Key &key);
};

template <typename Key, typename T, typename _tree>
s21_map<Key, T, _tree> &s21_map<Key, T, _tree>::operator=(
    const s21_map<Key, T, _tree> &m) {
    if (*this != m) {
        _tree::clear();
        _tree::copy_tree(m);
    }
    return *this;
}

template <typename Key, typename T, typename _tree>
s21_map<Key, T, _tree> &s21_map<Key, T, _tree>::operator=(
    s21_map<Key, T, _tree> &&m) {
    if (*this != m) {
        _tree::swap(m);
        m.clear();
    }
    return *this;
}

template <typename Key, typename T, typename _tree>
T &s21_map<Key, T, _tree>::at(const Key &key) {
    T value;
    bool flag = true;
    for (iterator i = _tree::begin(); i != _tree::end(); ++i) {
        if ((*i).first == key) {
            value = (*i).second;
            flag = false;
        }
    }
    if (flag) {
        throw std::out_of_range("map::at");
    }
    return _tree::search(std::pair<Key, T>{key, value})->key_.second;
}

template <typename Key, typename T, typename _tree>
T &s21_map<Key, T, _tree>::operator[](const Key &key) {
    if (!contains(key)) {
        insert({key, 0});
    }
    return at(key);
}

template <typename Key, typename T, typename _tree>
void s21_map<Key, T, _tree>::merge(s21_map &other) {
    for (iterator i = _tree::begin(); i != _tree::end(); ++i) {
        if (other.contains((*i).first)) {
            other.delete_node(
                std::pair<Key, T>{(*i).first, other.at((*i).first)});
        }
    }
    _tree::copy_tree(other);
    other.clear();
}

template <typename Key, typename T, typename _tree>
bool s21_map<Key, T, _tree>::contains(const Key &key) {
    for (iterator i = _tree::begin(); i != _tree::end(); ++i) {
        if ((*i).first == key) {
            return true;
        }
    }
    return false;
}

template <typename Key, typename T, typename _tree>
typename s21_map<Key, T, _tree>::iterator s21_map<Key, T, _tree>::find_key(
    const Key &key) {
    iterator i;
    for (i = _tree::begin(); i != _tree::end(); ++i) {
        if ((*i).first == key) {
            return i;
        }
    }
    return i;
}

template <typename Key, typename T, typename _tree>
std::pair<typename s21_map<Key, T, _tree>::iterator, bool>
s21_map<Key, T, _tree>::insert(const value_type &value) {
    if (contains(value.first)) {
        return std::pair<typename s21_map<Key, T>::iterator, bool>{
            find_key(value.first), false};
    }
    iterator i = _tree::add_node(value);
    return std::pair<typename s21_map<Key, T>::iterator, bool>{
        i, contains(value.first)};
}

template <typename Key, typename T, typename _tree>
std::pair<typename s21_map<Key, T, _tree>::iterator, bool>
s21_map<Key, T, _tree>::insert(const Key &key, const T &obj) {
    return insert(std::pair<Key, T>(key, obj));
}

template <typename Key, typename T, typename _tree>
std::pair<typename s21_map<Key, T, _tree>::iterator, bool>
s21_map<Key, T, _tree>::insert_or_assign(const Key &key, const T &obj) {
    bool ret = false;
    if (contains(key)) {
        at(key) = obj;
        return std::pair<typename s21_map<Key, T>::iterator, bool>{
            find_key(key), ret};
    }
    iterator i = _tree::add_node(std::pair<Key, T>{key, obj});
    if (contains(key)) {
        ret = true;
    }
    return std::pair<typename s21_map<Key, T>::iterator, bool>{i, ret};
}

template <typename Key, typename T, typename _tree>
template <typename... Args>
std::pair<typename s21_map<Key, T, _tree>::iterator, bool>
s21_map<Key, T, _tree>::emplace(Args &&...args) {
    s21_map<Key, T> tmp({args...});
    std::pair<iterator, bool> ret;
    for (iterator i = tmp.begin(); i != tmp.end(); ++i) {
        ret = insert(*i);
    }
    return ret;
}
}  // namespace s21

#endif  // SRC_LIB_S21_MAP_H_
