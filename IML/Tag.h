#pragma once
#include <string>
/// <summary>
/// During the Parser phase, when reading tokens, an instance of the class Tag is created when a token is tag_name. 
/// If there is additional information read about the tag from the tokens it's stored in here. 
/// The purpose of this class is only to keep information, and for easier management of tags. 
/// </summary>
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
	float getAdditionalInfoFloat()const { return additional_info_f; }
	const std::string& getAdditionalInfoString()const { return additional_info_s; }
	int getFrom()const { return from; }
	int getTo()const { return to; }
};