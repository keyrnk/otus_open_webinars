cmake_minimum_required(VERSION 3.5)

add_executable(compilation_with_headers
        compilation_with_headers.cpp
        functions.cpp
)
set_target_properties(compilation_with_headers PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)