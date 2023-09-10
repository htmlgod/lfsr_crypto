#pragma once
#include <algorithm>
#include <initializer_list>
#include <ranges>
#include <string>
#include <set>
#include <vector>

#include <iostream>

enum class lfsr_direction {
    left, // x_0 ... x_n
    right // x_n ... x_0
};

template<size_t SIZE, lfsr_direction DIRECTION = lfsr_direction::left>
class lfsr {
public:
    lfsr() = default;
    lfsr(std::initializer_list<size_t> func, 
         std::initializer_list<size_t> init) : memory(init), function(func) {}
    size_t compute() const {
        size_t result = 0;
        for (auto tap : function) {
            auto pos = (DIRECTION == lfsr_direction::right ? ((SIZE - 1) - tap) : tap);
            result ^= memory[pos]; 
        }
        return result;
    }
    size_t step() {
        return DIRECTION == lfsr_direction::right ? step_right() : step_left();
    }
    std::string get_gamma(size_t steps) {
        std::string gamma;
        for (size_t i : std::ranges::iota_view(0u, steps))
            gamma.append(1, (step() & 0b1 ? '1' : '0'));
        return gamma;
    }
private:
    size_t step_right() {
        auto gamma_bit = memory.back();
        auto new_val = compute();
        std::shift_right(memory.begin(), memory.end(), 1);
        memory.front() = new_val;
        return gamma_bit;
    }
    size_t step_left() {
        auto gamma_bit = memory.front();
        auto new_val = compute();
        std::shift_left(memory.begin(), memory.end(), 1);
        memory.back() = new_val;
        return gamma_bit;
    }
    std::vector<size_t> memory = std::vector<size_t>(SIZE, 0);
    std::set<size_t> function;
};
