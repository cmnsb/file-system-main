#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;

public:
    DisplayCommand(AbstractFileSystem*);
    ~DisplayCommand() = default;

    void displayInfo() override;
    int execute(std::string) override;
};