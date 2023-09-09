#pragma once
#include <cmath>

namespace field {

template<size_t N>
bool is_prime() {
    if (N == 1) return false;
    if (N == 2) return true;
    for (size_t i = 2; i <= std::sqrtl(N); i++) {
        if (N % i == 0) return false;
    }
    return true;
};

//template <size_t MOD> requires Prime<MOD>
//class field {
//
//};

}
