#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <string>

class MacroCommand : public AbstractCommand {
private:
    AbstractFileSystem* fs;
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* strategy;

public:
    MacroCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;
    void addCommand(AbstractCommand*); // adding individual commands
    void setParseStrategy(AbstractParsingStrategy*); // set the macro command¡¯s parsing strategy
};
