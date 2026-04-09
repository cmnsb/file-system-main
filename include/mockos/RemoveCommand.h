#pragma once
#include "AbstractCommand.h"
#include "CommandPrompt.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;

public:
    RemoveCommand(AbstractFileSystem* fileSystem);
    ~RemoveCommand() = default;

    void displayInfo() override;
    int execute(std::string input) override;
};