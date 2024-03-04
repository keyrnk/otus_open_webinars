cmake_minimum_required(VERSION 3.5)

# ##############################################################################
#
add_executable(compilation
        compilation.cpp
)
set_target_properties(compilation PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)