#include "utils.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>

std::vector<IP> ip_pool;

template<typename... Args>
std::vector<IP> filter(Args... args) {
    return filter_ip_pool(ip_pool, args...);
}

std::vector<IP> filter_any(int i) {
    return filter_ip_pool_any(ip_pool, i);
}


int main(int argc, char const *argv[]) {
    try
    {
        std::string line;
        std::getline(std::cin, line);
        while (!line.empty()) {
            IP v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
            std::getline(std::cin, line);
        }

        std::sort(ip_pool.begin(), ip_pool.end(), sort);

        print(ip_pool);
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
