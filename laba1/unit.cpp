#include "laba1.cpp"

#include <gtest/gtest.h>


TEST(GCDTest, test) {
    ASSERT_EQ(gcd(100, 50), 50);
    ASSERT_EQ(gcd(10, 50), 10);
    ASSERT_EQ(gcd(11, 18), 1);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
