#pragma once
#include <string>
#include "SyntaxChecker.h"
#include "Lexer.h"
#include "Parser.h"
///<summary>
/// Main system, controls everything. 
/// 
/// Main phases the program goes through:
/// Phase 1 - Get user input
/// Phase 2 - Validate if the filenames actually exist
/// Phase 3 - Check for any syntax errors. 
/// Phase 4 - Lexer - Recognize what each char is. The information is later stored in tokens - {type,value}
/// Phase 5 - Parser - Validate if tag names exist, if the additional info for a tag is correct, if tag order is correct... When a tag is closed correctly the program executes it and continues reading the tokens.
/// </summary>
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