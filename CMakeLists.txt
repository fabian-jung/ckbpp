cmake_minimum_required(VERSION 3.0)

project(ckbpp)

find_package(Threads)


FILE(GLOB_RECURSE ckbpp-lib-src src/ *cpp)
add_library(ckbpp-lib STATIC)
target_sources(ckbpp-lib PRIVATE ${ckbpp-lib-src})
target_include_directories(ckbpp-lib PUBLIC include)
target_compile_features(ckbpp-lib PUBLIC cxx_std_17)

add_executable(ckbpp bin/main.cpp)
set_target_properties(ckbpp PROPERTIES CXX_STANDARD 17)
target_link_libraries(ckbpp Threads::Threads ckbpp-lib)

install(TARGETS ckbpp RUNTIME DESTINATION bin)
