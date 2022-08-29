#include "map_test.h"

TEST_F(map_test, init_list_constructor) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    assert_eq_map(s21m, stdm);
}

TEST_F(map_test, moveass_insert_empty_contains) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    s21::s21_map<int, double> s21m1;
    s21m1 = std::move(s21m);
    s21m1.insert({15, 85});
    stdm.insert({15, 85});
    assert_eq_map(s21m1, stdm);
    ASSERT_TRUE(s21m.empty());
    ASSERT_FALSE(s21m.contains(4));
}

TEST_F(map_test, ass_equality) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    s21::s21_map<int, double> s21m1;
    s21m1 = s21m;
    ASSERT_EQ(s21m.size(), s21m1.size());
    ASSERT_TRUE(s21m == s21m1);
}

TEST_F(map_test, access_operator) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    ASSERT_EQ(s21m[4], stdm[4]);
}

TEST_F(map_test, insert_ret) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    ASSERT_EQ(s21m.insert({15, 23}).first.operator*().first,
              stdm.insert({15, 23}).first.operator*().first);
    ASSERT_EQ(s21m.insert({15, 23}).second, stdm.insert({15, 68}).second);
}

TEST_F(map_test, at_out) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    ASSERT_ANY_THROW(stdm.at(123));
    ASSERT_ANY_THROW(s21m.at(123));
}

TEST_F(map_test, out_access_ret) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    ASSERT_EQ(stdm[99], s21m[99]);
}

TEST_F(map_test, ins_or_assign) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    ASSERT_EQ(s21m.insert_or_assign(99, 2.34).first.operator*().second,
              stdm.insert({99, 2.34}).first.operator*().second);
}

TEST_F(map_test, size_max_size) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    ASSERT_EQ(s21m.size(), stdm.size());
    ASSERT_EQ(s21m.max_size(), stdm.max_size());
}

TEST_F(map_test, erase) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::map<int, double> stdm({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    s21::s21_map<int, double>::iterator it21 = s21m.begin();
    std::map<int, double>::iterator it = stdm.begin();
    s21m.erase(it21);
    stdm.erase(it);
    assert_eq_map(s21m, stdm);
}

TEST_F(map_test, swap) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    s21::s21_map<int, double> s21m1;
    s21m1 = s21m;
    s21m1.insert({911, 1.2345});
    s21m.swap(s21m1);
    ASSERT_TRUE(s21m.contains(911));
}

TEST_F(map_test, merge) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    s21::s21_map<int, double> s21m1;
    s21m1[-1] = 1;
    s21m1[10] = 345;
    s21m1[5] = 666;
    s21m1[-5] = 656;
    s21m1[2] = 666;
    s21m.merge(s21m1);
    ASSERT_TRUE(s21m.contains(10));
}

TEST_F(map_test, emplace) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    std::pair<int, double> a{10, 20};
    std::pair<int, double> b{20, 30};
    std::pair<int, double> c{30, 40};
    std::pair<int, double> d{40, 50};
    s21m.emplace(a, c, b, d);
    s21m.emplace(std::pair<int, double>{50, 60}, a,
                 std::pair<int, double>{60, 70}, d);
    ASSERT_TRUE(s21m.contains(20));
    ASSERT_TRUE(s21m.contains(60));
}

TEST_F(map_test, incr_decr) {
    s21::s21_map<int, double> s21m({{7, 2}, {2, 3}, {5, 6}, {4, 99.9}});
    s21::s21_map<int, double>::iterator i = s21m.begin();
    ++i;
    ++i;
    ASSERT_EQ((*i).first, 5);
    --i;
    --i;
    ASSERT_EQ((*i).first, 2);
}
