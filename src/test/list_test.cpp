#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <string>

#include "../lib/s21_containers.h"

TEST(str, case_1) {
  std::list<std::string> std_list;
  s21::List<std::string> s21_list;
  std_list.push_back("Я");
  std_list.push_back("люблю");
  std_list.push_back("плюсы");
  s21_list.push_back("Я");
  s21_list.push_back("люблю");
  s21_list.push_back("плюсы");
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  EXPECT_EQ(*it_std, *it_s21);
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(push_back, case_1) {
  std::list<int> std_list;
  s21::List<int> s21_list;
  std_list.push_back(123);
  s21_list.push_back(123);
  std_list.push_back(777);
  s21_list.push_back(777);
  std_list.push_back(146);
  s21_list.push_back(146);
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  EXPECT_EQ(*it_std, *it_s21);
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(push_back, case_2) {
  std::list<int> std_list;
  s21::List<int> s21_list;
  std_list.push_back(123);
  std_list.push_back(456);
  std_list.push_back(789);
  s21_list.push_back(123);
  s21_list.push_back(456);
  s21_list.push_back(789);
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(push_front, case_1) {
  std::list<int> std_list;
  s21::List<int> s21_list;
  std_list.push_front(123);
  s21_list.push_front(123);
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();

  EXPECT_EQ(*it_std, *it_s21);
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(push_front, case_2) {
  std::list<int> std_list;
  s21::List<int> s21_list;
  std_list.push_front(123);
  std_list.push_front(456);
  std_list.push_front(789);
  s21_list.push_front(123);
  s21_list.push_front(456);
  s21_list.push_front(789);
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(push_front, case_3) {
  std::list<double> std_list;
  s21::List<double> s21_list;
  for (double i = 0.0; i < 10; i += 0.1) {
    std_list.push_front(i);
    s21_list.push_front(i);
  }
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(init_list, case_1) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(std_list.size(), s21_list.size());
}

TEST(empty, case_1) {
  s21::List<int> s21_list;
  EXPECT_TRUE(s21_list.empty());
  s21_list.push_front(21);
  EXPECT_FALSE(s21_list.empty());
  s21_list.pop_front();
  EXPECT_TRUE(s21_list.empty());
}

TEST(copy_list, case_1) {
  s21::List<int> s21_list{2, 4, 6, 8};
  s21::List<int> s21_list_copy = s21_list;

  auto it_cpy = s21_list_copy.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_cpy != s21_list_copy.end();
       ++it_s21, ++it_cpy) {
    EXPECT_EQ(*it_cpy, *it_s21);
  }
  EXPECT_EQ(s21_list_copy.size(), s21_list.size());
}

TEST(move_list, case_1) {
  s21::List<int> s21_list{2, 4, 6, 8};
  s21::List<int> s21_list_move = std::move(s21_list);

  std::list<int> std_list{2, 4, 6, 8};
  std::list<int> std_list_move = std::move(std_list);

  auto it_s21 = s21_list_move.begin();
  auto it_std = std_list_move.begin();
  for (; it_s21 != s21_list_move.end() || it_std != std_list_move.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_move.size(), std_list_move.size());
}

TEST(front, case_1) {
  s21::List<int> s21_list{2, 4, 6, 8};
  EXPECT_EQ(s21_list.front(), 2);
}

TEST(back, case_1) {
  s21::List<int> s21_list{2, 4, 6, 8};
  EXPECT_EQ(s21_list.back(), 8);
}

TEST(insert, case_1_middle) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  ++it_s21;
  ++it_std;
  auto it_ret_std = std_list.insert(it_std, 300);
  auto it_ret_s21 = s21_list.insert(it_s21, 300);

  it_s21 = s21_list.begin();
  it_std = std_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(*it_ret_s21, *it_ret_std);
}

TEST(insert, case_2_begin) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  std_list.insert(it_std, 300);
  s21_list.insert(s21_list.begin(), 300);

  it_s21 = s21_list.begin();
  it_std = std_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(insert, case_3_end) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  auto it_std = std_list.end();
  auto it_s21 = s21_list.end();
  std_list.insert(it_std, 300);
  s21_list.insert(it_s21, 300);

  it_s21 = s21_list.begin();
  it_std = std_list.begin();
  for (; it_s21 != s21_list.end() && it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(pop_front, case_1) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  std_list.pop_front();
  s21_list.pop_front();

  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(pop_back, case_1) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  std_list.pop_back();
  s21_list.pop_back();

  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() && it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(erase, case_1_middle) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  ++it_s21;
  ++it_std;
  std_list.erase(it_std);
  s21_list.erase(it_s21);

  it_s21 = s21_list.begin();
  it_std = std_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(erase, case_2_begin) {
  std::list<int> std_list{2, 4, 6, 8};
  s21::List<int> s21_list{2, 4, 6, 8};
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  std_list.erase(it_std);
  s21_list.erase(it_s21);

  it_s21 = s21_list.begin();
  it_std = std_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(sort, case_1) {
  std::list<int> std_list{2, 5, 4, 17, 1, 6, 8};
  s21::List<int> s21_list{2, 5, 4, 17, 1, 6, 8};
  std_list.sort();
  s21_list.sort();
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(sort, case_2) {
  std::list<int> std_list{300, 299, 298, 297, 296, 295, 294};
  s21::List<int> s21_list{300, 299, 298, 297, 296, 295, 294};
  std_list.sort();
  s21_list.sort();
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(sort, case_3) {
  std::list<int> std_list{300};
  s21::List<int> s21_list{300};
  std_list.sort();
  s21_list.sort();
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(sort, case_4) {
  std::list<int> std_list{1, 2};
  s21::List<int> s21_list{1, 2};
  std_list.sort();
  s21_list.sort();
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(sort, case_5) {
  std::list<int> std_list{1, 2, -1, -2};
  s21::List<int> s21_list{1, 2, -1, -2};
  std_list.sort();
  s21_list.sort();
  auto it_std = std_list.begin();
  auto it_s21 = s21_list.begin();
  for (; it_s21 != s21_list.end() || it_std != std_list.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(merge, case_1) {
  std::list<int> std_list_a{2, 4, 6, 8};
  std::list<int> std_list_b{3, 5, 7, 9};
  std_list_a.merge(std_list_b);

  s21::List<int> s21_list_a{2, 4, 6, 8};
  s21::List<int> s21_list_b{3, 5, 7, 9};
  s21_list_a.merge(s21_list_b);
  auto it_std = std_list_a.begin();
  auto it_s21 = s21_list_a.begin();

  for (; it_s21 != s21_list_a.end() || it_std != std_list_a.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
  EXPECT_EQ(s21_list_b.size(), std_list_b.size());
}

TEST(merge, case_2_same) {
  std::list<int> std_list_a{2, 4, 6, 8};
  std_list_a.merge(std_list_a);

  s21::List<int> s21_list_a{2, 4, 6, 8};
  s21_list_a.merge(s21_list_a);
  auto it_std = std_list_a.begin();
  auto it_s21 = s21_list_a.begin();

  for (; it_s21 != s21_list_a.end() || it_std != std_list_a.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(reverse, case_2_same) {
  std::list<int> std_list_a{2, 4, 6, 8};
  s21::List<int> s21_list_a{2, 4, 6, 8};
  std_list_a.reverse();
  s21_list_a.reverse();

  auto it_std = std_list_a.begin();
  auto it_s21 = s21_list_a.begin();

  for (; it_s21 != s21_list_a.end() || it_std != std_list_a.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(uniq, case_1) {
  std::list<int> std_list_a{2, 2, 4, 2, 6, 6, 8, 6};
  s21::List<int> s21_list_a{2, 2, 4, 2, 6, 6, 8, 6};
  std_list_a.unique();
  s21_list_a.unique();

  auto it_std = std_list_a.begin();
  auto it_s21 = s21_list_a.begin();

  for (; it_s21 != s21_list_a.end() || it_std != std_list_a.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(splice, case_1) {
  std::list<int> std_list_a{2, 4, 6, 8};
  std::list<int> std_list_b{3, 5, 7, 9};
  auto it_std = std_list_a.begin();
  ++it_std;
  std_list_a.splice(it_std, std_list_b);

  s21::List<int> s21_list_a{2, 4, 6, 8};
  s21::List<int> s21_list_b{3, 5, 7, 9};
  auto it_s21 = s21_list_a.begin();
  ++it_s21;
  s21_list_a.splice(it_s21, s21_list_b);

  it_s21 = s21_list_a.begin();
  it_std = std_list_a.begin();

  for (; it_s21 != s21_list_a.end() || it_std != std_list_a.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
  EXPECT_EQ(s21_list_b.size(), std_list_b.size());
}

TEST(splice, case_2) {
  std::list<int> std_list_a{2, 4, 6, 8};
  std::list<int> std_list_b{3, 5, 7, 9};
  auto it_std = std_list_a.begin();
  std_list_a.splice(it_std, std_list_b);

  s21::List<int> s21_list_a{2, 4, 6, 8};
  s21::List<int> s21_list_b{3, 5, 7, 9};
  auto it_s21 = s21_list_a.begin();
  s21_list_a.splice(it_s21, s21_list_b);

  it_s21 = s21_list_a.begin();
  it_std = std_list_a.begin();

  for (; it_s21 != s21_list_a.end() || it_std != std_list_a.end();
       ++it_s21, ++it_std) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
  EXPECT_EQ(s21_list_b.size(), std_list_b.size());
}

TEST(list_emplace, case_1) {
  std::list<int> std_list_a{2, 4, 6, 8};
  auto it_std = std_list_a.begin();
  ++it_std;
  auto new_pos_std = std_list_a.emplace(it_std, 10);

  s21::List<int> s21_list_a{2, 4, 6, 8};
  auto it_s21 = s21_list_a.begin();
  ++it_s21;
  auto new_pos_s21 = s21_list_a.emplace(it_s21, 10);

  it_s21 = s21_list_a.begin();
  it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
  EXPECT_EQ(*new_pos_s21, *new_pos_std);
}

TEST(list_emplace, case_2) {
  std::list<std::string> std_list_a{"one", "two", "three"};
  auto it_std = std_list_a.end();
  it_std--;
  auto new_pos_std = std_list_a.emplace(it_std, 10, 'x');

  s21::List<std::string> s21_list_a{"one", "two", "three"};
  auto it_s21 = s21_list_a.end();
  --it_s21;
  auto new_pos_s21 = s21_list_a.emplace(it_s21, 10, 'x');

  it_s21 = s21_list_a.begin();
  it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
  EXPECT_EQ(*new_pos_s21, *new_pos_std);
}

TEST(list_emplace, case_3) {
  std::list<std::string> std_list_a{"one", "two", "three"};
  std::string four = "four";
  std::string five = "five";
  std::string five21 = "five";

  auto it_std = std_list_a.end();
  it_std--;
  std_list_a.emplace(it_std, four);
  std_list_a.emplace(it_std, std::move(five));

  s21::List<std::string> s21_list_a{"one", "two", "three"};
  auto it_s21 = s21_list_a.end();
  --it_s21;
  s21_list_a.emplace(it_s21, four);
  s21_list_a.emplace(it_s21, std::move(five21));

  it_s21 = s21_list_a.begin();
  it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(list_emplace_back, case_1) {
  std::list<std::string> std_list_a{"one", "two", "three"};
  std_list_a.emplace_back(10, 'x');

  s21::List<std::string> s21_list_a{"one", "two", "three"};
  s21_list_a.emplace_back(10, 'x');

  auto it_s21 = s21_list_a.begin();
  auto it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(list_emplace_back, case_2) {
  std::list<std::string> std_list_a;
  std_list_a.emplace_back(10, 'x');

  s21::List<std::string> s21_list_a;
  s21_list_a.emplace_back(10, 'x');

  auto it_s21 = s21_list_a.begin();
  auto it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(list_emplace_front, case_1) {
  std::list<std::string> std_list_a;
  std_list_a.emplace_front(10, 'x');

  s21::List<std::string> s21_list_a;
  s21_list_a.emplace_front(10, 'x');

  auto it_s21 = s21_list_a.begin();
  auto it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}

TEST(list_emplace_front, case_2) {
  std::list<std::string> std_list_a{"one", "two", "three"};
  std_list_a.emplace_front(10, 'x');

  s21::List<std::string> s21_list_a{"one", "two", "three"};
  s21_list_a.emplace_front(10, 'x');

  auto it_s21 = s21_list_a.begin();
  auto it_std = std_list_a.begin();

  for (; it_std != std_list_a.end() || it_s21 != s21_list_a.end();
       ++it_std, ++it_s21) {
    EXPECT_EQ(*it_std, *it_s21);
  }
  EXPECT_EQ(s21_list_a.size(), std_list_a.size());
}
