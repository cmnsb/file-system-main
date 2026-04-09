#pragma once
#include "AbstractCommand.h"
#include "CommandPrompt.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;

public:
    LSCommand(AbstractFileSystem*);
    ~LSCommand() = default;

    void displayInfo() override;
    int execute(std::string) override;
};
