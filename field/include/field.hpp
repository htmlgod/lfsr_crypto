#pragma once
#include <concepts>
#include <cmath>

template<std::size_t N>
constexpr bool is_prime() {
    if (N == 1) return false;
    if (N == 2) return true;
    for (size_t i = 2; i <= sqrtl(N); i++) {
        if (N % i == 0) return false;
    }
    return true;
}

template<std::size_t N>
concept Prime = is_prime<N>();

template <size_t MOD> requires Prime<MOD>
class field {
public:
    static get(size_t value) {
    }
    class field_element {
    public:
        field_element();
        field_element(size_t value);
        field_element& operator+=(const field_element& rhs);
        friend field_element operator+(field_element lhs, const field_element& rhs);
    private:
        size_t _value;
    };
private:

};
