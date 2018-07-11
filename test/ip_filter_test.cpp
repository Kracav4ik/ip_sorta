#include <gtest/gtest.h>

#include "../utils.h"

TEST(ip_sorta_tests, split) {
    ASSERT_EQ(split("",  '.'), std::vector<std::string>({""}));
    ASSERT_EQ(split("11", '.'), std::vector<std::string>({"11"}));
    ASSERT_EQ(split("..", '.'), std::vector<std::string>({"", "", ""}));
    ASSERT_EQ(split("11.", '.'), std::vector<std::string>({"11", ""}));
    ASSERT_EQ(split(".11", '.'), std::vector<std::string>({"", "11"}));
    ASSERT_EQ(split("11.22", '.'), std::vector<std::string>({"11", "22"}));
}

TEST(ip_sorta_tests, filter) {
    std::vector<IP> test_src = {
        {"1","1","1","1"},
        {"1","2","3","5"},
        {"1","2","3","7"},
        {"1","2","3","3"},
        {"2","3","4","1"},
        {"2","3","5","6"},
        {"4","2","1","3"},
        {"2","1","2","4"}
    };

    std::vector<IP> test1 = {
        {"1","1","1","1"},
        {"1","2","3","5"},
        {"1","2","3","7"},
        {"1","2","3","3"},
    };
    ASSERT_EQ(filter_ip_pool(test_src, 1), test1);

    std::vector<IP> test2 = {
        {"1","2","3","5"},
        {"1","2","3","7"},
        {"1","2","3","3"},
    };
    ASSERT_EQ(filter_ip_pool(test_src, 1, 2), test2);

    std::vector<IP> test3 = {
        {"1","2","3","5"},
        {"1","2","3","7"},
        {"1","2","3","3"},
    };
    ASSERT_EQ(filter_ip_pool(test_src, 1, 2, 3), test3);
}

TEST(ip_sorta_tests, filter_any) {
    std::vector<IP> test_src = {
        {"1","1","1","1"},
        {"1","2","3","5"},
        {"1","2","3","7"},
        {"1","2","3","3"},
        {"2","3","4","1"},
        {"2","3","5","6"},
        {"4","2","1","3"},
        {"2","1","2","4"}
    };

    std::vector<IP> test = {
        {"1","1","1","1"},
        {"1","2","3","5"},
        {"1","2","3","7"},
        {"1","2","3","3"},
        {"2","3","4","1"},
        {"4","2","1","3"},
        {"2","1","2","4"}
    };
    ASSERT_EQ(filter_ip_pool_any(test_src, 1), test);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

