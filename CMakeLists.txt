cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
if(TARGET aes_light)
	return()
endif()

# All options
option(AES_BUILD_TESTS "Build tests for aes" ON)

# Create the Wbfs_utils target
project(aes_light VERSION 0.1.0 LANGUAGES C)

# Set the include path so the library can define symbols for the
# external headers and include the source for the library
add_subdirectory(src)
target_include_directories(aes_light PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

# Add the examples
if(${AES_BUILD_TESTS})
	add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)
endif()