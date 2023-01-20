//
// Created by oem on 1/19/23.
//

#ifndef EX4_ADV_CLIENTClientCommand_H
#define EX4_ADV_CLIENTClientCommand_H

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sstream>

#include "DefaultIO.h"
#include "StandardIO.h"
#include "ClientData.h"

using namespace std;

class ClientCommand{
protected:
    ClientCommand(DefaultIO &dio1);

    string description;
    DefaultIO &dio;
    public:
    ClientCommand();
    virtual void execute() = 0;
};

class UploadClientCommand : public ClientCommand {
public:
    explicit UploadClientCommand(DefaultIO &dio);
    void execute() override;
    bool fileHandler(ifstream &file);
};

class SettingClientCommand : public ClientCommand{
public:
    explicit SettingClientCommand(DefaultIO &dio);
    void execute() override;
};

class ClassifyDataClientCommand : public ClientCommand{
public:
    explicit ClassifyDataClientCommand(DefaultIO &dio);
    void execute() override;
};

class DisplayResultClientCommand : public ClientCommand{
public:
    explicit DisplayResultClientCommand(DefaultIO &dio);
    void execute() override;
};

class DownloadResultClientCommand : public ClientCommand{
public:
    explicit DownloadResultClientCommand(DefaultIO &dio);
    void execute() override;
};

#endif //EX4_ADV_CLIENTClientCommand_H
