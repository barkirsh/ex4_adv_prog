//
// Created by oem on 1/12/23.
//

#ifndef EX4_ADV_CLI_H
#define EX4_ADV_CLI_H

#include "Command.h"
//#include "DefaultIO.h"
//#include "ClientData.h"

class CLI {
private:
    Command* commands[6]{};
    ClientData *cd;
    DefaultIO &dio;
public:
    explicit CLI(DefaultIO &dio);
    void menu();
    void start();
    void deleteAll();
};


#endif //EX4_ADV_CLI_H
