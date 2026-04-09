#pragma once
#include "AbstractFileFactory.h"
#include <string>

class SimpleFileFactory : public AbstractFileFactory {
public:
    AbstractFile* createFile(std::string) override;
};