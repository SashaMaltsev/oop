#include "PoolAllocator.cpp"
#include "Vector.cpp"


#include <gtest/gtest.h>


TEST(Test, Test1) {
    
    PoolAllocator<char, 4> pl;

    auto ptr1 = pl.allocate(1);
    auto ptr2 = pl.allocate(1);
    auto ptr3 = pl.allocate(1);
    auto ptr4 = pl.allocate(1);

    pl.construct(ptr1, 1);
    pl.construct(ptr2, 2);
    pl.construct(ptr3, 3);
    pl.construct(ptr4, 4);

    ASSERT_EQ(*ptr1, 1);
    ASSERT_EQ(*ptr2, 2);
    ASSERT_EQ(*ptr3, 3);
    ASSERT_EQ(*ptr4, 4);

    pl.destroy(ptr1);
    pl.destroy(ptr2);    
    pl.destroy(ptr3);
    pl.destroy(ptr4);

    pl.deallocate(ptr1, 1);
    pl.deallocate(ptr2, 1);
    pl.deallocate(ptr3, 1);
    pl.deallocate(ptr4, 1);

}

TEST(Test, Test2) {
    
    PoolAllocator<char, 3> pl;

    auto ptr1 = pl.allocate(1);
    auto ptr2 = pl.allocate(1);
    auto ptr3 = pl.allocate(1);

    EXPECT_THROW(pl.allocate(1), std::exception);
}

TEST(Test, Test3) {

    Vector<double, PoolAllocator<double, 10>> v;
    v.reserve(10);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    for (int i = 0; i < v.size(); ++i) {
        ASSERT_EQ(i + 1, v[i]);
    }

}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
