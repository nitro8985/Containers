#ifndef SRC_BASE_TEST_H_
#define SRC_BASE_TEST_H_

#include <gtest/gtest.h>
#include <stack>

class BaseTest : public ::testing::Test {
   protected:
    std::initializer_list<double> d = {0.1, 0.2, 0.3, 0.4};
    std::initializer_list<int> i = {1, 2, 3, 4};
    std::initializer_list<std::string> s = {"first", "second", "third"};
};
#endif  // SRC_BASE_TEST_H_
