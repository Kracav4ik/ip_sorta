#include <gtest/gtest.h>

#include "../utils.h"

TEST(ip_sorta_tests, split) {
    ASSERT_EQ(ip::split("",  '.'), ip::IP_STR({""}));
    ASSERT_EQ(ip::split("11", '.'), ip::IP_STR({"11"}));
    ASSERT_EQ(ip::split("..", '.'), ip::IP_STR({"", "", ""}));
    ASSERT_EQ(ip::split("11.", '.'), ip::IP_STR({"11", ""}));
    ASSERT_EQ(ip::split(".11", '.'), ip::IP_STR({"", "11"}));
    ASSERT_EQ(ip::split("11.22", '.'), ip::IP_STR({"11", "22"}));
}

TEST(ip_sorta_tests, filter) {
    std::vector<ip::IP> test_src = {
        {1,1,1,1},
        {1,2,3,5},
        {1,2,3,7},
        {1,2,3,3},
        {2,3,4,1},
        {2,3,5,6},
        {4,2,1,3},
        {2,1,2,4}
    };

    std::vector<ip::IP> test1 = {
        {1,1,1,1},
        {1,2,3,5},
        {1,2,3,7},
        {1,2,3,3},
    };
    ASSERT_EQ(ip::filter_ip_pool(test_src, 1), test1);

    std::vector<ip::IP> test2 = {
        {1,2,3,5},
        {1,2,3,7},
        {1,2,3,3},
    };
    ASSERT_EQ(ip::filter_ip_pool(test_src, 1, 2), test2);

    std::vector<ip::IP> test3 = {
        {1,2,3,5},
        {1,2,3,7},
        {1,2,3,3},
    };
    ASSERT_EQ(ip::filter_ip_pool(test_src, 1, 2, 3), test3);
}

TEST(ip_sorta_tests, filter_any) {
    std::vector<ip::IP> test_src = {
        {1,1,1,1},
        {1,2,3,5},
        {1,2,3,7},
        {1,2,3,3},
        {2,3,4,1},
        {2,3,5,6},
        {4,2,1,3},
        {2,1,2,4}
    };

    std::vector<ip::IP> test = {
        {1,1,1,1},
        {1,2,3,5},
        {1,2,3,7},
        {1,2,3,3},
        {2,3,4,1},
        {4,2,1,3},
        {2,1,2,4}
    };
    ASSERT_EQ(ip::filter_ip_pool_any(test_src, 1), test);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

