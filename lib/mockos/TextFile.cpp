#include "mockos/TextFile.h"
#include <iostream>

using namespace std;

TextFile::TextFile(std::string fileName) : name(fileName) {}

vector<char> TextFile::read() {
	// for (char c : contents) {
	// 	cout << c;
	// }
	// cout << endl;
	return contents;
}

int TextFile::write(std::vector<char> data) {
	contents = data;
	return 0;
}

int TextFile::append(std::vector<char> data) {
	for (char c : data) {
		contents.push_back(c);
	}
	return 0;
}

unsigned int TextFile::getSize() {
	return contents.size();
}

std::string TextFile::getName() {
	return name;
}

void TextFile::accept(AbstractFileVisitor *visitor) {
	visitor -> visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string newName) {
	AbstractFile* copy = new TextFile(newName);
	copy->write(this->read());
	return copy;
}