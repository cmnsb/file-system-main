#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/Constants.h"
#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* fileSystem) : 
	fs(fileSystem) {}

//how to use ls command
void LSCommand::displayInfo() {
	cout << "ls lists all files in the file system. ls can be invoked with the command : ls" << endl;
	cout << "ls also support an additional option, -m, which will display a single file per line along with the metadata" << endl;
}

//execute implementation
int LSCommand::execute(string input) {
	set<string> names = fs->getFileNames();
	if (input == "") { // ls command
		auto it = names.begin();
		while (it != names.end()) {
			cout << left << setw(20) << *it;
			++it;
			if (it != names.end()) {
				cout << left << setw(20) << *it << endl;
				++it;
			}
			else {
				cout << endl;
			}
		}
	}
	else if (input == "-m") { // ls -m command
		MetadataDisplayVisitor mdv;
		for (auto it = names.begin(); it != names.end(); ++it) {
			AbstractFile* file = fs->openFile(*it);
			file->accept(&mdv);
			fs->closeFile(file);
		}
	}
	else {
		cout << "fail to list all files" << endl;
		return ls_execute_fail;
	}
	return success;
}