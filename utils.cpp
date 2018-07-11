#include "utils.h"

#include <iostream>

IP split(const std::string &str, char d) {
    IP result;

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

bool sort(IP ip1, IP ip2) {
    for (int i = 0; i < ip1.size(); ++i) {
        if (std::stoi(ip1[i]) > std::stoi(ip2[i])) {
            return true;
        } else if (std::stoi(ip1[i]) < std::stoi(ip2[i])) {
            return false;
        }
    }
    return true;
}

void print(const std::vector<IP>& ip_pool) {
    for (const auto& ip : ip_pool) {
        std::string ip_string;
        for(const auto& ip_part : ip) {
            ip_string += ip_part + '.';
        }
        ip_string.pop_back();
        std::cout << ip_string << std::endl;
    }
}

std::vector<IP> filter_ip_pool_any(const std::vector<IP>& ip_pool, int i) {
    std::vector<IP> res;
    for (const auto& ip : ip_pool) {
        bool add = false;
        for (const auto& byte : ip) {
            if (i == std::stoi(byte)) {
                add = true;
            }
        }
        if (add) {
            res.push_back(ip);
        }
    }
    return res;
}