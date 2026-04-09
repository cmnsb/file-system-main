#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <sstream>

using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile* file) {
    if (files.find(fileName) != files.end()) {
        return file_exists;
    }
    if (file == nullptr) {
        return null_pointer;
    }
    files[fileName] = file;
    return success;
}

/*
int SimpleFileSystem::createFile(string fileName) {
    if (files.find(fileName) != files.end()) {
        return file_exists;
    }
    auto dot = fileName.find('.');
    if (dot == string::npos) {
        return invalid_extension;
    } 
    string extension = fileName.substr(dot + 1);

    AbstractFile* newFile = nullptr;
    if (extension == "txt") {
        newFile = new TextFile(fileName);
    }
    else if (extension == "img") {
        newFile = new ImageFile(fileName);
    }
    else {
        return invalid_extension;
    }
    files[fileName] = newFile;
    return success;
}
*/

AbstractFile* SimpleFileSystem::openFile(string fileName) {
    auto it = files.find(fileName);
    if (it == files.end()) {
        return nullptr;
    }
    AbstractFile* file = it->second;
    if (openFiles.find(file) != openFiles.end()) {
        return nullptr;
    }
    openFiles.insert(file);
    return file;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
    auto it = openFiles.find(file);
    if (it == openFiles.end()) {
        return file_not_exists;
    }
    openFiles.erase(it);
    return success;
}

int SimpleFileSystem::deleteFile(string fileName) {
    auto it = files.find(fileName);
    if (it == files.end()) {
        return file_not_exists;
    }
    AbstractFile* file = it->second;
    if (openFiles.find(file) != openFiles.end()) {
        return file_open;
    }
    delete file;
    files.erase(it);
    return success;
}

std::set<string> SimpleFileSystem::getFileNames() {
    set<string> fileNames;
    for (auto const& pair : files) {
        fileNames.insert(pair.first);
    }
    return fileNames;
}
