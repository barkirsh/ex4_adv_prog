//
// Created by oem on 1/19/23.
//

#include <fstream>
#include "Client.h"
Client::Client(int socket,DefaultIO dio) : port(0) {
    this->dio = dio;
    this->socket = socket;

    this->commands[1] = new UploadClientCommand(this->dio);
    this->commands[2] = new SettingClientCommand(this->dio);
    this->commands[3] = new ClassifyDataClientCommand(this->dio);
    this->commands[4] = new DisplayResultClientCommand(this->dio);
}

void Client::setSocket(int socket) {
    this->socket = socket;
}

int Client::getSocket() {
    return this->socket;
}

bool isValidIP(const string& str) {
    // Split the string by the '.' delimiter
    stringstream ss(str);
    string token;
    int count = 0;
    while (getline(ss, token, '.')) {
        ++count;
        // If there are more or less than 4 tokens, it is not a valid IP address
        if (count > 4) {
            return false;
        }
        try {
            // Check that each token is a number between 0 and 255
            int num = stoi(token);
            if (num < 0 || num > 255) {
                return false;
            }
        }
        catch (...) {
            return false;
        }
    }
    // Return true if there are exactly 4 tokens
    return count == 4;
}

bool isValidPort(const string& str) {
    int portNum;
    try {
        portNum = stoi(str);
        if (portNum < 1024 || portNum > 65535) {
            return false;
        }
    }
    catch (const invalid_argument &ia) {
        return false;
    }
    return true;
}

bool checkArgs (int argc, char *argv[]) {
    // check that we got the right number of arguments.
    if (argc != 3) {
        perror("Wrong Input");
        exit(1);
    }
    bool checkIP = isValidIP(argv[1]);
    if (checkIP) {
        bool checkPort = isValidPort(argv[2]);
        if (checkPort) {
            return true;
        }
        return false;
    }
    return false;
}

int main(int argc, char *argv[]){
    if (!checkArgs(argc,argv)) {
        exit(1);
    }

    DefaultIO dio = *new StandardIO;
    Client c = *new Client(1,dio);

    const char *ip_address = argv[1];
    int port_no = stoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        // if the socket creation fails, print an error message
        perror("error creating socket");
        exit(1);
    }

    c.setSocket(sock);

    // set up the address of the server we want to connect to
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin)); // zero out the memory in sin
    sin.sin_family = AF_INET; // set the address family to AF_INET (IPv4)
    sin.sin_addr.s_addr = inet_addr(ip_address); // set the IP address
    sin.sin_port = htons(port_no); // set the port number

    // try to connect to the server
    if (connect(c.getSocket(), (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        // if the connection fails, print an error message
        perror("error connecting to server");
        exit(1);
    }


    while (true) {
        string fromServer = dio.read();

        // print the message
        cout << fromServer << endl;

        string str;
        getline(cin,str);

        c.commands[stoi(str)]->execute();
    }
}