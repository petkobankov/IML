#pragma once
#include <queue>
#include "Token.h"
#include <string>
#include <vector>
#include <stack>
#include "Tag.h"
#include <queue>

class Parser {
	//Used for throwing exceptions. For example the tag order is incorrect or the program comes across an unknown tag name, we write the message in error_msg;
	std::string error_msg;
	//Used to store all the numbers outside of tags. 
	std::vector<float> numbers;
	//Used to keep track of open tags. When the program finds a closing tag, removes the top of the stack if they are the same, else error.
	std::stack<Tag> tag_order;
	//When the program sees a closing tag and successfully removes an open tag from the stack, it pushes it in a queue for later excecution.
	std::queue<Tag> tag_excecution;
	Tag currentTag;
	bool is_in_tag=false;
	bool is_closing_tag=false;
	bool is_tag_name_expected=true;

	void reset_flags();
public:
	void start(std::queue<Token>& tokens);
};