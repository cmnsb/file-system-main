#pragma once
#include "AbstractFile.h"
#include <vector>
#include <string>

class ImageFile : public AbstractFile {
protected:
	std::vector<char> contents;
	std::string name;
	int size;
public:
	ImageFile(std::string);

	vector<char> read() override;
	int write(std::vector<char>) override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor *) override;
	AbstractFile* clone(std::string) override;
	~ImageFile() {}
};
