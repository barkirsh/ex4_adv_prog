//
// Created by oem on 1/12/23.
//

#ifndef EX4_ADV_SETTINGCOMMAND_H
#define EX4_ADV_SETTINGCOMMAND_H

#include "Command.h"

class SettingCommand : public Command{
public:
    SettingCommand(ClientData* cd, DefaultIO dio);
    void execute();
    virtual bool KIsValid(string k);

    string strToUpper(string word);

    bool CurrStrIsDistance(string str);
};


#endif //EX4_ADV_SETTINGCOMMAND_H
