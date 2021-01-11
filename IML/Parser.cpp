#include "Parser.h"
#include "MyException.h"

void Parser::reset_flags()
{
	is_in_tag = false;
	is_closing_tag = false;
	is_tag_name_expected = true;
}

void Parser::foundLeftArrow(Token& currentToken)
{
	is_in_tag = true;
}

void Parser::foundRightArrow(Token& currentToken)
{
	if (!is_closing_tag) {
		currentTag.setFrom(numbers.size());
		tag_order.push(currentTag);
		currentTag = Tag();
	}
	else {
		if (tag_order.empty() || currentTag.getName() != tag_order.top().getName()) {
			throw MyException(e_type::parser, "Tag order is incorrect.");
		}
		else {
			tag_excecution.push(tag_order.top());
			tag_excecution.back().setTo(numbers.size() - 1);
			tag_order.pop();
		}
	}
	reset_flags();
	
}

void Parser::foundSlash(Token& currentToken)
{
	is_closing_tag = true;
}

void Parser::foundString(Token& currentToken)
{
	if (is_in_tag && is_tag_name_expected) {
		currentTag.setName(currentToken.value);
		if (!manager.doesTagExist(currentTag))
			throw MyException(e_type::parser, "Tag name " + currentToken.value + " does not exist.");
		
		is_tag_name_expected = false;
	}
	else if (is_in_tag && !is_tag_name_expected) {
		if (manager.isAdditionalInfoCorrect(currentToken.value, currentTag.getId())) {
			currentTag.setAdditionalInfoStr(currentToken.value);
		}
		else {
			throw MyException(e_type::parser, "Tag name " + currentTag.getName() + " incompatible with additional info '" + currentToken.value + "'.");
		}
		
	}
}

void Parser::foundNumber(Token& currentToken)
{
	float current_num = -1;
	try {
		current_num = std::stof(currentToken.value);
	}
	catch (const std::exception& e) {
		throw MyException(e_type::error, "Couldn't read number.");
	}

	if (!is_in_tag) {
		numbers.push_back(current_num);
	}
	else if (is_in_tag && !is_tag_name_expected) {
		if (manager.isAdditionalInfoCorrect(current_num, currentTag.getId())) {
			currentTag.setAdditionalInfoFloat(current_num);
		}
		else {
			throw MyException(e_type::parser, "Tag name '" + currentTag.getName() + "' incompatible with additional info '" + currentToken.value + "'.");
		}
	}
}

void Parser::parseTokens(std::queue<Token>& tokens)
{
	while (!tokens.empty()) {
		Token& currentToken = tokens.front();

		switch (currentToken.type)
		{
		case t_type::left_arrow:
			foundLeftArrow(currentToken);
			break;
		case t_type::right_arrow:
			foundRightArrow(currentToken);
			break;
		case t_type::slash:
			foundSlash(currentToken);
			break;
		case t_type::number:
			foundNumber(currentToken);
			break;
		case t_type::string:
			foundString(currentToken);
			break;
		default:
			break;
		}
		tokens.pop();
	}
}

void Parser::start(std::queue<Token>& tokens)
{
	parseTokens(tokens);
	
}
