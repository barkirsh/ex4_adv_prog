// Bar Kirshenboim & Noa Dolev


#include "SocketIO.h"

SocketIO::SocketIO(int client_socket) {
    this->client_socket = client_socket;
}

void SocketIO::write(const std::string &message) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int sent_bytes;
    memset(buffer, 0, expected_data_len);
    strncpy(buffer, message.c_str(), sizeof(buffer));
    //buffer = message.c_str();
    // sending the messege
    sent_bytes = send(this->client_socket, buffer, expected_data_len, 0);

    if (sent_bytes < 0) {
        perror("error sending to client");
    }

}

string SocketIO::read() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes;
    memset(buffer, 0, expected_data_len);

    // receiving char* str[] of the user input(vector,dist,k) into buffer
    read_bytes = recv(this->client_socket, buffer, expected_data_len, 0);

    //something went wrong with receiving input from client - not our responsibility
    if (read_bytes == 0) {
        // connection is closed
        return "";
    } else if (read_bytes < 0) {
        perror("Error reading client message");
    } else {
        return buffer;
    }
    return "";
}

SocketIO::~SocketIO() {
    close(this->client_socket);
}