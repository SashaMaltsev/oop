#include "src/Pentagon.cpp"
#include "src/Rhomb.cpp"
#include "src/Trapezoid.cpp"

#include <gtest/gtest.h>

TEST(Test, DefaultConstructor) {
    Rhomb r;
    ASSERT_EQ(r.GetName(), "Rhomb");
}

TEST(Test, Constructor) {
    Trapezoid t({{1.0, 1.0}, {2.0, 7.0}, {7.0, 7.0}, {10.0, 1.0}});
    std::stringstream s;

    s << t;

    ASSERT_EQ(s.str(), "Trapezoid: { (1, 1) (2, 7) (7, 7) (10, 1) }");
}

TEST(Test, Square) {
    Trapezoid t({{1.0, 1.0}, {2.0, 7.0}, {7.0, 7.0}, {10.0, 1.0}});
    ASSERT_NEAR(t.Square(), 42.0, 0.001);
}

TEST(Test, Vector) {
    Trapezoid t({{1.0, 1.0}, {2.0, 7.0}, {7.0, 7.0}, {10.0, 1.0}});

    std::vector<Trapezoid> v {t, t, t};

    ASSERT_EQ(v[0], t);
    ASSERT_EQ(v[1], t);
    ASSERT_EQ(v[2], t);
}

TEST(Test, test) {
    Trapezoid t({{1.0, 1.0}, {2.0, 7.0}, {7.0, 7.0}, {10.0, 1.0}});
    Rhomb r;

    ASSERT_EQ(t == r, false);
}

TEST(Test, CenterTest) {
    Trapezoid t({{1.0, 1.0}, {2.0, 7.0}, {7.0, 7.0}, {10.0, 1.0}});

    ASSERT_EQ(t.Center().x, 5.0);
    ASSERT_EQ(t.Center().y, 4.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}