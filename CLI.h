//
// Created by oem on 1/12/23.
//

#ifndef EX4_ADV_CLI_H
#define EX4_ADV_CLI_H

#include "Command.h"
#include "Commands/UploadCommand.h"
#include "Commands/SettingCommand.h"
#include "Commands/ClassifyDataCommand.h"
#include "Commands/DisplayResultCommand.h"
#include "ClientData.h"

class CLI {
private:
    Command* commands[6];
    ClientData *cd;
    DefaultIO dio;
public:
    CLI(DefaultIO dio);
    void menu();
    void start();
};


#endif //EX4_ADV_CLI_H
