#include <gtest/gtest.h>

#include "../utils.h"

TEST(ip_sorta_tests, is_valid) {
    ASSERT_EQ(split("",  '.'), std::vector<std::string>({""}));
    ASSERT_EQ(split("11", '.'), std::vector<std::string>({"11"}));
    ASSERT_EQ(split("..", '.'), std::vector<std::string>({"", "", ""}));
    ASSERT_EQ(split("11.", '.'), std::vector<std::string>({"11", ""}));
    ASSERT_EQ(split(".11", '.'), std::vector<std::string>({"", "11"}));
    ASSERT_EQ(split("11.22", '.'), std::vector<std::string>({"11", "22"}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

