#include "stack_test.h"

TEST_F(stack_test, push) {
    s21::stack<double> s21_stack;
    std::stack<double> std_stack;
    
    s21_stack.push(*d.begin());
    std_stack.push(*d.begin());

    ASSERT_EQ(s21_stack.size(), std_stack.size());
    ASSERT_EQ(s21_stack.top(), std_stack.top());
}

TEST_F(stack_test, pop) {
    s21::stack<double> s21_stack;
    std::stack<double> std_stack;

    s21_stack.push(d.begin()[0]);
    s21_stack.push(d.begin()[1]);
    std_stack.push(d.begin()[0]);
    std_stack.push(d.begin()[1]);

    s21_stack.pop();
    std_stack.pop();

    ASSERT_EQ(s21_stack.size(), std_stack.size());
    ASSERT_EQ(s21_stack.top(), std_stack.top());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
