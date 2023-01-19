cmake_minimum_required(VERSION 3.24)
project(ex4_adv)

set(CMAKE_CXX_STANDARD 11)

add_executable(server ServerClass.cpp serverCommands/SettingCommand.cpp ServerClass.cpp ServerClass.h
        serverCommands/UploadCommand.cpp CLI.cpp CLI.h serverCommands/ClassifyDataCommand.cpp
        ClientData.cpp serverCommands/Command.cpp DefaultIO.h DefaultIO.cpp serverCommands/DisplayResultCommand.cpp
        Distances/Can.cpp Distances/Cheb.cpp DataSetsHandler.cpp Distances/Distance.cpp Distances/Euc.cpp
        Knn.cpp Distances/Man.cpp Distances/Minikovski.cpp SocketIO.cpp SocketIO.h serverCommands/DownloadResultCommand.cpp)

add_executable(client Client.cpp DefaultIO.h DefaultIO.cpp SocketIO.cpp SocketIO.h Client.cpp Client.h
        clientCommands/ClientCommand.cpp clientCommands/ClientCommand.h clientCommands/ClassifyDataClientCommand.cpp
        clientCommands/DisplayResultClientCommand.cpp clientCommands/UploadClientCommand.cpp
        clientCommands/SettingClientCommand.cpp clientCommands/DownloadResultClientCommand.cpp)
