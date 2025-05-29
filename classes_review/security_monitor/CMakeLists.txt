cmake_minimum_required(VERSION 3.14)
project(SecurityMonitor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Diretórios
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(security_monitor ${SOURCES})