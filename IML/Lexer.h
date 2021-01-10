#pragma once
#include <string>
#include <fstream>
#include "Token.h"
#include <vector>
#include "InputSystem.h"
class Lexer {
private:
	std::string inputFile;
	std::vector<Token> tokens;
	std::ifstream iFile;
	Token currentToken;
	InputSystem currentInput;
	void pushToken();
	void updateToken();
	void updateTokenData(t_type type, const char& data);
	void stop() { iFile.close(); }
	bool is_token(t_type type) { return currentToken.type == type; }
	bool is_token_empty() { return is_token(t_type::empty); }
	bool is_token_number() { return is_token(t_type::number); }
	bool is_token_string() { return is_token(t_type::string); }
	bool is_token_immediate() { return (is_token(t_type::left_arrow) || is_token(t_type::right_arrow) || is_token(t_type::slash)); }
	//void throw_error() { throw "Internal error."; }
	void immediate_update();
public:
	Lexer() : inputFile(), tokens(), iFile(), currentInput(), currentToken{t_type::empty,""}{};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void start();
	const std::vector<Token>& getTokens() { return tokens; }
};