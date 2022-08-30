#ifndef SRC_TEST_QUEUE_TEST_H_
#define SRC_TEST_QUEUE_TEST_H_

#include <gtest/gtest.h>

#include <queue>

#include "base_test.h"

class queue_test : public BaseTest {
 public:
    template <class T>
    void assert_queue(s21::queue<T> s1, std::queue<T> s2) {
        EXPECT_EQ(s1.size(), s2.size());
        EXPECT_EQ(s1.back(), s2.back());
        EXPECT_EQ(s1.front(), s2.front());
        while (s1.size() != 0 || s2.size() != 0) {
            EXPECT_EQ(s1.front(), s2.front());
            EXPECT_EQ(s1.back(), s2.back());
            s1.pop();
            s2.pop();
        }
    }
};
#endif  // SRC_TEST_QUEUE_TEST_H_
