#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include <map>
#include <set>
#include <string>

class SimpleFileSystem : public AbstractFileSystem {
protected:
    std::map<std::string, AbstractFile*> files;
    std::set<AbstractFile*> openFiles;

public:
    int addFile(std::string, AbstractFile*) override;
    //int createFile(std::string) override;
    int deleteFile(std::string) override;
    AbstractFile* openFile(std::string) override;
    int closeFile(AbstractFile*) override;
    std::set<std::string> getFileNames() override;

    virtual ~SimpleFileSystem() = default;
};
