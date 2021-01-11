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
		throw MyException(e_type::error,"Problem with opening input file. Either doesn't exist, incorrect spelling or missing extension.");
	}
	testInput.close();

}
void System::validateOutputFileName()
{
	fstream testOutput(outputFile);
	if (testOutput.fail()) {
		throw MyException(e_type::error, "Problem with opening output file. Either doesn't exist, incorrect spelling or missing extension.");
	}
	testOutput.close();

}

void System::checkSyntax()
{
	inputSyntaxChecker.loadFile(inputFile);
	inputSyntaxChecker.checkSyntax();
}

void System::initiateLexer(std::queue<Token>& tokens)
{
	inputLexer.loadFile(inputFile);
	inputLexer.start(tokens);
}

void System::initiateParser(std::queue<Token>& tokens)
{
	inputParser.start(tokens,numbers);
}

void System::outputResult()
{
	ofstream oFile(outputFile, ios::trunc);
	std::vector<float>::iterator begin = numbers.begin();
	std::vector<float>::iterator end = numbers.end();
	for (std::vector<float>::iterator i = begin; i < end; i++)
	{
		oFile << *i << " ";
	}
	oFile.close();
}

void System::start()
{
	std::queue<Token> tokens;
	try {
		getInputFileName();
		getOutputFileName();
		validateInputFileName();
		validateOutputFileName();
		checkSyntax();
		initiateLexer(tokens);
		initiateParser(tokens);
		outputResult();
		cout << "Success! Check " << outputFile << " for the output." << endl;
	}
	catch (const MyException& e) {
		std::cout << e.getMessage() << std::endl;
	}
}
