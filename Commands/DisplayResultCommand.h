#include "Command.h"


class DisplayResultCommand : public Command{
public:
    DisplayResultCommand(ClientData* cd, DefaultIO dio);
    void execute();
};

