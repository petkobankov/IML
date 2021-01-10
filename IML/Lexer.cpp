#include "Lexer.h"

void Lexer::start()
{
	if (inputFile.empty()) {
		throw "Input file missing!";
	}
	iFile.open(inputFile);

	while (iFile.get(currentInput.getInput())) {
		switch (previousState) {
		case 'n':
			
			break;
		case 'o':
			break;
		case 'e':
			break;
		case 'd':
			break;
		case 'u':
			break;
		case 'i':
			break;
		default:
			break;
		}
	}
}
