#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "../lib/s21_containers.h"

TEST(insert_test, case_1) {
    std::vector<char> current{1, 2, 3, 4, 5, 6};
    s21::Vector<char> custom{1, 2, 3, 4, 5, 6};
    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    current.insert(it_1 + 3, 9);
    custom.insert(it_2 + 3, 9);

    it_1 = current.begin();
    it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.size(), custom.size());
}

TEST(insert_test, case_2) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};
    auto it_1 = current.end();
    auto it_2 = custom.end();

    current.insert(it_1, 9);
    custom.insert(it_2, 9);

    it_1 = current.begin();
    it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.size(), custom.size());
}

TEST(at_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    for (size_t i = 0; i < current.size(); i++) {
        EXPECT_EQ(current.at(i), custom.at(i));
    }
}

TEST(reserve_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(current.capacity(), custom.capacity());

    size_t newSize = 20;

    current.reserve(newSize);
    custom.reserve(newSize);

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(reserve_test, case_2) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(current.capacity(), custom.capacity());

    size_t newSize = 2;

    current.reserve(newSize);
    custom.reserve(newSize);

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(reserve_test, case_3) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(current.capacity(), custom.capacity());

    size_t newSize = 0;

    current.reserve(newSize);
    custom.reserve(newSize);

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(reserve_test, case_4) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(current.capacity(), custom.capacity());

    size_t newSize = 2000000;

    current.reserve(newSize);
    custom.reserve(newSize);

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(shrink_to_fit_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(current.capacity(), custom.capacity());

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    current.insert(it_1 + 3, 9);
    custom.insert(it_2 + 3, 9);

    EXPECT_EQ(current.capacity(), custom.capacity());

    current.shrink_to_fit();
    custom.shrink_to_fit();

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(push_back_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    current.push_back(9);
    custom.push_back(9);

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.size(), custom.size());
}

TEST(pop_back_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    current.pop_back();
    custom.pop_back();

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.size(), custom.size());
}

TEST(front_test, case_1) {
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(1, custom.front());
}

TEST(back_test, case_1) {
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    EXPECT_EQ(5, custom.back());
}

TEST(iterators_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};

    auto it_1 = current.begin();
    auto it_2 = custom.begin();
    auto it_end = custom.end();

    for (; it_2 != it_end; it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }
}

TEST(is_empty_test, case_1) {
    std::vector<int> current(0);
    s21::Vector<int> custom(0);

    EXPECT_TRUE(current.empty());
    EXPECT_TRUE(custom.empty());
}

TEST(is_empty_test, case_2) {
    std::vector<int> current{1, 2, 3, 4};
    s21::Vector<int> custom{1, 2, 3};

    EXPECT_FALSE(current.empty());
    EXPECT_FALSE(custom.empty());
}

TEST(clear_test, case_1) {
    std::vector<int> current{1, 2, 3, 4};
    s21::Vector<int> custom{1, 2, 3};

    EXPECT_FALSE(current.empty());
    EXPECT_FALSE(custom.empty());

    current.clear();
    custom.clear();

    EXPECT_TRUE(current.empty());
    EXPECT_TRUE(custom.empty());
}

TEST(erase_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5};
    s21::Vector<int> custom{1, 2, 3, 4, 5};
    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    current.erase(it_1 + 3);
    custom.erase(it_2 + 3);

    it_1 = current.begin();
    it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.size(), custom.size());
}

TEST(max_size_test, case_1) {
    std::vector<int> current;
    s21::Vector<int> custom;

    EXPECT_EQ(current.max_size(), custom.max_size());
}

TEST(swap_test, case_1) {
    s21::Vector<int> currentFirst{1, 2, 3, 4, 5, 6};
    s21::Vector<int> currentSecond{9, 8, 7, 6, 5, 4};

    s21::Vector<int> swappedFirst = currentSecond;
    s21::Vector<int> swappedSecond = currentFirst;

    swappedFirst.swap(swappedSecond);
    for (auto i = 0; i < currentFirst.size(); i++) {
        EXPECT_EQ(swappedFirst[i], currentFirst[i]);
    }
    for (auto i = 0; i < currentSecond.size(); i++) {
        EXPECT_EQ(swappedSecond[i], currentSecond[i]);
    }
}

TEST(swap_test, case_2) {
    s21::Vector<int> currentFirst{1, 2, 3, 4, 5, 6};
    s21::Vector<int> currentSecond{9, 8, 7, 6, 5, 4, 9, 76, 43};

    s21::Vector<int> swappedFirst = currentSecond;
    s21::Vector<int> swappedSecond = currentFirst;

    swappedFirst.swap(swappedSecond);
    for (auto i = 0; i < currentFirst.size(); i++) {
        EXPECT_EQ(swappedFirst[i], currentFirst[i]);
    }
    for (auto i = 0; i < currentSecond.size(); i++) {
        EXPECT_EQ(swappedSecond[i], currentSecond[i]);
    }
}

