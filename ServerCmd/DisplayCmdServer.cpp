//
// Created by barki on 1/17/2023.
//

#include "../Command.h"
DisplayCmdServer:: DisplayCmdServer(DefultIO io){
    this->description = "display- server";
    this->dio = io;
}