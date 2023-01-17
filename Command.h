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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Dio's/DefaultIO.h"
#include "Dio's/StandardIO.h"
#include "Dio's/SocketIO.h"
#include "ClientData.h"

using namespace std;

class Command {
protected:
    string description;
    DefaultIO &dio;

public:
    explicit Command(DefaultIO &dio) : dio(dio), description("Default Command") {}

    /**
     * execute the command.
     */
    virtual void execute(ClientData &cd) = 0;
};

class PrintCmd : public Command {
public:
    void execute(ClientData &cd);

    PrintCmd(DefaultIO &dio);
};

class UploadCmdServer : public Command {

public:
    UploadCmdServer(DefaultIO &dio);

    void execute(ClientData &cd);

};

class SettingCmdServer : public Command {

public:
    SettingCmdServer(DefaultIO &dio);

    void execute(ClientData &cd);
};

class ClassifyCmdServer : public Command {

public:
    ClassifyCmdServer(DefaultIO &dio);

    void execute(ClientData &cd);
};

class DisplayCmdServer : public Command {

public:
    DisplayCmdServer(DefaultIO &dio);

    void execute(ClientData &cd);
};

class DownloadCmdServer : public Command {

public:

    void execute(ClientData &cd);
};

#endif //EX4_COMMAND_H
