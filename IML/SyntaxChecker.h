#pragma once
#include <string>
#include <fstream>
using namespace std;
class SyntaxChecker {
private:
	//Path to the input
	std::string inputFile;
	//When we check the syntax and start reading the input we alternate between each of the four main states
	enum class main_state { none, tag, number,error };
	main_state currentMainState;
	//The previous main state is needed if we are reading a number inside a tag. If the number is correct and there is no more input, the syntax is not correct. That's the only time it's used.
	main_state prevMainState;
	//When the main state is 'tag' or 'number' we go a deeper level in the states. Now the tag/number has it's own states in order to help better track the syntax.
	char currentTagState;
	char currentNumState;
	char currentInput;
	//When there is no more input to read, the program checks if the last state was final. 
	bool lastStateWasFinal;
	std::ifstream iFile;
	//Functions to help readability 
	void defaultState();
	void tagState();
	void numberState();
	void errorState();
	//Also for better readability
	bool isDigit() { return (currentInput >= '0' && currentInput <= '9'); };
	bool isInput(const char& input) { return (currentInput == input); };
	bool isDash() { return isInput('-'); };
	bool isDot() { return isInput('.'); };
	bool isUpperCase() { return (currentInput >= 'A' && currentInput <= 'Z'); };
	bool isQuote() { return isInput('"'); };
	bool isLeftArrow() { return isInput('<'); };
	bool isRightArrow() { return isInput('>'); };
	bool isSlash() { return isInput('/'); };
	bool isSpace() { return (isInput(' ') || isInput('\n') || isInput('\t') || isInput('\v') || isInput('\r') || isInput('\f')); };
	//Used when updating the main state.
	void updateStateFromTo(main_state from, main_state to, bool isNewStateFinal=false);
	//The bottom two functions are for the tag and number sub states
	void updateTagState(const char& newTagState, bool isFinal = false);
	void updateNumState(const char& newNumState, bool isFinal = false);
	void exitFromTagState();
	void exitFromNumState();
	//It's called when there is no more input. Checks if the last state was final.
	bool canFinish() { return lastStateWasFinal; }
	//if the input was "..> 2.34 <..". The current state is default and we read the digit 2. We change to state 'number' and now we are reading the dot. It's easier if we pause the input and when we change to state 'number' we are still reading the digit 2.  
	void pauseStreamPointer() { iFile.seekg(-1, ios::cur); }
	//Stops the checking of the syntax. Called when there is no more input, or if there is an error.
	void stopCheck() { if (!canFinish()) throw "Syntax Error!\nThe program uses a strict syntax check. \nTag syntax: <TAG-NAME \"NUMBER\"> or <TAG-NAME \"UPPER_CASE_LETTERS\"> or <TAG-NAME> or </TAG-NAME>. \nBetween the tags should be only numbers"; }

public:
	SyntaxChecker(): inputFile(), currentMainState(main_state::none), prevMainState(main_state::none),currentInput(), iFile(), currentTagState('s'), currentNumState('s'), lastStateWasFinal(true){};
	void loadFile(const std::string& inputFile) { this->inputFile = inputFile; };
	void checkSyntax();
};
