set(gtest_disable_pthreads on) # needed in MinGW?
add_subdirectory(googletest-release-1.8.0)

add_executable(ip_sorta_tests ip_filter_test.cpp)

target_link_libraries(ip_sorta_tests gtest gtest_main)