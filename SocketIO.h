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
    /**
     * Constructor of Socket IO
     */
    explicit SocketIO(int client_socket);

    /**
     * reading message from port
     * @return
     */
    string read() override ;

    /**
     * write messege to socket
     */
    void write(const std::string &message) override;

    ~SocketIO();
};


#endif //EX4_ADV_SOCKETIO_H