#pragma once
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <ranges>
#include <string>
#include <set>
#include <vector>

namespace cpplfsr { // namespace

enum class lfsr_direction {
    left, // x_0 ... x_n
    right // x_n ... x_0
};

template<size_t SIZE, lfsr_direction DIRECTION = lfsr_direction::left>
class lfsr {
public:
    lfsr() = default;
    lfsr(std::initializer_list<size_t> func, std::initializer_list<size_t> init) : memory(init), function(func) {
        static_assert(SIZE != 0, "Size of LFSR can not be zero");
        assert((init.size() <= SIZE) && "Size of register's init does not equal actual register's size");
        for (auto tap : func) {
            assert((tap <= SIZE) && "Size of register's tap exceeds register's size");
        }
    }

    size_t compute() const {
        size_t result = 0;
        for (auto tap : function)
            result ^= memory[tap]; 
        return result;
    }
    size_t operator()() {
        auto gamma_bit = memory.front();
        auto new_val = compute();
        std::shift_left(memory.begin(), memory.end(), 1);
        memory.back() = new_val;
        return gamma_bit;
    }
    std::string get_gamma(size_t steps) {
        std::string gamma;
        for (size_t i : std::ranges::iota_view(0u, steps))
            gamma.append(1, ((*this)() & 0b1 ? '1' : '0'));
        return gamma;
    }
private:
    std::vector<size_t> memory = std::vector<size_t>(SIZE, 0);
    std::set<size_t> function;
};

template<size_t SIZE>
class lfsr<SIZE, lfsr_direction::right> {
public:
    lfsr() = default;
    lfsr(std::initializer_list<size_t> func, std::initializer_list<size_t> init) : memory(init), function(func) {
        static_assert(SIZE != 0, "Size of LFSR can not be zero");
        assert((init.size() <= SIZE) && "Size of register's init does not equal actual register's size");
        for (auto tap : func) {
            assert((tap <= SIZE) && "Size of register's tap exceeds register's size");
        }
    }
    //lfsr(std::initializer_list<size_t> func, size_t mem);
    size_t compute() const {
        size_t result = 0;
        for (auto tap : function)
            result ^= memory[(SIZE - 1) - tap]; 
        return result;
    }
    size_t operator()() {
        auto gamma_bit = memory.back();
        auto new_val = compute();
        std::shift_right(memory.begin(), memory.end(), 1);
        memory.front() = new_val;
        return gamma_bit;
    }
    std::string get_gamma(size_t steps) {
        std::string gamma;
        for (size_t i : std::ranges::iota_view(0u, steps))
            gamma.append(1, ((*this)() & 0b1 ? '1' : '0'));
        return gamma;
    }
private:
    std::vector<size_t> memory = std::vector<size_t>(SIZE, 0);
    //std::bitset<size_t> memory;
    std::set<size_t> function;
};

size_t get_linear_complexity_cg(const std::string& gamma);
size_t get_linear_complexity_bk(const std::string& gamma);
size_t get_linear_complexity_for_comb_gen(std::initializer_list<std::string> regs_gamma,
        std::function<size_t(const std::vector<size_t>&)>&& function);
size_t get_linear_complexity_for_comb_gen_par(std::initializer_list<std::string> regs_gamma,
        std::function<size_t(const std::vector<size_t>&)>&& function);

} // end of namespace lfsr
