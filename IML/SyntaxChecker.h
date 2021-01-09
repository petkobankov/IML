#pragma once
#include <string>
class SyntaxChecker {
private:
	std::string inputFile;
	enum class main_state { none, tag, number,error };
	main_state currentMainState;
	main_state prevMainState;
	char currentTagState;
	char currentNumState;

	char currentInput;
	bool canFinish;
	std::ifstream iFile;

	void defaultState();
	void tagState();
	void numberState();
	void errorState();
	bool isDigit() { return (currentInput >= '0' && currentInput <= '9'); };
	bool isInput(const char& input) { return (currentInput == input); };
	bool isDash() { return isInput('-'); };
	bool isDot() { return isInput('.'); };
	bool isUpperCase() { return (currentInput >= 'A' && currentInput <= 'Z'); };
	bool isQuote() { return isInput('"'); };
	bool isLeftArrow() { return isInput('<'); };
	bool isRightArrow() { return isInput('>'); };
	bool isSpace() { return (isInput(' ') || isInput('\n') || isInput('\t') || isInput('\v') || isInput('\r') || isInput('\f')); };
	void finalState() { canFinish = true; }
	//void throwError(const char* error = "Syntax is incorrect.") {throw error;}

public:
	SyntaxChecker(): inputFile(), currentMainState(main_state::none), prevMainState(main_state::none),currentInput(), iFile(), canFinish(true), currentTagState('s'), currentNumState('s') {};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void checkSyntax();
};
