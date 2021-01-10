#pragma once
#include <string>
//start_tag - <
//end_tag - </
//right_arrow - >
//element - number between tags
//tag_name - name of a tag
//tag_info - the additional info of a tag between ""

enum class t_type {left_arrow,right_arrow,slash,number,string,empty};
struct Token {
	t_type type;
	std::string value;
};