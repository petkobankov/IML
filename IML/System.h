#pragma once
#include <string>
#include "Interpreter.h"
using namespace std;
class System {
private:
	string inputFile;
	string outputFile;
	Interpreter mainInterpreter;

	void getOutputFileName();
	void getInputFileName();
	void validateInputFileName();
	void validateOutputFileName();
	void interprateInput();
	void outputResult();
public:
	void start();
};