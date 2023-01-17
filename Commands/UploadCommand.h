//
// Created by nodo0 on 12/01/2023.
//

#ifndef EX4_UPLOADCOMMAND_H
#define EX4_UPLOADCOMMAND_H

#include "Command.h"
#include "../Dio's/StandardIO.h"

class UploadCommand : public Command {
public:
    UploadCommand(ClientData* cd, DefaultIO dio);
    void execute();
};


#endif //EX4_UPLOADCOMMAND_H
