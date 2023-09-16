#include <lfsr.hpp>

#include <boost/dynamic_bitset.hpp>
#include <bitset>
#include <stdexcept>

#include <thread>
#include <future>

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

size_t get_linear_complexity_for_comb_gen(std::initializer_list<std::string> regs_gamma,
        std::function<size_t(const std::vector<size_t>&)>&& function) {
    std::vector<size_t> reg_comps;
    reg_comps.reserve(regs_gamma.size());
    for (auto& gamma : regs_gamma)
        reg_comps.push_back(get_linear_complexity_cg(gamma));

    return function(reg_comps);
}

size_t get_linear_complexity_for_comb_gen_par(std::initializer_list<std::string> regs_gamma,
        std::function<size_t(const std::vector<size_t>&)>&& function) {
    std::vector<std::future<size_t>> futures;
    futures.reserve(regs_gamma.size());
    for (auto&& gamma : regs_gamma)
        futures.push_back(std::async(std::launch::async, &get_linear_complexity_cg, std::move(gamma)));
    
    std::vector<size_t> reg_comps;
    reg_comps.reserve(regs_gamma.size());
    for (auto& future : futures)
        reg_comps.push_back(future.get());

    return function(reg_comps);
}

size_t get_linear_complexity_bk(const std::string& gamma) { return gamma.size(); }
}

