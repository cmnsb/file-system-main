#include <iostream>
#include <ostream>

#include "mockos/AbstractCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/TouchCommand.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>

using namespace std;

int main() {
    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    AbstractCommand* touch = new TouchCommand(fs, ff);

    CommandPrompt cp;
    cp.setFileSystem(fs);
    cp.setFileFactory(ff);
    cp.addCommand("touch", touch);
    cp.run();

    AbstractFile* f = fs->openFile("t.txt");
    if (f != nullptr) {
        cout << "file created successfully" << endl;
        fs->closeFile(f);
    }
    else {
        cout << "failed to created the file." << endl;
    }

    delete fs;
    delete ff;
    delete touch;
}