#pragma once
#include <queue>
#include "Token.h"
#include <string>
#include <vector>
#include <stack>
#include "Tag.h"
#include <queue>
#include "TagsManager.h"
/// <summary>
/// Validate if tag names exist, if the additional info for a tag is correct, if tag order is correct... When a tag is closed correctly the program executes it and continues reading the tokens.
/// Each tag is stored in a class called Tag. The class only stores what the program has read.
/// The tag is later checked for correction or execution usnig the class TagsManager.
/// The TagsManager stores the information for the markup langue. 
/// </summary>
class Parser {
	//Used for throwing exceptions. For example the tag order is incorrect or the program comes across an unknown tag name, we write the message in error_msg;
	std::string error_msg;
	//Used to keep track of open tags. When the program finds a closing tag, removes the top of the stack if they are the same, else error.
	//Execution is when we pop from stack
	std::stack<Tag> tag_order;
	Tag currentTag;
	bool is_in_tag=false;
	bool is_closing_tag=false;
	bool is_tag_name_expected=true;
	TagsManager manager;
	void reset_flags();

	void foundLeftArrow(Token& currentToken);
	void foundRightArrow(Token& currentToken, std::vector<float>& numbers);
	void foundSlash(Token& currentToken);
	void foundString(Token& currentToken);
	void foundNumber(Token& currentToken, std::vector<float>& numbers);
	void parseTokens(std::queue<Token>& tokens, std::vector<float>& numbers);
public:
	void start(std::queue<Token>& tokens, std::vector<float>& numbers);
};