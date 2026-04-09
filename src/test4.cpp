#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/AbstractFileVisitor.h"
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
    txt->write({'H','e','l','l','o'});
    AbstractFile* img = fs->openFile("image.img");
    img->write({'X',' ','X',' ','X',' ','X',' ','X','3'});

    BasicDisplayVisitor bdv;
    txt->accept(&bdv);
    img->accept(&bdv);

    MetadataDisplayVisitor mdv;
    txt->accept(&mdv);
    img->accept(&mdv);

    fs->closeFile(txt);
    fs->closeFile(img);
    delete fs;
    delete ff;
}