cmake_minimum_required(VERSION 3.0.0)

project(BlackJackProject)

file(GLOB SOURCES "*.cpp")
add_compile_options(-std=c++11)

add_executable(BlackJackProject ${SOURCES})