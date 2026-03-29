cmake_minimum_required(VERSION 3.12)

project(escc LANGUAGES CXX)

set(SOURCES
        source/main.cpp
        source/Token.cpp
        source/Token.hpp
)

add_executable(escc ${SOURCES})
