#include "set_test.h"

TEST_F(set_test, init_list_constructor) {
    s21::s21_set<int> s21s({6, 2, 4, 56, -1, 33, 25});
    std::set<int> stds({6, 2, 4, 56, -1, 33, 25});
    assert_eq_set(s21s, stds);
}

TEST_F(set_test, ass_operator) {
    s21::s21_set<int> s21s({6, 2, 4, 56, -1, 33, 25});
    s21::s21_set<int> s21s1;
    s21s1 = std::move(s21s);
    ASSERT_TRUE(s21s1.contains(33));
}

TEST_F(set_test, insert) {
    s21::s21_set<int> s21s;
    s21s.insert(3);
    s21s.insert(1);
    s21s.insert(5);
    ASSERT_TRUE(s21s.contains(1));
    ASSERT_EQ(s21s.size(), 3);
}

TEST_F(set_test, erase) {
    s21::s21_set<int> s21s({1, 2, 3, 4, 5});
    s21::s21_set<int>::iterator it21 = s21s.begin();
    ++it21;
    s21s.erase(it21);
    ASSERT_FALSE(s21s.contains(2));
    ASSERT_EQ(s21s.size(), 4);
}

TEST_F(set_test, merge) {
    s21::s21_set<int> s21s({6, 2, 4, 56, -1, 33, 25});
    s21::s21_set<int> s21s1;
    s21s1.insert(3);
    s21s1.insert(1);
    s21s1.insert(5);
    s21s1.insert(56);
    s21s.merge(s21s1);
    ASSERT_TRUE(s21s.contains(5));
    ASSERT_EQ(s21s.size(), 10);
    ASSERT_TRUE(s21s1.empty());
}

TEST_F(set_test, swap) {
    s21::s21_set<int> s21s({6, 2, 4, 56, 33, 25});
    s21::s21_set<int> s21s1({-1, -2, -3, -4});
    s21s.swap(s21s1);

    ASSERT_TRUE(s21s.contains(-2));
    ASSERT_TRUE(s21s1.contains(56));

    ASSERT_EQ(s21s.size(), 4);
    ASSERT_EQ(s21s1.size(), 6);
}

TEST_F(set_test, find) {
    s21::s21_set<int> s21s({6, 2, 4, 56, 33, 25});

    s21::s21_set<int>::iterator pos_2 = s21s.find(2);
    s21::s21_set<int>::iterator pos_25 = s21s.find(25);

    ASSERT_EQ(2, *pos_2);
    ASSERT_EQ(25, *pos_25);
}

TEST_F(set_test, emplace) {
    s21::s21_set<int> s21s({6, 2, 4, 56, -1, 33, 25});
    int a = 7;
    int b = -1024;
    s21s.emplace(a, 35, b, 98);
    ASSERT_TRUE(s21s.contains(b));
    ASSERT_TRUE(s21s.contains(98));
}
