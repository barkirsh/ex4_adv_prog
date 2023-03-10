// Bar Kirshenboim & Noa Dolev

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
/**
 *
 * @return string from IO
 */
    virtual string read() = 0;

/**
 * write messege using IO type
 * @param message string
 */
    virtual void write(const std::string &message) = 0;
};


#endif //EX4_DEFAULTIO_H