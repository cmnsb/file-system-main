#include <iostream>
#include "mockos/TextFile.h"
#include <vector>

using namespace std;

int main() {
    //testing TextFile class
    TextFile f("test.txt");
    AbstractFile* p = &f; //using pointer with static type AbstractFile

    //testing write function
    vector<char> data = { 'Z', 'h', 'o', 'u' };
    cout << p->write(data) << endl;
    cout << "size of f: " << p->getSize() << endl;
    cout << "file name: " << p->getName() << endl;
    //testing read function
    p->read();

    //testing append function
    vector<char> data2 = { 'Z', 'h', 'a', 'n', 'r', 'u', 'i'};
    cout << p->append(data2) << endl;
    p->read();

    return 0;
}