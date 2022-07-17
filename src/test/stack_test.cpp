#include "stack_test.h"

TEST(stack, main_test) {
    s21::stack<int> int_stack;
    s21::stack<int> int_i_stack;
    int_i_stack = std::move(int_stack);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
