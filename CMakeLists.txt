cmake_minimum_required(VERSION 3.16)
project(ex4_adv)

set(CMAKE_CXX_STANDARD 11)

add_executable(server ServerClass.cpp ServerClass.h
        DefaultIO.h DefaultIO.cpp SocketIO.cpp SocketIO.h

        CLI.cpp CLI.h
        ClientData.cpp ClientData.h Command.h Command.cpp
        UploadCommand.cpp SettingCommand.cpp ClassifyDataCommand.cpp DisplayResultCommand.cpp DownloadResultCommand.cpp
        Distance.h Distance.cpp Can.cpp Cheb.cpp Euc.cpp Man.cpp Minikovski.cpp
        DataSetsHandler.cpp DataSetsHandler.h Knn.cpp Knn.h)

add_executable(client Client.cpp Client.h
        DefaultIO.h DefaultIO.cpp SocketIO.cpp SocketIO.h
        ClientCommand.cpp ClientCommand.h
        ClassifyDataClientCommand.cpp DisplayResultClientCommand.cpp UploadClientCommand.cpp
        SettingClientCommand.cpp DownloadResultClientCommand.cpp)

