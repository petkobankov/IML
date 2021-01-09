#include "SyntaxChecker.h"
#include <fstream>
#include <iostream>
using namespace std;
void SyntaxChecker::defaultState()
{
	if (isSpace()) {
		//By default if the input is space it's ignored. The state is final, so that if the input stops there is no syntax error.
		updateStateFromTo(main_state::none, main_state::none,true);
	}
	else if (isDigit() || isDash()) {
		//if the current input is -, or a digit then we move to the number state. The number state has sub states. 
		updateStateFromTo(main_state::none, main_state::number);
		//The stream is paused so that the code is more understandable. 
		pauseStreamPointer();
	}
	else if (isLeftArrow()) {
		//The input is '<' so the program prepares to read a tag.
		updateStateFromTo(main_state::none, main_state::tag);
		pauseStreamPointer();
	}
	else {
		//If the input is anything else from space,digit,dash,left arrow the program outputs there is error with the syntax. 
		updateStateFromTo(main_state::none, main_state::error);
	}
}

void SyntaxChecker::tagState()
{
	//Like in checkSyntax() here the programm goes through sub states of a tag. 
	switch (currentTagState)
	{
	case 's':
		//The start of automata, expects '<' else it's error. If we want spaces between '<' and tag name, it should be added here.
		if (isLeftArrow()) {
			updateTagState('z');
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'z':
		//This states seperates a start tag from ending one. The ending one has no additional inputs.
		if (isUpperCase()) {
			updateTagState('n');
		}
		else if (isSlash()) {
			updateTagState('e');
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'n':
		//The state for a starting tag. Currently reading the name. 
		//If there is a space, then we expect additional input, if there is '>' then that's the end of the tag and the program changes the state to default in exitFromTagState();
		//If we want to accept space between TAG-NAME and > we make the change here.
		if (isUpperCase() || isDash()) {
			updateTagState('n');
		}
		else if (isSpace()) {
			updateTagState('a');
		}
		else if (isRightArrow()) {
			exitFromTagState();
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'a':
		//Expecting a quote for additional input
		if (isQuote()) {
			updateTagState('d');
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'd':
		//Seperates the states to a tag with addition string input, and a tag with additional float/int input.
		if (isUpperCase()) {
			updateTagState('c');
		}
		else if (isDash() || isDigit()) {
			//If it's a digit or - we change the main state to 'number' because the program is reading a number
			//We update the prev state to 'tag' so that if the input stops in a final state the syntax is still incorrect
			updateTagState('b');
			updateStateFromTo(main_state::tag, main_state::number);
			pauseStreamPointer();
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'c':
		//Expecting string with upper case letters, if there is a quote then the additional input is over
		if (isUpperCase()) {
			updateTagState('c');
		}
		else if (isQuote()) {
			updateTagState('t');
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'b':
		//When the main state is number, it reads digits until the input is something else. When the input is other than a number it goes back to it's previous state i.e. 'tag' in our case. The sub state was changed to b when we updated the main state so we are here.
		//Expecting only '"'
		if (isQuote()) {
			updateTagState('t');
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 't':
		//After the quote there is nothing else to read expect '>'. If we want to read extra spaces between the two, we change it here.
		if (isRightArrow()) {
			exitFromTagState();
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	case 'e':
		//This state was from the start of the function, when we read '/'. So it's an end tag. 
		//For an end tag we expect only letters, dashes or '>'
		//If it's '>' then we exit from the tag state
		if (isUpperCase()||isDash()) {
			updateTagState('e');
		}
		else if (isRightArrow()) {
			exitFromTagState();
		}
		else {
			updateStateFromTo(main_state::tag, main_state::error);
		}
		break;
	default:
		break;
	}
}

void SyntaxChecker::numberState()
{
	//Like tagState().
	switch (currentNumState) {
	case 's':
		//In the start we expect either - or a digit
		if (isDash()) {
			updateNumState('m');
		}
		else if (isDigit()) {
			updateNumState('n',true);
		}
		else {
			updateStateFromTo(main_state::number, main_state::error);
		}
		break;
	case 'm':
		//If we read a - then we expect atleast one digit after it.
		if (isDigit()) {
			updateNumState('n',true);
		}
		else {
			updateStateFromTo(main_state::number, main_state::error);
		}
		break;
	case 'n':
		//We have read at least one digit here. If we read something else than a digit we exit from main state 'number', go back to the previous main state and pause the stream for one cycle
		if (isDigit()) {
			updateNumState('n',true);
		}
		else if (isDot()) {
			updateNumState('d');
		}
		else {
			exitFromNumState();
		}
		break;
	case 'd':
		//We have read one dot, now it's not a final state and we expect atleast one more digit.
		if (isDigit()) {
			updateNumState('a',true);
		}
		else {
			updateStateFromTo(main_state::number, main_state::error);
		}
		break;
	case 'a':
		//We have read at least one digit after a dot, it's a final state so if we read something else from a digit we change the main state to the previous one and pause the stream for a cycle.
		if (isDigit()) {
			updateNumState('a', true);
		}
		else {
			exitFromNumState();
		}
		break;
	default:
		break;
	}
}

void SyntaxChecker::errorState()
{
	//Called when the main state is 'error'.
	//Throws expection and additonal message.
	stopCheck();
}

void SyntaxChecker::updateStateFromTo(main_state from, main_state to, bool isNewStateFinal)
{
	//Called when we want to change the main state
	currentMainState = to; 
	prevMainState = from;
	//We mark the state final (or not final) before we are in it, because if there is no more input we wouldn't know if the last state was final or not.
	lastStateWasFinal = isNewStateFinal;
}

void SyntaxChecker::updateTagState(const char& newTagState, bool isFinal)
{
	//Same as updateStateFromTo
	currentTagState = newTagState;
	lastStateWasFinal = isFinal;
}

void SyntaxChecker::updateNumState(const char& newNumState, bool isFinal)
{
	//Same as updateStateFromTo
	//If the previous state was a tag, we don't care if the last state is final, because we are currently still in a tag.
	currentNumState = newNumState;
	if (prevMainState == main_state::tag) {
		lastStateWasFinal = false;
	}
	else {
		lastStateWasFinal = isFinal;
	}
	
}

void SyntaxChecker::exitFromTagState()
{
	//For the next tag we make sure it starts from the beggining.
	updateTagState('s');
	//It's a final state, because if there is no more input there isin't an error.
	updateStateFromTo(main_state::tag, main_state::none,true);
}

void SyntaxChecker::exitFromNumState()
{
	//Same as exitFromTagState();
	updateNumState('s');
	//As in updateNumState, if the previous state was a tag, then the syntax is still currently incorrect.
	if (prevMainState != main_state::tag) {
		updateStateFromTo(main_state::number, prevMainState);
	}
	else {
		updateStateFromTo(main_state::number, prevMainState,true);
	}
	pauseStreamPointer();
}

void SyntaxChecker::checkSyntax()
{
	if (inputFile.empty()) {
		throw "Input file missing!";
	}
	iFile.open(inputFile);

	//Main loop. Here we only operate on the main state and we are currently ignoring the sub states. 
	while (iFile.get(currentInput)) {
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
			throw "Internal error!";
			break;
		}
	}
	stopCheck();
	//If the code reaches here then the syntax is correct.
}
