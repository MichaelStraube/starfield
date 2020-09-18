cmake_minimum_required(VERSION 3.8)

project(starfield LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
add_compile_options(-Wall -Wextra)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(starfield
	src/main.cpp
	src/starfield.cpp
	src/starfield.h
)

target_link_libraries(starfield sfml-graphics sfml-window sfml-system)
