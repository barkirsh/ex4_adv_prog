// Bar Kirshenboim & Noa Dolev

#ifndef EX4_ADV_CLI_H
#define EX4_ADV_CLI_H

#include "Command.h"

class CLI {
private:
    Command *commands[6]{}; // array of server commands
    ClientData *cd;         // refernce to client data
    DefaultIO &dio;         // the IO way we communicate
public:
    explicit CLI(DefaultIO &dio);

/**
 * func that responsible for menu
 */
    void menu();

/**
 * func for handle the server side process
 */
    void start();

/**
 * free space of commands allocations
 */
    void deleteAll();
};

#endif //EX4_ADV_CLI_H