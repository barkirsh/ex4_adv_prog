cmake_minimum_required(VERSION 3.16)
project(ex5_adv_prog)

set(CMAKE_CXX_STANDARD 11)

add_executable(client Client.cpp ValidationClient.cpp)
add_executable(server Server.cpp
        DataSetsHandler.cpp Knn.cpp ValidationClient.cpp
        Command.h PrintCmd.cpp
        Dio's/SocketIO.cpp Dio's/DefaultIO.cpp Dio's/DefaultIO.h Dio's/SocketIO.h
        Distances/Distance.h Distances/Can.cpp Distances/Cheb.cpp Distances/Euc.cpp Distances/Man.cpp Distances/Minikovski.cpp
        ClientData.h ClientData.cpp

        )