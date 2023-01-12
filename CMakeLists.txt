cmake_minimum_required(VERSION 3.22)
project(ex5_adv_prog)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex5_adv_prog main.cpp ClassifyData.h ClassifyData.h Command.cpp Command.h DefaultIO.cpp StandardIO.cpp StandardIO.h StandardIO.h DisplayResultCommand.cpp)
