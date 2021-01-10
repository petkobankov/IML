#include "Lexer.h"

void Lexer::pushToken()
{
	tokens.push(currentToken);
}

void Lexer::updateToken()
{
	if (!is_token_empty()) 
		pushToken();
}

void Lexer::updateTokenData(t_type type, const char& data)
{
	if (type == t_type::empty || type == t_type::left_arrow || type == t_type::slash || type == t_type::right_arrow) {
		currentToken.type = type;
		currentToken.value = "";
	}
	else {
		if(is_token_empty())
			currentToken.type = type;
		currentToken.value.push_back(data);
	}
}

void Lexer::start()
{
	if (inputFile.empty()) {
		throw "Input file missing!";
	}
	iFile.open(inputFile);
	t_type currentType = t_type::empty;
	while (iFile.get(currentInput.getInput())) {
		if (currentInput.isSpace()) {
			currentType = t_type::empty;
			updateToken();
		}else if (currentInput.isDigit() || currentInput.isDot()) {
			currentType = t_type::number;
		}
		else if (currentInput.isDash()) {
			is_token_empty() ? currentType = t_type::number : currentType = t_type::string;
		}
		else if (currentInput.isUpperCase()) {
			currentType = t_type::string;
		}
		else if (currentInput.isLeftArrow()) {
			currentType = t_type::left_arrow;
			updateToken();
		}
		else if (currentInput.isRightArrow()) {
			currentType = t_type::right_arrow;
			updateToken();
		}
		else if (currentInput.isSlash()) {
			currentType = t_type::slash;
			updateToken();
		}
		else if (currentInput.isQuote()) {
			currentType = t_type::empty;
			updateToken();
		}
		updateTokenData(currentType, currentInput.getInput());
	}
	stop();
}
