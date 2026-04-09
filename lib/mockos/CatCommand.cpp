#include "mockos/CatCommand.h"
#include "mockos/Constants.h"
#include <iostream>
#include <sstream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSystem) : 
	fs(fileSystem) {}

void CatCommand::displayInfo() {
    cout << "cat writes to a file, can be invoked with : cat <filename> [-a]" << endl;
    cout << "-a option can append the file with contents." << endl;
}

int CatCommand::execute(string input) {
    if (input == "") {
        cout << "no filename" << endl;
        return cat_execute_fail;
    }
    istringstream iss(input);
    string fileName, option;
    iss >> fileName >> option;
    AbstractFile* file = fs->openFile(fileName);
    if (file == nullptr) {
        cout << "failed to open file." << endl;
        return cat_execute_fail;
    }
    if (option == "-a") { // append option
        vector<char> contents = file->read();
        cout << fileName << endl;
        for (auto c : contents) { // display the contents
            cout << c;
        }
        cout << endl;
        cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
        string commandInput;
        vector<char> tempContents;
        while (getline(cin, commandInput)) {
            if (commandInput == ":wq") { // save append and exit
                int result = file->append(tempContents);
                fs->closeFile(file);
                return result;
            }
            else if (commandInput == ":q") { // exit without save 
                fs->closeFile(file);
                return success;
            }
            else {
                if (tempContents.empty() == false) {
                    tempContents.push_back('\n');
                }
                for (char c : commandInput) {
                    tempContents.push_back(c);
                }
            }
        }
    }
    else { // overwrite option
        cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
        string commandInput;
        vector<char> tempContents;
        while (getline(cin, commandInput)) {
            if (commandInput == ":wq") { // save append and exit
                tempContents.pop_back();
                int result = file->write(tempContents);
                fs->closeFile(file);
                return result;
            }
            else if (commandInput == ":q") { // exit without save
                fs->closeFile(file);
                return success;
            }
            else {
                for (char c : commandInput) {
                    tempContents.push_back(c);
                }
                tempContents.push_back('\n');
            }
        }
    }
    fs->closeFile(file);
    return cat_execute_fail;
}