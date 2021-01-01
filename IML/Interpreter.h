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
	vector<float> result;
	stack<Tag> tags;
	stack<Tag> tagValidation;
	stack<int> tagStartPos;
	stack<int> tagEndPos;
public:
	Interpreter() = default;
	Interpreter(const string& inputFile);
	void start();
};