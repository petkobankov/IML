#include "Interpreter.h"
#include <iostream>
#include <fstream>
//<SRT-ORD "ASC">81 3<MAP-INC "1">4 12 55<AGG-AVG>4 8</AGG-AVG></MAP-INC>22</SRT-ORD>
Tag* Interpreter::createTag(const string& tagName)
{
	return nullptr;
}

Tag* Interpreter::removeTag(const string& tagName)
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
	bufferSize = buffer.size();
	enum class states { start, finish,invalid,number };
	states currentState = states::start;
	std::cout << start;
	int currentPosition = 0;
	while(currentPosition< bufferSize)
	{


	}
}
