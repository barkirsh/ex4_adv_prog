cmake_minimum_required(VERSION 3.16)
project(ex5_adv_prog)

set(CMAKE_CXX_STANDARD 11)

add_executable(client Client.cpp ValidationClient.cpp)
add_executable(server Server.cpp DataSetsHandler.cpp
        Knn.cpp ValidationClient.cpp Command.h PrintCmd.cpp
        Dio's/SocketIO.cpp Dio's/DefaultIO.cpp)