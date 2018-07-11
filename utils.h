#pragma once
#include <string>
#include <vector>

using IP = std::vector<std::string>;

IP split(const std::string &str, char d);
bool sort(IP ip1, IP ip2);
void print(const std::vector<IP>& ip_pool);

template<typename... Args>
std::vector<IP> filter_ip_pool(std::vector<IP> ip_pool, Args... args) {
    std::vector<IP> res;
    std::vector<int> inp = {args...};
    for (const auto& ip : ip_pool) {
        bool add = true;
        for (int i = 0; i < inp.size(); ++i) {
            if (inp[i] != std::stoi(ip[i])) {
                add = false;
            }
        }
        if (add) {
            res.push_back(ip);
        }
    }
    return res;
}
