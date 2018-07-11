#include "utils.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
    try
    {
        std::vector<ip::IP> ip_pool;

        std::string line;
        std::getline(std::cin, line);
        while (!line.empty()) {
            ip::IP_STR v = ip::split(line, '\t');
            ip_pool.push_back(ip::toIP(ip::split(v.at(0), '.')));
            std::getline(std::cin, line);
        }

        std::sort(ip_pool.begin(), ip_pool.end(), ip::sort);

        ip::print(ip_pool);
        ip::print(ip::filter_ip_pool(ip_pool, 1));
        ip::print(ip::filter_ip_pool(ip_pool, 46, 70));
        ip::print(ip::filter_ip_pool_any(ip_pool, 46));
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
