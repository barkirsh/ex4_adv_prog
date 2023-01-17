//
// Created by barki on 1/16/2023.
//

#ifndef EX5_ADV_PROG_UPLOADCMDSERVER_H
#define EX5_ADV_PROG_UPLOADCMDSERVER_H
#include "Command.h"

class UploadCmdServer : public Command {

public:
    UploadCmdServer(DefultIO io);
    void execute(ClientData &cd);

};


#endif //EX5_ADV_PROG_UPLOADCMDSERVER_H
