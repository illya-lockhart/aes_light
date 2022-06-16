cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
if(NOT TARGET aes_light)
	return()
endif()

add_executable(aes_light_tests 
	tests.h
	main.c
	expansion_keys.c )

target_link_libraries(aes_light_tests PRIVATE aes_light)