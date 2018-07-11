#pragma once
#include <string>
#include <vector>
namespace ip {
    using IP = std::vector<int>;
    using IP_STR = std::vector<std::string>;

    IP_STR split(const std::string& str, char d);

    bool sort(IP ip1, IP ip2);
    IP toIP(const IP_STR& ip_str);
    
    void print(const std::vector<IP>& ip_pool);

    std::vector<IP> filter_ip_pool_any(const std::vector<IP>& ip_pool, int i);

    template <typename... Args>
    std::vector<IP> filter_ip_pool(const std::vector<IP>& ip_pool, Args... args) {
        std::vector<IP> res;
        std::vector<int> inp = {args...};
        for (const auto& ip : ip_pool) {
            bool add = true;
            for (int i = 0; i < inp.size(); ++i) {
                if (inp[i] != ip[i]) {
                    add = false;
                }
            }
            if (add) {
                res.push_back(ip);
            }
        }
        return res;
    }
}