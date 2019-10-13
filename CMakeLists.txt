cmake_minimum_required(VERSION 3.0)

project(ckbpp)

add_executable(ckbpp main.cpp)

install(TARGETS ckbpp RUNTIME DESTINATION bin)
