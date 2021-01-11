#include "Parser.h"

void Parser::reset_flags()
{
	is_in_tag = false;
	is_closing_tag = false;
	is_tag_name_expected = true;
}

void Parser::start(std::queue<Token>& tokens)
{
	while (!tokens.empty()) {
		Token& currentToken = tokens.front();
		tokens.pop();
		switch (currentToken.type)
		{
		case t_type::left_arrow:
			is_in_tag = true;
			break;
		case t_type::right_arrow:
			reset_flags();
			break;
		case t_type::slash:
			is_closing_tag = true;
			break;
		case t_type::number:
			break;
		case t_type::string:

			break;
		case t_type::empty:
			break;
		default:
			break;
		}
	}
}
