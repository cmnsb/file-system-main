#include "mockos/TouchCommand.h"
#include "mockos/Constants.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fileSystem, AbstractFileFactory* fileFactory)
    : fs(fileSystem), ff(fileFactory) 
{}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, invoked with the command: touch <filename>" << endl;
    cout << "touch creates a password protected file, invoked with: touch <filename> -p" << endl;
}

int TouchCommand::execute(string input) {
    if (input == "") {
        cout << "no filename" << endl;
        return touch_execute_fail;
    }
    istringstream iss(input);
    string fileName, pw;
    iss >> fileName >> pw;
    AbstractFile* file = ff -> createFile(fileName);
    if (file == nullptr) {
        cout << "failed to create file" << endl;
        return ErrorCreateFile;
    }
    if (pw == "-p") {
        cout << "What is the password? " << endl;
        string password;
        getline(cin, password);
        AbstractFile* proxy = new PasswordProxy(file, password);
        int result = fs->addFile(fileName, proxy);
        if (result != 0) {
            delete proxy;
            cout << "failed to add a password protected file" << endl;
            return ErrorAddFile;
        }
    }
    else {
        if (fs -> addFile(fileName, file) != 0) {
            delete file;
            cout << "failed to add file" << endl;
            return ErrorAddFile;
        }    
    }
    return success;
}


