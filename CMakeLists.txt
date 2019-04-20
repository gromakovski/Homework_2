cmake_minimum_required(VERSION 3.2)

set(BUILD_NUMBER 1)
if($ENV{TRAVIS_BUILD_NUMBER})
  set(BUILD_NUMBER $ENV{TRAVIS_BUILD_NUMBER})
endif($ENV{TRAVIS_BUILD_NUMBER})

project(filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)

configure_file(version.h.in version.h)

set (GTEST_ROOT /usr/src/gtest)
set (GTEST_LIBRARY /usr/src/gtest/libgtest.a)
set (GTEST_MAIN_LIBRARY /usr/src/gtest/libgtest_main.a)

add_executable(ip_filter main.cpp)

add_library(ip filter.cpp)

add_library(filter lib.cpp)

add_executable(test_version test_version.cpp)

add_executable(test_main gtest_main.cpp)

set_target_properties(ip_filter filter ip test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(ip_filter
    filter
    ip
)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    filter
)

target_link_libraries(gtest_main ${GTEST_BOTH_LIBRARIES} 
    ip_filter
    pthread
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT gromakovskiyvladimir1989@gmail.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
add_test(test_main test_main)