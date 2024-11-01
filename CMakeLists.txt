cmake_minimum_required(VERSION 3.11)
project(Sort)
file (GLOB SOURCES "src/*.cpp")
add_executable(Sort ${SOURCES})
