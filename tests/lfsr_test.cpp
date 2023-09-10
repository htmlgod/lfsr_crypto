#include <gtest/gtest.h>
#include <iostream>
#include <lfsr.hpp>

// TODO: add more tests

TEST(lfsr_tests, step_right) {
    lfsr<3, lfsr_direction::right> reg{{0,2}, {0,0,1}};
    EXPECT_TRUE(reg.step() == 1);
}

TEST(lfsr_tests, step_left) {
    lfsr<3> reg{{0,2}, {0,0,1}};
    EXPECT_TRUE(reg.step() == 0);
}

TEST(lfsr_tests, gamma_left) {
    lfsr<4> reg{{0,1,3}, {1,1,0,1}};
    std::string gamma = reg.get_gamma(9);
    std::string str = "110110110";
    EXPECT_EQ(gamma, str);
}
TEST(lfsr_tests, gamma_right) {
    {
        lfsr<32, lfsr_direction::right> reg{{31, 30, 29, 27, 25, 0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};
        std::string gamma = reg.get_gamma(96);
        std::string str = "100000000000000000000000000000001100100010110101111110011011101011110000101100101010011101011100";
        EXPECT_EQ(gamma, str);
    }
    {
        lfsr<3, lfsr_direction::right> reg{{0,2}, {0,0,1}};
        std::string gamma = reg.get_gamma(8);
        std::string str = "10011101";
        EXPECT_EQ(gamma, str);
    }
    {
        lfsr<4, lfsr_direction::right> reg{{3,1}, {0,1,0,1}};
        std::string gamma = reg.get_gamma(7);
        std::string str = "1010011";
        EXPECT_EQ(gamma, str);
    }
}
