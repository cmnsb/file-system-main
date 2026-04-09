#pragma once
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
    virtual AbstractFile* createFile(std::string) = 0;
    virtual ~AbstractFileFactory() = default;
};