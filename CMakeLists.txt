cmake_minimum_required(VERSION 3.16)
project(ChessEngine C)

set(CMAKE_C_STANDARD 99)

add_executable(ChessEngine sources/main.c headers/struct.h sources/data.c headers/data.h sources/init.c headers/init.h sources/print.c headers/print.h sources/eval.c headers/eval.h sources/board.c headers/board.h sources/test.c headers/test.h sources/move.c headers/move.h sources/generator.c headers/generator.h sources/search.c headers/search.h sources/pvTable.c headers/pvTable.h)
