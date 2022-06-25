cmake_minimum_required(VERSION 3.18.4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  expression-templates
  VERSION 0.0.42
  LANGUAGES CXX
)

add_subdirectory(cmake/boost-cmake)

add_subdirectory(examples)

