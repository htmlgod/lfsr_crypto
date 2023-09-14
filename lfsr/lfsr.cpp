#include <lfsr.hpp>

#include <boost/dynamic_bitset.hpp>
#include <bitset>
#include <stdexcept>

namespace cpplfsr {

size_t get_linear_complexity_cg(const std::string& gamma) {
    size_t L = 0;
    size_t m = gamma.size();

    std::string tmp = gamma;

    while (m > 1) {
        m /= 2;
        auto l = tmp.substr(0, m);
        auto r = tmp.substr(m, 2*m);
        boost::dynamic_bitset<> b = boost::dynamic_bitset<>(l) ^ boost::dynamic_bitset<>(r);
        if (b.none()) {
            tmp = l;
        }
        else {
            L += m;
            boost::to_string(b,tmp);
        }
    }
    if (tmp[0] == '1')
        L += 1;
    return L;
}

size_t get_linear_complexity_bk(const std::string& gamma) { return gamma.size(); }

}

