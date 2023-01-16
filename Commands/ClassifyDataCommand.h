
#ifndef EX4_ClassifyDataCommand_H
#define EX4_ClassifyDataCommand_H


# include "Command.h"
#include "Knn.h"

class ClassifyDataCommand : public Command{
public:
    ClassifyDataCommand(ClientData* cd, DefaultIO dio);
    void execute();
};

#endif //EX4_ClassifyDataCommand_H