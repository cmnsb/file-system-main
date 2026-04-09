#pragma once
#include <map>
#include "AbstractFile.h"
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

using namespace std;

class CommandPrompt{
private:
    map<string, AbstractCommand*> commands;
    AbstractFileFactory* ff;
    AbstractFileSystem* fs;

    protected:
    void listCommands() const;
    string prompt() const;

    public:
    CommandPrompt(); 
    ~CommandPrompt() = default;

    void setFileSystem(AbstractFileSystem*);
    void setFileFactory(AbstractFileFactory*);
    int addCommand(string, AbstractCommand*);
    int run();
};