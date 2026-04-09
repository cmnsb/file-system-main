#pragma once
#include "AbstractFile.h"
#include <string>

using namespace std;

class PasswordProxy : public AbstractFile {
private:
    AbstractFile* protectedFile;
    string password;

protected:
    string passwordPrompt();
    bool verifyPassword(const string& attempt) const;

public:
    PasswordProxy(AbstractFile*, string);
    virtual ~PasswordProxy();

    vector<char> read() override;
    int write(vector<char>) override;
    int append(vector<char>) override;
    unsigned int getSize() override;
    string getName() override;
    void accept(AbstractFileVisitor*) override;
    AbstractFile* clone(std::string) override;
};

