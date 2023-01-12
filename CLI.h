//
// Created by oem on 1/12/23.
//

#ifndef EX4_ADV_CLI_H
#define EX4_ADV_CLI_H

#include "Command.h"
#include "UploadCommand.h"
#include "SettingCommand.h"

class CLI {
public:
    Command commands[6];
    CLI();
    void start();
};


#endif //EX4_ADV_CLI_H
