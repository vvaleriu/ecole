cmake_minimum_required(VERSION 3.2)
project(n_puzzle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")

set(SOURCE_FILES srcs/main.cpp headers/n_puzzle.h srcs/Manager.cpp srcs/Manager.hpp srcs/AHeuristic.cpp srcs/AHeuristic.hpp srcs/HeuManhattan.cpp srcs/HeuManhattan.hpp srcs/AAlgorithm.cpp srcs/AAlgorithm.hpp srcs/AlgoAStar.cpp srcs/AlgoAStar.hpp)
add_executable(n_puzzle ${SOURCE_FILES} srcs/State.cpp srcs/State.hpp headers/n_puzzle.h srcs/HeuManhattan.cpp srcs/HeuManhattan.hpp)

find_package(Boost)
IF (Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIR})
endif()