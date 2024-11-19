cmake_minimum_required(VERSION 3.2)

project(ProjestWithGTest)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    #By default, new Visual Studio projects link the C runtimes dynamically
    #but GoogleTest links them statically. This will generate an error
    #Enabling this option will make gtest link the runtimes dynamically too
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
endif()

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)

# Test target
add_library(stack_lib STATIC src/RotatedStack.cpp src/function.cpp)

add_executable(
    test_stack
    test/test_stack.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_stack PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    test_stack PRIVATE
    gtest gtest_main
    #-Wl,--whole-archive //for clang
    stack_lib
    #-Wl,--no-whole-archive
)

add_custom_target(copy_script
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/generate_coverage.sh ${CMAKE_BINARY_DIR}/generate_coverage.sh
)

add_dependencies(test_stack copy_script)

set_target_properties(test_stack PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        test_stack PRIVATE
        /W4
    )
else ()
    target_compile_options(
        test_stack PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
