//
// Created by nodo0 on 12/01/2023.
//

#ifndef EX4_DEFAULTIO_H
#define EX4_DEFAULTIO_H

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

using namespace std;

class DefaultIO {
public:
    //DefaultIO();

    virtual string read();
    void write(string str);
};


#endif //EX4_DEFAULTIO_H
