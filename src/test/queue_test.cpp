#include "queue_test.h"

TEST_F(queue_test, push) {
    s21::queue<double> s21_queue;
    std::queue<double> std_queue;

    s21_queue.push(*d.begin());
    std_queue.push(*d.begin());

    EXPECT_EQ(s21_queue.size(), std_queue.size());
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST_F(queue_test, pop) {
    s21::queue<double> s21_queue;
    std::queue<double> std_queue;

    s21_queue.push(d.begin()[0]);
    s21_queue.push(d.begin()[1]);
    std_queue.push(d.begin()[0]);
    std_queue.push(d.begin()[1]);

    s21_queue.pop();
    std_queue.pop();

    EXPECT_EQ(s21_queue.size(), std_queue.size());
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST_F(queue_test, empty) {
    s21::queue<int> s21_queue;
    std::queue<int> std_queue;

    EXPECT_EQ(s21_queue.size(), std_queue.size());
    EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST_F(queue_test, list) {
    s21::queue<int> s21_queue(i);
    std::queue<int> std_queue(i);

    EXPECT_EQ(s21_queue.size(), std_queue.size());
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    assert_queue(s21_queue, std_queue);
}

TEST_F(queue_test, swap) {
    // подготовка
    s21::queue<double> s21_queue(d);
    s21::queue<double> s21_queue_another({1, 2, 3});
    std::queue<double> std_queue(d);
    std::queue<double> std_queue_another({1, 2, 3});

    // действие
    s21_queue.swap(s21_queue_another);
    std_queue.swap(std_queue_another);

    // проверка
    assert_queue(s21_queue, std_queue);
    assert_queue(s21_queue_another, std_queue_another);
}

TEST_F(queue_test, move_constr) {
    // подготовка
    s21::queue<double> s21_queue(d);
    std::queue<double> std_queue(d);

    // действие
    s21::queue<double> s21_queue_act(std::move(s21_queue));
    std::queue<double> std_queue_act(std::move(std_queue));

    // проверка
    assert_queue(s21_queue_act, std_queue_act);
    ASSERT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST_F(queue_test, move_operator) {
    // подготовка
    s21::queue<double> s21_queue(d);
    std::queue<double> std_queue(d);

    // действие
    s21::queue<double> s21_queue_act = (s21::queue<double>&&) s21_queue;
    std::queue<double> std_queue_act = (std::queue<double>&&) std_queue;

    // проверка
    assert_queue(s21_queue_act, std_queue_act);
    ASSERT_EQ(s21_queue.empty(), std_queue.empty());
}
