#pragma once
#include <string>
class Tag {
	std::string name;
	float additional_info_f;
	std::string additional_info_s;
	bool has_additional = false;
	int id=-1;
	int from;
	int to;
public:
	const std::string& getName()const { return name; }
	void setName(const std::string& _name) { name = _name; }
	void setAdditionalInfoStr(const std::string& _additional_info_s);
	void setAdditionalInfoFloat(float _additional_info_f);
	bool hasAdditionalInfo()const { return has_additional; }
	bool hasId()const { return id != -1; }
	void setId(int _id) { id = _id; }
	int getId()const { return id; }
	void setFrom(int _from) { from = _from; }
	void setTo(int _to) { to = _to; }
};