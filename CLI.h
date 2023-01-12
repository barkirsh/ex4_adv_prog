//
// Created by oem on 1/12/23.
//

#ifndef EX4_ADV_CLI_H
#define EX4_ADV_CLI_H

#include "Command.h"
#include "UploadCommand.h"
#include "SettingCommand.h"
#include "ClassifyDataCommand.h"
#include "DisplayResultsCommand.h"
#include "ClientData.h"

class CLI {
private:
    Command commands[6];
    ClientData cd;
public:

    CLI();
    void start();
};


#endif //EX4_ADV_CLI_H
