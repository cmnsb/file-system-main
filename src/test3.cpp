#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	AbstractFileSystem* fs = new SimpleFileSystem();
	AbstractFileFactory* ff = new SimpleFileFactory();
	AbstractFile* f1 = ff->createFile("text.txt");
	AbstractFile* f2 = ff->createFile("image.img");
    fs->addFile("text.txt", f1);
    fs->addFile("image.img", f2);

    AbstractFile* txt = fs->openFile("text.txt");
    txt->write({ 'H','e','l','l','o' });
    txt->read();
    fs->closeFile(txt);

    AbstractFile* img = fs->openFile("image.img");
    img->write({ 'X',' ','X',' ','X',' ','X',' ','X','3' });
    img->read();
    fs->closeFile(img);

    delete fs;
    delete ff;
}