#pragma once
#include <vector>
#include <string>
#include "Tag.h"
class TagMask {
	std::vector<std::string> additional_info_boundry;
	std::string name;
	char additional_info_type;
	
public:
	TagMask() = default;
	TagMask(const std::string& name, const char& additional_info_type, const std::vector<std::string>& additional_info_boundry) :name(name), additional_info_type(additional_info_type), additional_info_boundry(additional_info_boundry){}
	TagMask(const std::string& name, const char& additional_info_type) :name(name), additional_info_type(additional_info_type), additional_info_boundry(){}
	TagMask(const std::string& name) :name(name), additional_info_type('\0'), additional_info_boundry(){}
	const std::string& getName()const { return name; }
	bool hasSameName(const std::string& _name)const { return name == _name; }
	bool hasAdditionalInfoBoundry()const { return !additional_info_boundry.empty(); }
	char getAdditionalInfoType()const { return additional_info_type; }
	bool hasSameType(const char& _additional_info_type)const { return _additional_info_type == additional_info_type; }
	int getBoundrySize()const { return additional_info_boundry.size(); }
	bool isAdditionalInfoAccepted(const std::string& info)const;
};