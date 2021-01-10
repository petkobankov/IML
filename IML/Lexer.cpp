#include "Lexer.h"
#include "MyException.h"
void Lexer::pushToken()
{
	tokens.push_back(currentToken);
}

void Lexer::updateToken()
{
	if (!is_token_empty()) 
		pushToken();
}

void Lexer::updateTokenData(t_type type, const char& data=' ')
{
	if (type == t_type::empty || type == t_type::left_arrow || type == t_type::slash || type == t_type::right_arrow) {
		updateToken();
		currentToken.type = type;
		currentToken.value = "";
	}
	else {
		if(is_token_empty())
			currentToken.type = type;
		currentToken.value.push_back(data);
	}
}

void Lexer::immediate_update()
{
	if (is_token_immediate()) {
		updateTokenData(t_type::empty);
	}
}

void Lexer::start()
{

	if (inputFile.empty()) {
		throw MyException(e_type::error, "Input file missing!");
	}
	tokens = std::vector<Token>();
	iFile.open(inputFile);
	t_type currentType = t_type::empty;
	bool needsAdditionalUpdate = false;
	while (iFile.get(currentInput.getInput())) {
		immediate_update();
		if (currentInput.isSpace()) {
			currentType = t_type::empty;
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
		}
		else if (currentInput.isRightArrow()) {
			currentType = t_type::right_arrow;
		}
		else if (currentInput.isSlash()) {
			currentType = t_type::slash;
		}
		else if (currentInput.isQuote()) {
			currentType = t_type::empty;
			
		}
		updateTokenData(currentType, currentInput.getInput());
	}
	updateToken();
	stop();
}
