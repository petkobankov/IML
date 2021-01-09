#include "SyntaxChecker.h"
#include <fstream>
#include <iostream>
using namespace std;
void SyntaxChecker::defaultState()
{
	if (isSpace()) {
		finalState();
		currentMainState = main_state::none;
	}
	else if (isDigit() || isDash()) {
		currentMainState = main_state::number;
		iFile.seekg(-1, ios::cur);
	}
	else if (isLeftArrow()) {
		currentMainState = main_state::tag;
		iFile.seekg(-1, ios::cur);
	}
	else {
		currentMainState = main_state::error;
	}
	prevMainState = main_state::none;
}

void SyntaxChecker::tagState()
{
	switch (currentTagState)
	{
	case 's':

		break;
	default:
		break;
	}
}

void SyntaxChecker::numberState()
{

}

void SyntaxChecker::errorState()
{

}

void SyntaxChecker::checkSyntax()
{
	if (inputFile.empty()) {
		throw "Input file missing!";
	}
	iFile.open(inputFile);
	while (iFile.get(currentInput)) {
		canFinish = false;
		switch (currentMainState) {
		case main_state::none:
			defaultState();
			break;
		case main_state::tag:
			tagState();
			break;
		case main_state::number:
			numberState();
			break;
		case main_state::error:
			errorState();
			break;
		default:
			break;
		}
	}
	if (!canFinish) throw "Syntax Error!";
}
