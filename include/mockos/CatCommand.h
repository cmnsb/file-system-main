#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;

public:
    CatCommand(AbstractFileSystem*);
    ~CatCommand() = default;

    void displayInfo() override;
    int execute(std::string) override;
};