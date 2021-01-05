#include "Interpreter.h"
#include <iostream>
#include <fstream>
Tag* Interpreter::createTag(const string& tagName)
{
	return nullptr;
}

void Interpreter::start()
{
	if (inputFile.empty()) {
		throw "Input file missing!";
	}
	ifstream iFile(inputFile);
	char input;
	while (iFile.get(input)) {
		buffer.push_back(input);
	}
	cout << buffer;
		

}
