#include "mockos/PasswordProxy.h"
#include "mockos/Constants.h"
#include <iostream>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* file, string pw) 
    : protectedFile(file), password(pw)
{}

PasswordProxy::~PasswordProxy() {
    delete protectedFile;
}

string PasswordProxy::passwordPrompt(){
    cout << "Enter password: ";
    string input;
    getline(cin, input);
    return input;
}

bool PasswordProxy::verifyPassword(const string& pw) const {
    return pw == password;
}

vector<char> PasswordProxy:: read() {
    if (verifyPassword(passwordPrompt())) {
        cout << "read successful" << endl;
        return protectedFile->read();
    }else {
        cout << "invalid password" << endl;
    }
    return {};
}

int PasswordProxy:: write(vector<char> contents) {
    if (verifyPassword(passwordPrompt())) {
        cout << "write successful" << endl;
        return protectedFile->write(contents);
    }
    cout << "invalid password" << endl;
    return ErrorPassword;
}

int PasswordProxy:: append(vector<char> contents) {
    if (verifyPassword(passwordPrompt())) {
        cout << "append successful" << endl;
        return protectedFile-> append(contents);
    }
    cout << "invalid password" << endl;
    return ErrorPassword;
}

unsigned int PasswordProxy::getSize() {
    return protectedFile->getSize();
}

string PasswordProxy::getName() {
    return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *visitor) {
    if (verifyPassword(passwordPrompt())) {
        cout << "accept successful" << endl;
        return protectedFile-> accept(visitor);
    }
    cout << "password prompt not accepted" << endl;
}

AbstractFile* PasswordProxy::clone(string newName) {
    AbstractFile* protectedClone = protectedFile->clone(newName);
    return new PasswordProxy(protectedClone, password);
}