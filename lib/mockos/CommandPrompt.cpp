#include "mockos/CommandPrompt.h"
#include "mockos/AbstractCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt() : 
    fs(nullptr), ff(nullptr) 
{}

void CommandPrompt::setFileFactory(AbstractFileFactory* fileFactory) {
    ff = fileFactory;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* fileSystem) {
    fs = fileSystem;
}

int CommandPrompt::addCommand(string name, AbstractCommand* command) {
    auto result = commands.insert({ name, command });
    if (result.second) {
        return 0;
    }
    else {
        return 1;
    }
}

void CommandPrompt::listCommands() const{
    cout << "list of all available commands: " << endl;
    for (auto it : commands) {
        cout << it.first << endl;
    }
}

string CommandPrompt::prompt() const {
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
    cout << "$  ";
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt::run() {
    while (true) {
        string input = prompt();
        //user quit
        if (input == "q") {
            return 2;
        }
        //help for a list of commands
        else if (input == "help") {
            listCommands();
            continue;
        }
        else {
            size_t i = input.find(' ');
            //input is 1 word long
            if (i == string::npos) {
                auto it = commands.find(input);
                if (it != commands.end()) {
                    int r = it->second->execute("");
                    if (r != 0) {
                        cout << "return value: " << r << endl;
                        cout << "command execution fail." << endl;
                    }
                }
                else {
                    cout << "command not found." << endl;
                }
            }
            //input is longer than 1 word
            else {
                istringstream iss(input);
                string word1, word2;
                iss >> word1;
                if (word1 == "help") {
                    iss >> word2;
                    auto it = commands.find(word2);
                    if (it != commands.end()) {
                        it->second->displayInfo();
                    }
                    else {
                        cout << "command not found." << endl;
                    }
                }
                else {
                    auto it = commands.find(word1);
                    if (it != commands.end()) {
                        string rest = input.substr(word1.length() + 1);
                        int re = it->second->execute(rest);
                        if (re != 0) {
                            cout << "return value: " << re << endl;
                            cout << "command execution fail." << endl;
                        }
                    }
                    else {
                        cout << "command not found." << endl;
                    }
                }
            }
        }
    }
}