TEST(construct_test, case_1) {
    std::vector<int> current;
    s21::Vector<int> custom;

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.data(), custom.data());
}

TEST(construct_test, case_2) {
    std::vector<int> current(10);
    s21::Vector<int> custom(10);

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }
}

TEST(construct_test, case_3) {
    std::vector<int> current{1, 2, 3, 4, 5, 6};
    s21::Vector<int> custom{1, 2, 3, 4, 5, 6};

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }
}

TEST(construct_test, case_4) {
    std::vector<int> first{1, 2, 3, 4, 5, 6};
    s21::Vector<int> second{1, 2, 3, 4, 5, 6};

    std::vector<int> current(first);
    s21::Vector<int> custom(second);

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }
}

TEST(construct_test, case_5) {
    std::vector<int> first{1, 2, 3, 4, 5, 6};
    s21::Vector<int> second{1, 2, 3, 4, 5, 6};

    std::vector<int> current = std::move(first);
    s21::Vector<int> custom = std::move(second);

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(first.size(), second.size());
    EXPECT_EQ(first.capacity(), second.capacity());
}

TEST(operator_assign_test, case_1) {
    std::vector<int> first{1, 2, 3, 4, 5, 6};
    s21::Vector<int> second{1, 2, 3, 4, 5, 6};

    std::vector<int> current = first;
    s21::Vector<int> custom = second;

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(first.size(), second.size());
    EXPECT_EQ(first.capacity(), second.capacity());
}

TEST(operator_assign_test, case_2) {
    std::vector<int> first{1, 2, 3, 4, 5, 6};
    s21::Vector<int> second{1, 2, 3, 4, 5, 6};

    std::vector<int> current = first;
    s21::Vector<int> custom = second;

    auto it_1 = current.begin();
    auto it_2 = custom.begin();

    for (; it_1 != current.end(); it_1++, it_2++) {
        EXPECT_EQ(*it_1, *it_2);
    }

    EXPECT_EQ(first.size(), second.size());
    EXPECT_EQ(first.capacity(), second.capacity());
}

TEST(operator_iterator_test, case_1) {
    std::vector<int> current{1, 2, 3, 4, 5, 6};
    s21::Vector<int> custom{1, 2, 3, 4, 5, 6};

    for (auto i = 0; i < current.size(); i++) {
        EXPECT_EQ(current[i], custom[i]);
    }
}

TEST(emplace_back, case_1) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    current.emplace_back();
    custom.emplace_back();

    auto it1 = current.begin();
    auto it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(emplace_back, case_2) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    current.emplace_back("four");
    custom.emplace_back("four");

    auto it1 = current.begin();
    auto it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(emplace_back, case_3) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    current.push_back("zero");
    custom.push_back("zero");

    current.emplace_back("four");
    custom.emplace_back("four");

    auto it1 = current.begin();
    auto it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }

    EXPECT_EQ(current.size(), custom.size());
    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(emplace_back, case_4) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    current.emplace_back(5, 'x');
    custom.emplace_back(5, 'x');

    auto it1 = current.begin();
    auto it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(emplace, case_1) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    EXPECT_EQ(*(current.emplace(it1)), *(custom.emplace(it2)));
}

TEST(emplace, case_2) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    current.emplace(it1);
    custom.emplace(it2);

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(emplace, case_2_1) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    current.push_back("zero");
    custom.push_back("zero");

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    current.emplace(it1);
    custom.emplace(it2);

    EXPECT_EQ(current.capacity(), custom.capacity());
}

TEST(emplace, case_3) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    current.emplace(it1);
    custom.emplace(it2);

    EXPECT_EQ(current.size(), custom.size());
}

TEST(emplace, case_4) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    current.emplace(it1);
    custom.emplace(it2);

    it1 = current.begin();
    it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(emplace, case_5) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    current.emplace(it1, 10, 'w');
    custom.emplace(it2, 10, 'w');

    it1 = current.begin();
    it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(emplace, case_6) {
    std::vector<std::string> current{"one", "two", "three"};
    s21::Vector<std::string> custom{"one", "two", "three"};

    current.push_back("zero");
    custom.push_back("zero");

    auto it1 = current.begin() + 1;
    auto it2 = custom.begin() + 1;

    current.emplace(it1, 10, 'q');
    custom.emplace(it2, 10, 'q');

    it1 = current.begin();
    it2 = custom.begin();

    for (; it1 != current.end(); it1++, it2++) {
        EXPECT_EQ(*it1, *it2);
    }

    EXPECT_EQ(current.capacity(), custom.capacity());
    EXPECT_EQ(current.size(), custom.size());
}

TEST(def_constr, zero_size) {
    const int c_size = 0;
    std::vector<int> current(c_size);
    s21::Vector<int> custom(c_size);

    ASSERT_EQ(current.size(), custom.size());
}
