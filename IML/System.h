#pragma once
#include <string>
#include "SyntaxChecker.h"
#include "Lexer.h"
#include "Parser.h"
using namespace std;
class System {
private:
	string inputFile;
	string outputFile;
	SyntaxChecker inputSyntaxChecker;
	Lexer inputLexer;
	Parser inputParser;
	std::vector<float> numbers;
	void getOutputFileName();
	void getInputFileName();
	void validateInputFileName();
	void validateOutputFileName();
	void checkSyntax();
	void initiateLexer(std::queue<Token>& tokens);
	void initiateParser(std::queue<Token>& tokens);
	void outputResult();
public:
	void start();
};