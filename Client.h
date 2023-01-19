//
// Created by oem on 1/19/23.
//

#ifndef EX4_ADV_CLIENT_H
#define EX4_ADV_CLIENT_H

#include "DefaultIO.h"
#include "SocketIO.h"
#include "clientCommands/ClientCommand.h"

using namespace std;

class Client {
    DefaultIO dio;
    int socket;


public:
    const int port; // port number
    ClientCommand* commands[6]{};
    Client(int socket, DefaultIO dio);
    void setSocket (int socket);
    int getSocket();
};


#endif //EX4_ADV_CLIENT_H
