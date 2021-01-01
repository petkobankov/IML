#pragma once
#include <string>
#include "Interpreter.h"
using namespace std;
class System {
private:
	string inputFile;
	string outputFile;
	Interpreter mainInterpreter;

	void getFileNames();
	void validateFiles();
	void interprateInput();
	void outputResult();
public:
	void start();
};