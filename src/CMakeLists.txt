cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
set(SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/aes.c
	${CMAKE_CURRENT_LIST_DIR}/../include/aes_light.h)

add_library(aes_light ${SOURCES})