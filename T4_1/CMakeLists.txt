cmake_minimum_required(VERSION 3.0)

project(practise)

set(SOURCE practise.cpp)
set(CMAKE_CXX_FLAGS "-fexec-charset=CP949")

add_executable(${PROJECT_NAME} ${SOURCE})