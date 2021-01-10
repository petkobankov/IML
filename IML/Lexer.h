#pragma once
#include <string>
#include <fstream>
#include "Token.h"
#include <queue>
class Lexer {
private:
	std::string inputFile;
	std::queue<Token> tokens;
	std::ifstream iFile;
	char previousState;
	Token currentToken;
	char currentInput;
public:
	Lexer(): inputFile(),tokens(),iFile(),currentInput(),previousState('n'){};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void start();
};