#include "laba2.cpp"

#include <gtest/gtest.h>

TEST(HexTest, DefaultConstructor) {
    Hex hex;
    ASSERT_EQ(hex.Size(), 1);
    ASSERT_EQ(hex.Data()[0], '0');
}

TEST(HexTest, SizeConstructor) {
    Hex hex(10, 'a');
    ASSERT_EQ(hex.Size(), 10);

    for (size_t i = 0; i < hex.Size(); ++i) {
        ASSERT_EQ(hex.Data()[i], 'a');
    }
}

TEST(HexTest, InitializerListConstructor) {
    Hex hex = {'a', 'b', 'c'};
    ASSERT_EQ(hex.Size(), 3);
    ASSERT_EQ(hex.Data()[0], 'a');
    ASSERT_EQ(hex.Data()[1], 'b');
    ASSERT_EQ(hex.Data()[2], 'c');
}

TEST(HexTest, StringConstructor) {
    Hex hex("abcdef");
    ASSERT_EQ(hex.Size(), 6);
    ASSERT_EQ(hex.Data()[0], 'a');
    ASSERT_EQ(hex.Data()[1], 'b');
    ASSERT_EQ(hex.Data()[2], 'c');
    ASSERT_EQ(hex.Data()[3], 'd');
    ASSERT_EQ(hex.Data()[4], 'e');
    ASSERT_EQ(hex.Data()[5], 'f');
}

TEST(HexTest, CopyConstructor) {
    Hex hex1 = {'a', 'b', 'c'};
    Hex hex2(hex1);
    ASSERT_EQ(hex2.Size(), 3);
    ASSERT_EQ(hex2.Data()[0], 'a');
    ASSERT_EQ(hex2.Data()[1], 'b');
    ASSERT_EQ(hex2.Data()[2], 'c');
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}