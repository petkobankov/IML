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
	Token currentToken;
	InputSystem currentInput;
	void pushToken();
	void updateToken();
	void updateTokenData(t_type type, const char& data);
	void stop() { iFile.close(); }
	bool is_token_empty() { return currentToken.type == t_type::empty; }
	//void throw_error() { throw "Internal error."; }

public:
	Lexer() : inputFile(), tokens(), iFile(), currentInput(), currentToken{t_type::empty,""}{};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void start();
};