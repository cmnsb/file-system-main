#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <iostream>

using namespace std;

ImageFile::ImageFile(std::string fileName) : name(fileName), size(0) {}

vector<char> ImageFile::read() {
	// for (int y = size - 1; y >= 0; --y) {
	// 	for (int x = 0; x < size; ++x) {
	// 		cout << contents[y * size + x];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	return contents;
}

int ImageFile::write(std::vector<char> data) {
    // ignore all the '\n' in data
    data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());

    if (data.size() < 1) {
        return empty_size;
    }
    //user input size
    int s = (int)(data.back() - '0');
    //check size match
    if (data.size() - 1 != s * s) {
        return size_not_match;
    }
    //check only contain 'X' and ' '
    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {
            contents.clear();
            size = 0;
            return bad_content;
        }
    }
    contents.assign(data.begin(), data.end() - 1);
    size = s;
    return success;
}

int ImageFile::append(std::vector<char> data) {
	return Image_cannot_append;
}

unsigned int ImageFile::getSize() {
	return contents.size();
}

std::string ImageFile::getName() {
	return name;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor -> visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string newName) {
    AbstractFile* copy = new ImageFile(newName);
    vector<char> content = this->read();
    content.push_back('0' + this->size);
    copy->write(content);
    return copy;
}