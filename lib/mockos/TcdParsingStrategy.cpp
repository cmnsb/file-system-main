#include "mockos/TcdParsingStrategy.h"
#include <sstream>

using namespace std;

vector<string> TcdParsingStrategy::parse(string input) {
    istringstream iss(input);
    string fileName;
    iss >> fileName;

    vector<string> parsedInputs;
    // touch command input
    parsedInputs.push_back(fileName);
    // cat command input
    parsedInputs.push_back(fileName);
    // ds command input
    parsedInputs.push_back(fileName);
    return parsedInputs;
}