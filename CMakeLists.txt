cmake_minimum_required(VERSION 3.9.2)

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
    set(IP_SORTA_NUMBER "0")
else()
    set(IP_SORTA_NUMBER "$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(ip_sorta VERSION 0.0.${IP_SORTA_NUMBER})

set(CMAKE_CXX_STANDARD 14)

add_executable(ip_sorta ip_filter.cpp utils.cpp utils.h)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dikama2013@yandex.ru)

include(CPack)

add_subdirectory(test)

set_target_properties(ip_sorta gtest PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

enable_testing()
add_test(
        NAME ip_sorta_tests
        COMMAND ip_sorta_tests
)