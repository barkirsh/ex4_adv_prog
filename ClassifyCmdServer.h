//
// Created by barki on 1/17/2023.
//

#ifndef EX5_ADV_PROG_CLASSIFYCMDSERVER_H
#define EX5_ADV_PROG_CLASSIFYCMDSERVER_H

#include "Command.h"
class ClassifyCmdServer : public Command{

public:
    ClassifyCmdServer(DefaultIO &dio);
    void execute(ClientData &cd);
};


#endif //EX5_ADV_PROG_CLASSIFYCMDSERVER_H