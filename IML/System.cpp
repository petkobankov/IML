#include "System.h"
#include <iostream>
#include <fstream>
#include "MyException.h"
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

void System::checkSyntax()
{
	inputFile = "input.txt"; // delete after testing
	inputSyntaxChecker.loadFile(inputFile);
	inputSyntaxChecker.checkSyntax();
}

void System::initiateLexer()
{
	inputLexer.loadFile(inputFile);
	inputLexer.start();
}

void System::initiateParser()
{

}

void System::outputResult()
{

}

void System::start()
{
	
	try {
		//getInputFileName();
		//getOutputFileName();
		//validateInputFileName();
		//validateOutputFileName();
		checkSyntax();
		initiateLexer();
		initiateParser();
	}
	catch (const MyException& e) {
		std::cout << e.getMessage() << std::endl;
	}
	
}
