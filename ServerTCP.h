//
// Created by barki on 1/13/2023.
//

#ifndef EX4_ADV_SERVERTCP_H
#define EX4_ADV_SERVERTCP_H

#include "../ValidationClient.h"
class ServerTCP {
private:
    const int server_port;
    const int _sock;
    // vector of client threads.
    std::vector<std::thread> clients_threads;

public:
    ServerTCP(int server_port);
    void newClient(int client_socket);
    void runClient(int client_socket);
    void listen();
};


#endif //EX4_ADV_SERVERTCP_H
