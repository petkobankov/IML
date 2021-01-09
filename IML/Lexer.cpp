#include "Lexer.h"

void Lexer::start()
{
	if (inputFile.empty()) {
		throw "Input file missing!";
	}
	iFile.open(inputFile);

	while (iFile.get(currentInput)) {
		
	}
}
