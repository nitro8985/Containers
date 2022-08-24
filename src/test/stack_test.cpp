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

TEST_F(stack_test, empty) {
    s21::stack<int> s21_stack;
    std::stack<int> std_stack;

    ASSERT_EQ(s21_stack.size(), std_stack.size());
    ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST_F(stack_test, list) {
    s21::stack<int> s21_stack(i);
    std::stack<int> std_stack(i);

    ASSERT_EQ(s21_stack.size(), std_stack.size());
    ASSERT_EQ(s21_stack.top(), std_stack.top());
    assert_stack(s21_stack, std_stack);
}

TEST_F(stack_test, swap) {
    // подготовка
    s21::stack<double> s21_stack(d);
    s21::stack<double> s21_stack_another({1, 2, 3});
    std::stack<double> std_stack(d);
    std::stack<double> std_stack_another({1, 2, 3});

    // действие
    s21_stack.swap(s21_stack_another);
    std_stack.swap(std_stack_another);

    // проверка
    assert_stack(s21_stack, std_stack);
    assert_stack(s21_stack_another, std_stack_another);
}

TEST_F(stack_test, move_constr) {
    // подготовка
    s21::stack<double> s21_stack(d);
    std::stack<double> std_stack(d);

    // действие
    s21::stack<double> s21_stack_act(std::move(s21_stack));
    std::stack<double> std_stack_act(std::move(std_stack));

    // проверка
    assert_stack(s21_stack_act, std_stack_act);
    ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST_F(stack_test, move_operator) {
    // подготовка
    s21::stack<double> s21_stack(d);
    std::stack<double> std_stack(d);

    // действие
    s21::stack<double> s21_stack_act = (s21::stack<double>&&) s21_stack;
    std::stack<double> std_stack_act = (std::stack<double>&&) std_stack;

    // проверка
    assert_stack(s21_stack_act, std_stack_act);
    ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}
