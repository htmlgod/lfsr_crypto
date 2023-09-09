#include <gtest/gtest.h>
#include <field.hpp>

// Demonstrate some basic assertions.
TEST(field_tests, is_prime) {

    field_element<2> gf2;

    using namespace field;
    EXPECT_TRUE(is_prime<2>());
    EXPECT_TRUE(is_prime<7>());
    EXPECT_TRUE(is_prime<5>());
    EXPECT_TRUE(is_prime<524287>());
    EXPECT_TRUE(is_prime<8191>());
    EXPECT_FALSE(is_prime<1>());
    EXPECT_FALSE(is_prime<9>());
    EXPECT_FALSE(is_prime<6>());
    EXPECT_FALSE(is_prime<1024>());
    EXPECT_FALSE(is_prime<1023>());
}
