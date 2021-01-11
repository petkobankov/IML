#pragma once
#include <string>
class Tag {
	std::string name;
	float additional_info_f;
	std::string additional_info_s;
public:
	const std::string& getName() { return name; }
};