#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <string>

using namespace std;

AbstractFile* SimpleFileFactory::createFile(string fileName) {
    auto dot = fileName.find('.');
    if (dot == string::npos) {
        return nullptr;
    }
    string extension = fileName.substr(dot + 1);
    if (extension == "txt") {
        return new TextFile(fileName);
    }
    else if (extension == "img") {
        return new ImageFile(fileName);
    }
    else {
        return nullptr;
    }
}