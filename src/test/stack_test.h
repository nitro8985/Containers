#ifndef SRC_TEST_STACK_TEST_H_
#define SRC_TEST_STACK_TEST_H_

#include <gtest/gtest.h>
#include <stack>
#include "base_test.h"

class stack_test : public BaseTest {
 public:
    template <class T>
    void assert_stack(s21::stack<T> s1, std::stack<T> s2) {
        EXPECT_EQ(s1.size(), s2.size());
        EXPECT_EQ(s1.top(), s2.top());
        while (s1.size() != 0 || s2.size() != 0) {
            EXPECT_EQ(s1.top(), s2.top());
            s1.pop();
            s2.pop();
        }
    }
};
#endif  // SRC_TEST_STACK_TEST_H_
