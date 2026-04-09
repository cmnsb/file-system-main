#include "mockos/RenameParsingStrategy.h"
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string input) {
    istringstream iss(input);
    string existingFileName, newName;
    iss >> existingFileName >> newName;
    
    vector<string> parsedInputs;
    // copy command input
    string copyInput = existingFileName + " " + newName;
    parsedInputs.push_back(copyInput);
    // remove command input
    string removeInput = existingFileName;
    parsedInputs.push_back(removeInput);

    return parsedInputs;
}