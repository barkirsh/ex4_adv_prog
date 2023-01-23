// Bar Kirshenboim & Noa Dolev


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
    /**
     * constructor
     * @param dio1 IO
     * @param cd Client Data
     */
    SettingCommand(DefaultIO &dio1, ClientData *cd);

/**
 * executing command
 */
    void execute() override;

/**
 * check if k is int >= 0
 * @param k val
 * @return true if int>=0, false otherwise
 */
    bool KIsValid(string k);

/**
 * uppercasing word's letters
 * @param word the word
 * @return uppercased word
 */
    string strToUpper(string word);

/**
 * check if str is word with letters for a metric type
 * @param str  string
 * @return true if is, else - false
 */
    bool CurrStrIsDistance(string str);
};

class UploadCommand : public Command {
public:
    UploadCommand(DefaultIO &dio1, ClientData *cd);

    void execute() override;
};

#endif //EX4_COMMAND_H