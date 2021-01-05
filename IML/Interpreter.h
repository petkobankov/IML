#pragma once
#include <string>
#include <vector>
#include <stack>
#include "Tag.h"
using namespace std;
class Interpreter {
private:
	string inputFile;
	float currentNumber;
	bool currentNumberSign; //true +, false -
	string buffer;
	int currentPosition;
	int bufferSize;
	vector<float> result;
	stack<Tag> tags;
	stack<Tag> tagValidation;
	stack<int> tagStartPos;
	stack<int> tagEndPos;
	Tag* createTag(const string& tagName);
	bool isPositionValid(int pos) {return pos>=0 && pos<bufferSize}
public:
	Interpreter() = default;
	Interpreter(const string& inputFile) : inputFile(inputFile), currentNumber(0), result(), tags(), tagValidation(), tagStartPos(), tagEndPos() {};
	void start();
};