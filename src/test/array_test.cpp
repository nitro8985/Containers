#include <gtest/gtest.h>

#include <iostream>
#include <array>

#include "../lib/s21_containersplus.h"

TEST(construct, case_1) {
    s21::Array<int, 5> custom;
    std::array<int, 5> current;

    EXPECT_EQ(custom.size(), current.size());
}

TEST(construct_list, case_1) {
    s21::Array<int, 6> custom{1, 2, 9, 0, 6, 54};
    std::array<int, 6> current{1, 2, 9, 0, 6, 54};

    EXPECT_EQ(custom.size(), current.size());

    auto it = custom.begin();
    auto it2 = current.begin();

    for (; it != custom.end(); it++, it2++) {
        EXPECT_EQ(*it, *it2);
    }
}

TEST(construct_copy, case_1) {
    s21::Array<int, 6> first{1, 9, 4, 89, 7, -3};
    std::array<int, 6> second{1, 9, 4, 89, 7, -3};

    s21::Array<int, 6> custom(first);
    std::array<int, 6> current(second);

    EXPECT_EQ(custom.size(), current.size());

    auto it = custom.begin();
    auto it2 = current.begin();

    for (; it != custom.end(); it++, it2++) {
        EXPECT_EQ(*it, *it2);
    }
}

TEST(construct_move, case_1) {
    s21::Array<int, 6> first{1, 2, 9, 0, 6, 54};
    std::array<int, 6> second{1, 2, 9, 0, 6, 54};

    s21::Array<int, 6> custom = std::move(first);
    std::array<int, 6> current = std::move(second);

    EXPECT_EQ(custom.size(), current.size());
    EXPECT_EQ(first.size(), second.size());

    auto it = custom.begin();
    auto it2 = current.begin();

    for (; it != custom.end(); it++, it2++) {
        EXPECT_EQ(*it, *it2);
    }

    auto elem1 = first.begin();
    auto elem2 = second.begin();

    for (; elem1 != first.end(); elem1++, elem2++) {
        EXPECT_EQ(*elem1, *elem2);
    }
}

TEST(operator_assign, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    std::array<int, 5> currentReceiver;
    s21::Array<int, 5> customReceiver;

    currentReceiver = current;
    customReceiver = custom;

    EXPECT_EQ(customReceiver.size(), custom.size());

    auto it = customReceiver.begin();
    auto it2 = currentReceiver.begin();

    for (; it != customReceiver.end(); it++, it2++) {
        EXPECT_EQ(*it, *it2);
    }
}

TEST(begin, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    auto itCustom = custom.begin();
    auto itCurrent = current.begin();

    EXPECT_EQ(*itCustom, *itCurrent);
}

TEST(begin, case_2) {
    std::array<int, 0> current;
    s21::Array<int, 0> custom;

    auto itCustom = custom.begin();
    auto endCustom = custom.end();
    auto itCurrent = current.begin();
    auto endCurrent = current.end();

    std::cout << *itCustom << std::endl;

    EXPECT_EQ(itCurrent, endCurrent);
    EXPECT_EQ(itCustom, endCustom);
}

TEST(end, case_1) {
  std::array<int, 5> current {9, 8, 7, 6, 5};
  s21::Array<int, 5> custom {9, 8, 7, 6, 5};

  EXPECT_NO_THROW(custom.end());
  EXPECT_NO_THROW(current.end());
}

TEST(at, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    EXPECT_EQ(current.at(4), custom.at(4));
}

TEST(at, case_2) {
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    EXPECT_ANY_THROW(custom.at(6));
}

TEST(operator_access, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    for (int i = 0; i < current.size(); i++) {
        EXPECT_EQ(current[i], custom[i]);
    }
}

TEST(array_front, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    EXPECT_EQ(current.front(), custom.front());
}

TEST(array_back, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    EXPECT_EQ(current.back(), custom.back());
}

TEST(data, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    int* _pCurr = current.data();
    int* _pCust = custom.data();

    for (int i = 0; i < current.size(); i++) {
        EXPECT_EQ(_pCurr[i], _pCust[i]);
    }
}

TEST(array_empty, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    EXPECT_EQ(current.empty(), custom.empty());
}

TEST(array_empty, case_2) {
  std::array<int, 0> _emptCurrent;
  s21::Array<int, 0> _emptCustom;

    EXPECT_EQ(_emptCurrent.empty(), _emptCustom.empty());
}

TEST(size, case_1) {
    std::array<int, 5> current{9, 8, 7, 6, 5};
    s21::Array<int, 5> custom{9, 8, 7, 6, 5};

    EXPECT_EQ(current.size(), custom.size());
}

TEST(max_size, case_1) {
    std::array<int, 5> current;
    s21::Array<int, 5> custom;

    EXPECT_EQ(current.max_size(), custom.max_size());
}

TEST(swap, case_1) {
    const int c_size = 5;
    std::array<int, c_size> _firstCurrent{1, 2, 3, 4, 5};
    std::array<int, c_size> _secondCurrent{98, 456, 54, 0, -89};

    s21::Array<int, c_size> _firstCustom{1, 2, 3, 4, 5};
    s21::Array<int, c_size> _secondCustom{98, 456, 54, 0, -89};

    _firstCurrent.swap(_secondCurrent);
    _firstCustom.swap(_secondCustom);

    for (int i = 0; i < c_size; i++) {
        EXPECT_EQ(_firstCurrent[i], _firstCustom[i]);
    }
}

TEST(fill, case_1) {
    const int c_size = 5;
    std::array<int, c_size> current{98, 456, 54, 0, -89};
    s21::Array<int, c_size> custom{9, 8, 7, 6, 5};

    current.fill(5);
    custom.fill(5);

    for (int i = 0; i < c_size; i++) {
        EXPECT_EQ(current[i], custom[i]);
    }
}
