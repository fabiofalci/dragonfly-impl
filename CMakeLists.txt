cmake_minimum_required(VERSION 3.10)
project(dragonfly_impl)

#Bring the headers into the project
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(game ${SOURCES})