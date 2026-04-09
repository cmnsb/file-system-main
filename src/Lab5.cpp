#include <iostream>
#include <ostream>

#include "mockos/AbstractCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/TcdParsingStrategy.h"
#include "mockos/MacroCommand.h"

#include <iostream>

using namespace std;

int main() {
    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    CommandPrompt cp;
    cp.setFileSystem(fs);
    cp.setFileFactory(ff);

    // configure all commands
    AbstractCommand* touch = new TouchCommand(fs, ff);
    AbstractCommand* ls = new LSCommand(fs);
    AbstractCommand* rm = new RemoveCommand(fs);
    AbstractCommand* cat = new CatCommand(fs);
    AbstractCommand* ds = new DisplayCommand(fs);
    AbstractCommand* copy = new CopyCommand(fs);

    // Macro command : rename rn
    MacroCommand* renameMacro = new MacroCommand(fs);
    AbstractParsingStrategy* renameStrategy = new RenameParsingStrategy();
    renameMacro->setParseStrategy(renameStrategy);
    renameMacro->addCommand(copy);
    renameMacro->addCommand(rm);
    
    // Macro command : touch + cat + ds, tcd
    MacroCommand* tcdMacro = new MacroCommand(fs);
    AbstractParsingStrategy* tcdStrategy = new TcdParsingStrategy();
    tcdMacro->setParseStrategy(tcdStrategy);
    tcdMacro->addCommand(touch);
    tcdMacro->addCommand(cat);
    tcdMacro->addCommand(ds);

    // configure command prompt
    cp.addCommand("touch", touch);
    cp.addCommand("ls", ls);
    cp.addCommand("rm", rm);
    cp.addCommand("cat", cat);
    cp.addCommand("ds", ds);
    cp.addCommand("cp", copy);
    cp.addCommand("rn", renameMacro);
    cp.addCommand("tcd", tcdMacro);
    cp.run();

    delete fs;
    delete ff;
    delete touch;
    delete ls;
    delete rm;
    delete cat;
    delete ds;
    delete copy;
    delete renameMacro;
    delete renameStrategy;
    delete tcdMacro;
    delete tcdStrategy;
}