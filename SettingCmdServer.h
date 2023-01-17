//
// Created by barki on 1/17/2023.
//

#ifndef EX5_ADV_PROG_SETTINGCMDSERVER_H
#define EX5_ADV_PROG_SETTINGCMDSERVER_H
#include "Command.h"

class SettingCmdServer : public Command {

public:
    SettingCmdServer(DefultIO io);
    void execute(ClientData &cd);
};


#endif //EX5_ADV_PROG_SETTINGCMDSERVER_H
