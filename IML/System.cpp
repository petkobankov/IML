#include "System.h"
#include <iostream>
#include <fstream>
void System::getInputFileName()
{
	std::cout << "Enter filename for the input: " << std::endl;
	char inputFileChar[1000];
	cin.getline(inputFileChar, 1000);
	inputFile = inputFileChar;
}
void System::getOutputFileName()
{
	std::cout << "Enter filename for the output: " << std::endl;
	char outputFileChar[1000];
	cin.getline(outputFileChar, 1000);
	outputFile = outputFileChar;
}

void System::validateInputFileName()
{
	fstream testInput(inputFile);
	if (testInput.fail()) {
		throw "Problem with opening input file. Either doesn't exist, incorrect spelling or missing extension.";
	}
	testInput.close();

}
void System::validateOutputFileName()
{
	fstream testOutput(outputFile);
	if (testOutput.fail()) {
		throw "Problem with opening output file. Either doesn't exist, incorrect spelling or missing extension.";
	}
	testOutput.close();

}

void System::interprateInput()
{
	inputFile = "input.txt"; // delete after testing
	mainInterpreter = Interpreter(inputFile);
	mainInterpreter.start();
}

void System::outputResult()
{
}

void System::start()
{
	//getInputFileName();
	//getOutputFileName();
	//validateInputFileName();
	//validateOutputFileName();
	interprateInput();
}
