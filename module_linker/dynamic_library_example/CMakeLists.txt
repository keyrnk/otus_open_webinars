cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)     
endif()

add_subdirectory(dynamic_library)

add_executable(dynamic_library_usage
	dynamic_library_usage.cpp
)
set_target_properties(dynamic_library_usage PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(dynamic_library_usage PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/dynamic_library
)
target_link_libraries(dynamic_library_usage PRIVATE
	calculation
)
