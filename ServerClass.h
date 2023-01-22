// Bar Kirshenboim & Noa Dolev


#ifndef EX4_ADV_SERVERCLASS_H
#define EX4_ADV_SERVERCLASS_H

//#include "SocketIO.h"
#include "CLI.h"
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>


class ServerClass {
private:
    const int port;
    const int sock;
    //std::vector<std::thread> threads;

public:
    explicit ServerClass(int port);

    void start();
/*
    void * handleClient(void* client_socket);
*/
};