#pragma once
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"
using namespace  std;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;

	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(std::string) = 0;
	virtual ~AbstractFile() {}
};