#include "mockos/MacroCommand.h"
#include "mockos/Constants.h"
#include <iostream>

MacroCommand::MacroCommand(AbstractFileSystem* fileSystem) : fs(fileSystem), strategy(nullptr) {}

void MacroCommand::displayInfo() {
    std::cout << "MacroCommand executes a sequence of commands parsed from the input string" << std::endl;
}

void MacroCommand::addCommand(AbstractCommand* command) {
    commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* s) {
    strategy = s;
}


int MacroCommand::execute(std::string input) {
    if (strategy == nullptr) {
        cout << "There is no parsing strategy" << endl;
        return macro_parse_fail;
    }
    vector<string> parsedInputs = strategy->parse(input);
    if (parsedInputs.size() != commands.size()) {
        cout << "Parsed input size not match commands size" << endl;
        return macro_parse_fail;
    }

    for (auto i = 0; i < commands.size(); ++i) {
        int result = commands[i]->execute(parsedInputs[i]);
        if (result != 0) {
            return result;
        }
    }
    return success;
}