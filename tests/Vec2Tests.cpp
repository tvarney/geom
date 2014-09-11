
#include <gtest/gtest.h>

#include "geom/Vector2.hpp"

TEST(Vector2, DefaultConstructor) {
  geom::Vector2<int> v;
  EXPECT_EQ(v.x, 0);
  EXPECT_EQ(v.y, 0);
}
TEST(Vector2, ScalarConstructor) {
  geom::Vector2<int> v(1,2);
  EXPECT_EQ(v.x, 1);
  EXPECT_EQ(v.y, 2);
}
TEST(Vector2, CopyConstructor) {
  geom::Vector2<int> v1(1,2);
  geom::Vector2<int> v2(v1);
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
}
TEST(Vector2, ConvertConstructor1) {
  geom::Vector2<double> v1(1.1, 2.2);
  geom::Vector2<int> v2(v1);
  EXPECT_EQ(static_cast<int>(v1.x), v2.x);
  EXPECT_EQ(static_cast<int>(v1.y), v2.y);
}
TEST(Vector2, ConvertConstructor2) {
  geom::Vector2<int> v1(5, 10);
  geom::Vector2<double> v2(v1);
  EXPECT_EQ(static_cast<double>(v1.x), v2.x);
  EXPECT_EQ(static_cast<double>(v1.y), v2.y);
}
TEST(Vector2, Assignment) {
  geom::Vector2<int> v1(1,2);
  geom::Vector2<int> v2;
  v2 = v1;
  EXPECT_EQ(v1.x, v2.x);
  EXPECT_EQ(v1.y, v2.y);
}
TEST(Vector2, ConvertAssignment1) {
  geom::Vector2<double> v1(1.1, 2.2);
  geom::Vector2<int> v2;
  v2 = v1;
  EXPECT_EQ(static_cast<int>(v1.x), v2.x);
  EXPECT_EQ(static_cast<int>(v1.y), v2.y);
}
TEST(Vector2, ConvertAssignment2) {
  geom::Vector2<int> v1(5, 10);
  geom::Vector2<double> v2;
  v2 = v1;
  EXPECT_EQ(static_cast<double>(v1.x), v2.x);
  EXPECT_EQ(static_cast<double>(v1.y), v2.y);
}

TEST(Vector2, Addition1) {
  geom::Vec2i v1(1,2);
  geom::Vec2i v2(0,0);
  geom::Vec2i v3(v1 + v2);
  EXPECT_EQ(v3.x, 1);
  EXPECT_EQ(v3.y, 2);
}

TEST(Vector2, Addition2) {
  geom::Vec2i v1(1,2);
  geom::Vec2i v2(-1, -2);
  geom::Vec2i v3(v1 + v2);
  EXPECT_EQ(v3.x, 0);
  EXPECT_EQ(v3.y, 0);
}

TEST(Vector2, Addition3) {
  geom::Vec2i v1(1,1);
  geom::Vec2i v2(2,3);
  geom::Vec2i v3(v1 + v2);
  EXPECT_EQ(v3.x, 3);
  EXPECT_EQ(v3.y, 4);
}

TEST(Vector2, AdditionAssignment) {
  geom::Vec2i v1(1,2);
  geom::Vec2i v2(2,1);
  v1 += v2;
  EXPECT_EQ(v1.x, 3);
  EXPECT_EQ(v1.y, 3);
}
