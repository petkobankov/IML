#pragma once
#include <string>
#include <vector>
using namespace std;
class Tag {
public:
	Tag():name(){};
	Tag(const string& name) :name(name) {};
	virtual bool hasAdditionalInput() { return false; };
	virtual const string& getName() { return name; };
	virtual const string& getAdditionalInputType() { return additionalInputType;};
	virtual void start(vector<float>& numbers,int startPos,int endPos) = 0;
protected:
	string name;
	string additionalInputType="null";
	bool hasAdditionalInput = false;
};