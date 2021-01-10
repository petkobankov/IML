#pragma once
#include <string>
#include <fstream>
#include "Token.h"
#include <queue>
#include "InputSystem.h"
class Lexer {
private:
	std::string inputFile;
	std::queue<Token> tokens;
	std::ifstream iFile;
	char previousState;
	Token currentToken;
	InputSystem currentInput;
public:
	Lexer(): inputFile(),tokens(),iFile(),currentInput(),previousState('n'){};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void start();
};