//
// Created by barki on 1/17/2023.
//

#ifndef EX5_ADV_PROG_DISPLAYCMDSERVER_H
#define EX5_ADV_PROG_DISPLAYCMDSERVER_H
#include "Command.h"

class DisplayCmdServer : public Command{

public:
    DisplayCmdServer(DefultIO io);
    void execute(ClientData &cd);
};


#endif //EX5_ADV_PROG_DISPLAYCMDSERVER_H
