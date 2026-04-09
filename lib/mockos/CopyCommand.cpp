#include "mockos/CopyCommand.h"
#include "mockos/Constants.h"
#include <sstream>
#include <iostream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fileSystem)
    : fs(fileSystem) {}

void CopyCommand::displayInfo() {
    cout << "cp copys a file that exists in the file system and add the copy to the file system with a different name." << endl;
    cout << "cp can be invoked with cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string input) {
    if (input == "") {
        cout << "no filename" << endl;
        return cp_execute_fail;
    }
    istringstream iss(input);
    string existing, copied;
    iss >> existing >> copied;
    //extract the extension from existing file's name
    size_t dot = existing.find('.');
    if (dot == string::npos) {
        cout << "invalid source file name." << endl;
        return cp_execute_fail;
    }
    string extension = existing.substr(dot);
    copied = copied + extension;

    //open and copy the file
    AbstractFile* original = fs->openFile(existing);
    if (original == nullptr) {
        cout << "failed to open the original file." << endl;
        return cp_execute_fail;
    }
    AbstractFile* copy = original->clone(copied);
    fs->closeFile(original);
    if (copy == nullptr) {
        cout << "Clone failed" << endl;
        return cp_execute_fail;
    }

    if (fs->addFile(copied, copy) != 0) {
        delete copy;
        cout << "failed to add the copied file." << endl;
        return cp_execute_fail;
    }
    return success;
}