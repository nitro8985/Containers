#ifndef SRC_TEST_MAP_TEST_H_
#define SRC_TEST_MAP_TEST_H_

#include <gtest/gtest.h>

#include <map>

#include "../lib/s21_map.h"
#include "base_test.h"

class map_test : public BaseTest {
 public:
    template <typename K, typename T>
    void assert_eq_map(s21::s21_map<K, T>& m1, std::map<K, T>& m2) {
        typename s21::s21_map<K, T>::iterator it21 = m1.begin();
        typename std::map<K, T>::iterator it = m2.begin();
        for (; it21 != m1.end() && it != m2.end(); ++it21, ++it) {
            EXPECT_EQ(it21.operator*().first, it.operator*().first);
            EXPECT_EQ(it21.operator*().second, it.operator*().second);
        }
    }
};
#endif  // SRC_TEST_MAP_TEST_H_
