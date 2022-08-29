#ifndef SRC_TEST_MULTISET_TEST_H_
#define SRC_TEST_MULTISET_TEST_H_

#include <gtest/gtest.h>

#include <set>

#include "../lib/s21_multiset.h"
#include "base_test.h"

class multiset_test : public BaseTest {
 public:
    template <typename T>
    void assert_eq_set(s21::s21_multiset<T>& s1, std::multiset<T>& s2) {
        typename s21::s21_multiset<T>::iterator it21 = s1.begin();
        typename std::multiset<T>::iterator it = s2.begin();
        for (; it21 != s1.end() && it != s2.end(); ++it21, ++it) {
            EXPECT_EQ(*it21, *it);
        }
    }
};
#endif  // SRC_TEST_MULTISET_TEST_H_
