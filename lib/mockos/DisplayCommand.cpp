#include "mockos/DisplayCommand.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/Constants.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSystem) :
	fs(fileSystem) {}

void DisplayCommand::displayInfo() {
	cout << "ds displays the contents of the file, and can be invoked with the command: ds <filename> [-d]" << endl;
	cout << "-d option for unformatted data only" << endl;
}

int DisplayCommand::execute(string input) {
    if (input == "") {
        cout << "no filename" << endl;
        return ds_execute_fail;
    }
    istringstream iss(input);
    string fileName, option;
    iss >> fileName >> option;
    AbstractFile* file = fs->openFile(fileName);
    if (file == nullptr) {
        cout << "failed to open the file" << endl;
        return ds_execute_fail;
    }
    if (option == "-d") { // unformatted data display
        vector<char> contents = file->read();
        for (char c : contents) {
            cout << c;
        }
        cout << endl;
    }
    else { // formatted data display
        BasicDisplayVisitor bdv;
        file->accept(&bdv);
    }
    fs->closeFile(file);
    return success;
}