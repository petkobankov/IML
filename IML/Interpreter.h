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
	int bufferSize;
	vector<float> result;
	stack<Tag> tags;
	stack<Tag> tagValidation;
	stack<int> tagStartPos;
	stack<int> tagEndPos;
	Tag* createTag(const string& tagName);
	Tag* removeTag(const string& tagName);
	bool isPositionValid(int pos) { return pos >= 0 && pos < bufferSize; };
	void advance();

public:
	Interpreter() = default;
	Interpreter(const string& inputFile) : inputFile(inputFile), currentNumber(0), result(), tags(), tagValidation(), tagStartPos(), tagEndPos(),currentNumberSign(true),bufferSize() {};
	void start();
};