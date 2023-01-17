//
// Created by nodo0 on 12/01/2023.
//

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "DefaultIO.h"
#include "StandardIO.h"
#include "SocketIO.h"
#include "ClientData.h"

using namespace std;

class Command{
protected:
    string description;
    DefaultIO dio;

public:
    /**
     * execute the command.
     */
    virtual void execute(ClientData &cd) = 0;
};


#endif //EX4_COMMAND_H