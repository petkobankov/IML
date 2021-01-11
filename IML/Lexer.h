#pragma once
#include <string>
#include <fstream>
#include "Token.h"
#include <queue>
#include "InputSystem.h"
class Lexer {
private:
	std::string inputFile;
	std::ifstream iFile;
	Token currentToken;
	InputSystem currentInput;
	void pushToken(std::queue<Token>& tokens);
	void updateToken(std::queue<Token>& tokens);
	void updateTokenData(t_type type, const char& data, std::queue<Token>& tokens);
	void stop() { iFile.close(); }
	bool is_token(t_type type) { return currentToken.type == type; }
	bool is_token_empty() { return is_token(t_type::empty); }
	bool is_token_number() { return is_token(t_type::number); }
	bool is_token_string() { return is_token(t_type::string); }
	bool is_token_immediate() { return (is_token(t_type::left_arrow) || is_token(t_type::right_arrow) || is_token(t_type::slash)); }
	//void throw_error() { throw "Internal error."; }
	void immediate_update(std::queue<Token>& tokens);
public:
	Lexer() : inputFile(), iFile(), currentInput(), currentToken{t_type::empty,""}{};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void start(std::queue<Token>& tokens);
};