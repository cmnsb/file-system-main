#include "mockos/RemoveCommand.h"
#include "mockos/Constants.h"
#include <iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSystem) :
    fs(fileSystem) {}

void RemoveCommand::displayInfo() {
    cout << "rm remove the file with the provided name from the file system" << endl;
    cout << "rm can be invoked with the command : rm <filename>" << endl;
}

int RemoveCommand::execute(string input) {
    //check the input is not empty
    if (input == "") {
        cout << "no filename" << endl;
        return rm_execute_fail;
    }
    //delete file from file system
    if (fs->deleteFile(input) == 0) {
        return success;
    }
    else {
        return rm_execute_fail;
    }
}