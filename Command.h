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

using namespace std;

class Command{
protected:
    string description;
    DefaultIO dio;
public:
    Command();
    void execute();
};


#endif //EX4_COMMAND_H
