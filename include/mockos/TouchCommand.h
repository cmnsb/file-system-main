#pragma once
#include "AbstractCommand.h"
#include "CommandPrompt.h"

class TouchCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;
    AbstractFileFactory* ff;

public:
    TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
    ~TouchCommand() = default;

    void displayInfo() override;
    int execute(std::string) override;
};
