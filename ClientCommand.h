// Bar Kirshenboim & Noa Dolev

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
#include <pthread.h>

#include "DefaultIO.h"
#include "StandardIO.h"
#include "ClientData.h"

using namespace std;

class ClientCommand {
protected:
    /**
     * constructor of client command
     * @param dio1  - IO
     */
    ClientCommand(DefaultIO &dio1);


    string description;
    DefaultIO &dio;

public:
/**
 * responsible for executing this command
 */
    virtual void execute() = 0;
};

class UploadClientCommand : public ClientCommand {
public:

    /**
     * constructor uploading
     * @param dio   io
     */
    explicit UploadClientCommand(DefaultIO &dio);

    void execute() override;

    void fileHandler(ifstream &file);
};

class SettingClientCommand : public ClientCommand {
public:

    /**
     * constructor settings
     * @param dio   io
     */
    explicit SettingClientCommand(DefaultIO &dio);

    void execute() override;
};

class ClassifyDataClientCommand : public ClientCommand {
public:

    /**
     * constructor classify
     * @param dio   io
     */
    explicit ClassifyDataClientCommand(DefaultIO &dio);

    void execute() override;
};

class DisplayResultClientCommand : public ClientCommand {
public:

    /**
     * constructor display
     * @param dio   io
     */
    explicit DisplayResultClientCommand(DefaultIO &dio);

    void execute() override;
};

class DownloadResultClientCommand : public ClientCommand {
public:

    /**
     * constructor downloading
     * @param dio   io
     */
    explicit DownloadResultClientCommand(DefaultIO &dio);



    void execute() override;


};

#endif //EX4_ADV_CLIENTClientCommand_H