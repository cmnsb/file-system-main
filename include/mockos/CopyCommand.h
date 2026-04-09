#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;

public:
    CopyCommand(AbstractFileSystem*);
    ~CopyCommand() = default;

    void displayInfo() override;
    int execute(std::string input) override;
};