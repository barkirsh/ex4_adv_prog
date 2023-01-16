//
// Created by barki on 1/16/2023.
//

#ifndef EX5_ADV_PROG_UPLOADCMDSERVER_H
#define EX5_ADV_PROG_UPLOADCMDSERVER_H
#include "Commands/Command.h"

class UploadCmdServer : Command {
private:
    string describtion = "upload command server";
    DefaultIO dio;
public:
    void execute(&ClientData cd);

};


#endif //EX5_ADV_PROG_UPLOADCMDSERVER_H
