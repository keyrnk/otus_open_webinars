cmake_minimum_required(VERSION 3.2)

project(BoostPrebuilt)

# Lookup for pre-built boost
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

message(STATUS ${Boost_INCLUDE_DIRS})
message(STATUS ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Main target
add_executable(
    demo
    src/main.cpp
    src/list.hpp
)

# Test target
add_executable(
    test_list
    test/test_list.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    ${Boost_INCLUDE_DIRS}
)

add_executable(
    test_fixture
    test/test_fixture.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_fixture PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    ${Boost_INCLUDE_DIRS}
)

add_executable(
    test_multi
    test/test_one.cpp
    test/test_second.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_multi PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    ${Boost_INCLUDE_DIRS}
)

# Link test target against gtest libraries
target_link_libraries(
    test_multi PRIVATE
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable(
    test_params
    test/test_params.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_params PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    ${Boost_INCLUDE_DIRS}
)

set_target_properties(demo PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_fixture PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_multi PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_params PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        demo PRIVATE
        /W4
    )
    target_compile_options(
        test_list PRIVATE
        /W4
    )
    target_compile_options(
        test_fixture PRIVATE
        /W4
    )
    target_compile_options(
        test_multi PRIVATE
        /W4
    )
else ()
    target_compile_options(
        demo PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_list PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_fixture PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_multi PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

    target_compile_options(
        test_params PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
