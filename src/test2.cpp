#include <iostream>
#include "mockos/ImageFile.h"
#include <vector>
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"

using namespace std;

int main() {
    //testing ImageFile class
	ImageFile img("image.img");
	AbstractFile* p = &img;
    //testing general functions
    vector<char> contents = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	cout << "write method: " << p->write(contents) << endl;
	cout << "read method:" << endl;
	p->read();
	cout << "size: " << p->getSize() << endl;
	cout << "file name: " << p->getName() << endl;
    //testing append function
    vector<char> ap = { 'X' };
    cout << "No size input: " << p->append(ap) << endl;
    //testing size dismatch
    vector<char> badSize = { 'X', 'X', 'X', '3' };
    cout << "Bad size: " << p->write(badSize) << endl;
    //testing bad contents input
    vector<char> badContents = { 'T', '1' };
    cout << "Bad contents input: " << p->write(badContents) << endl;

    //testing SimpleFileSystem class
    SimpleFileSystem sfs;
    //addFile
    AbstractFile* tf = new TextFile("text.txt");
    cout << "addFile: " << sfs.addFile("text.txt", tf) << endl;
    //createFile
    cout << "createFile(img): " << sfs.createFile("image.img") << endl;
    //openFiles
    AbstractFile* imgf = sfs.openFile("image.img");
    imgf->write(contents);
    imgf->read();
    sfs.closeFile(imgf);
    //deleteFile 
    cout << "deleteFile: " << sfs.deleteFile("text.txt") << endl;
    cout << "deleteFile: " << sfs.deleteFile("image.img") << endl;
    return 0;
}
