//
// Created by oem on 1/12/23.
//

#ifndef EX4_ADV_SERVERCLASS_H
#define EX4_ADV_SERVERCLASS_H

//#include "SocketIO.h"
#include "CLI.h"

class ServerClass {
private:
    const int port;
    const int sock;
public:
    explicit ServerClass(int port);

    void start();

    void handleClient(int client_socket);
};


#endif //EX4_ADV_SERVERCLASS_H