//
// Created by barki on 1/13/2023.
//

#ifndef EX4_ADV_SOCKETIO_H
#define EX4_ADV_SOCKETIO_H
#include "DefaultIO.h"

class SocketIO : public DefaultIO {
private:
    int client_socket;
public:
    SocketIO(int client_socket);
    string read();
    void write(std::string &message);
};


#endif //EX4_ADV_SOCKETIO_H
