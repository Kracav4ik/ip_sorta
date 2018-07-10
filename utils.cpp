#include "utils.h"

std::vector<std::string> split(const std::string &str, char d) {
    std::vector<std::string> result;

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

bool sort(std::vector<std::string> v1, std::vector<std::string> v2) {
    for (int i = 0; i < v1.size(); ++i) {
        if (std::stoi(v1[i]) > std::stoi(v2[i])) {
            return true;
        } else if (std::stoi(v1[i]) < std::stoi(v2[i])) {
            return false;
        }
    }
    return true;
}
