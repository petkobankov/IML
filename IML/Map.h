#pragma once
#include "Tag.h"
class Map : public Tag {
private:
	
public:
	Map() = default;
	Map(const string & name) : Tag(name) {};
	void start(vector<float>& numbers, int startPos, int endPos);

};