cmake_minimum_required(VERSION 3.22)
project(ex5_adv_prog)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex5_adv_prog Commands/ClassifyDataCommand.h Commands/ClassifyDataCommand.h Commands/Command.cpp Commands/Command.h DefaultIO.cpp StandardIO.cpp StandardIO.h StandardIO.h Commands/DisplayResultCommand.cpp Commands/ClassifyDataCommand.cpp Distances/Can.cpp Commands/DisplayResultsCommand.h "lastProjectFiles - Knn,DataSetHandle,Validation,Server,Client/Knn.h" Commands/ClientData.cpp Commands/ClientData.h)
