#pragma once
#include "AbstractFile.h"
#include <vector>
#include <string>

class AbstractFileVisitor;
class TextFile : public AbstractFile {
protected:
	std::vector<char> contents;
	std::string name;
public:
	TextFile(std::string);
	vector<char> read() override;
	int write(std::vector<char>) override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor *) override;
	AbstractFile* clone(std::string) override;
	~TextFile() {}
};