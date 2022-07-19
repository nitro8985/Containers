#ifndef SRC_TEST_STACK_H_
#define SRC_TEST_STACK_H_

#include <gtest/gtest.h>
#include <stack>
#include "../lib/s21_stack.h"

class stack_test : public ::testing::Test {
 protected:
    std::initializer_list<double> d = {0.1, 0.2, 0.3};
    std::initializer_list<int> i = {1, 2, 3};
    std::initializer_list<std::string> s = {"first", "second", "third"};
};
#endif  // SRC_TEST_STACK_H_
