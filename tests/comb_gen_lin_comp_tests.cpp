#include <gtest/gtest.h>
#include <lfsr.hpp>
#include <chrono>

#include <iostream>

using namespace cpplfsr;

TEST(comb_gen_lin_comp, no_parallel1) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::cout << get_linear_complexity_for_comb_gen({"11001001","10101010","11001101"},[](const std::vector<size_t>& mem) { return mem[0]*mem[1] +
            mem[1]*mem[2] + mem[2];}) << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
}

TEST(comb_gen_lin_comp, parallel1) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::cout << get_linear_complexity_for_comb_gen_par({"11001001","10101010","11001101"},[](const std::vector<size_t>& mem) { return mem[0]*mem[1] +
            mem[1]*mem[2] + mem[2];}) << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
}

TEST(comb_gen_lin_comp, no_parallel2) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::cout << get_linear_complexity_for_comb_gen({"1100100110101010", "1010101010101010", "1100110111001001", "1100100110101010","1010101010101010","1100110111001001"},[](const std::vector<size_t>& mem) { return mem[0]*mem[1] +
            mem[1]*mem[2] + mem[2]*mem[3] + mem[3]*mem[4] + mem[5];}) << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
}

TEST(comb_gen_lin_comp, parallel2) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    std::cout << get_linear_complexity_for_comb_gen_par({"1100100110101010", "1010101010101010", "1100110111001001", "1100100110101010","1010101010101010","1100110111001001"},[](const std::vector<size_t>& mem) { return mem[0]*mem[1] +
            mem[1]*mem[2] + mem[2]*mem[3] + mem[3]*mem[4] + mem[5];}) << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
}
