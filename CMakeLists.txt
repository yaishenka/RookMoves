cmake_minimum_required(VERSION 3.20)
project(RookMoves)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        chess_board.cpp
        rook.cpp
        board_position.cpp
        engine.cpp
        utils.cpp
)
add_executable(RookMoves main.cpp ${SOURCES})
add_executable(RookMovesWithSanitizers with_sanitizers.cpp ${SOURCES})

set (COMPILE_FLAGS
        -pedantic
        -Werror
        -Wextra
        -fsanitize=thread
        -fsanitize=undefined
        -std=c++20
)
target_compile_options(RookMovesWithSanitizers PUBLIC ${COMPILE_FLAGS})
target_link_options(RookMovesWithSanitizers PUBLIC ${COMPILE_FLAGS})