//
// Created by oem on 1/19/23.
//

#ifndef EX4_ADV_CLIENT_H
#define EX4_ADV_CLIENT_H

#include "DefaultIO.h"
#include "SocketIO.h"
#include <pthread.h>

#include "ClientCommand.h"

using namespace std;

class Client {
    DefaultIO &dio; // the io element of client -> socketIO in our case
    int socket;     // the client socket


public:
    const int port; // port number
    ClientCommand *commands[6]{};   // commands of client
/**
 * client constructor
 * @param socket client socket
 * @param dio client IO
 */
    Client(int socket, DefaultIO &dio);

/**
 * setter
 * @param socket of client
 */
    void setSocket(int socket);

/**
 * getter client socket
 * @return client socket
 */
    int getSocket();
};


#endif //EX4_ADV_CLIENT_H