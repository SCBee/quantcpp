cmake_minimum_required(VERSION 3.27)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(includes)

project(
  quant
  VERSION 0.0.1
  LANGUAGES CXX)

set(SRC main.cpp src/VanillaOption.cpp src/Utils.cpp)

add_executable(quant ${SRC})
