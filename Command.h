//
// Created by nodo0 on 12/01/2023.
//

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sstream>

#include "SocketIO.h"
#include "ClientData.h"

using namespace std;

class Command {
protected:

    string description;
    DefaultIO &dio;
    ClientData *cd;
public:
    Command(DefaultIO &dio1);

    virtual void execute() = 0;
};

class ClassifyDataCommand : public Command {
public:
    ClassifyDataCommand(DefaultIO &dio1, ClientData *cd);

    void execute() override;
};

class DisplayResultCommand : public Command {
public:
    DisplayResultCommand(DefaultIO &dio1, ClientData *cd);

    void execute() override;
};

class DownloadResultCommand : public Command {
public:
    DownloadResultCommand(DefaultIO &dio1, ClientData *cd);

    void execute() override;
};

class SettingCommand : public Command {
public:
    SettingCommand(DefaultIO &dio1, ClientData *cd);

    void execute() override;

    bool KIsValid(string k);

    string strToUpper(string word);

    bool CurrStrIsDistance(string str);
};

class UploadCommand : public Command {
public:
    UploadCommand(DefaultIO &dio1, ClientData *cd);

    void execute() override;
};

#endif //EX4_COMMAND_H