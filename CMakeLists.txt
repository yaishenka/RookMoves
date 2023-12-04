cmake_minimum_required(VERSION 3.20)
project(RookMoves)

set(CMAKE_CXX_STANDARD 20)

add_executable(RookMoves main.cpp chess_board.cpp rook.cpp board_position.cpp engine.cpp utils.cpp)
