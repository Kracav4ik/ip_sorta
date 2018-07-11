#include "utils.h"

#include <iostream>
#include <sstream>

ip::IP_STR ip::split(const std::string &str, char d) {
    ip::IP_STR result;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos) {
        result.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    result.push_back(str.substr(start));

    return result;
}

bool ip::sort(ip::IP ip1, ip::IP ip2) {
    for (int i = 0; i < ip1.size(); ++i) {
        if (ip1[i] > ip2[i]) {
            return true;
        } else if (ip1[i] < ip2[i]) {
            return false;
        }
    }
    return true;
}

void ip::print(const std::vector<ip::IP>& ip_pool) {
    for (const auto& ip : ip_pool) {
        std::stringstream ss;
        bool first = true;
        for(const auto& ip_part : ip) {
            if (!first) {
                ss << '.';
            }
            ss << std::to_string(ip_part);
            first = false;
        }
        std::cout << ss.str() << std::endl;
    }
    std::cout << std::endl;
}

std::vector<ip::IP> ip::filter_ip_pool_any(const std::vector<ip::IP>& ip_pool, int i) {
    std::vector<ip::IP> res;
    for (const auto& ip : ip_pool) {
        bool add = false;
        for (const auto& byte : ip) {
            if (i == byte) {
                add = true;
            }
        }
        if (add) {
            res.push_back(ip);
        }
    }
    return res;
}

ip::IP ip::toIP(const ip::IP_STR& ip_str) {
    IP res;
    for (auto&& byte : ip_str) {
        if (byte.empty()) {
            res.push_back(-1);
            continue;
        }
        res.push_back(std::stoi(byte));
    }
    return res;
}
