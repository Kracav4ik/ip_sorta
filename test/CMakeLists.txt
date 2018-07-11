set(gtest_disable_pthreads on) # needed in MinGW?
add_subdirectory(gtest)

add_executable(ip_sorta_tests ip_filter_test.cpp ../utils.cpp)

target_link_libraries(ip_sorta_tests gtest gtest_main)