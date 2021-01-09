#pragma once
#include <string>

enum class t_type {left_arrow,right_arrow,number,tag_name,tag_info};
struct Token {
	t_type type;
	std::string value;
};