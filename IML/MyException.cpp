#include "MyException.h"
//enum class e_type {error,syntax,lexer,parser};
MyException::MyException(e_type type = e_type::error, const std::string& cause_msg = "", int line = 0, int col = 0)
{
	std::string error;
	switch (type)
	{
	case e_type::syntax:
		error = "Syntax error! ";
		break;
	case e_type::parser:
	case e_type::lexer:
	case e_type::error:
	default:
		error = "Error! ";
		break;
	}
	if (line != 0) {
		message = error + "On line: " + std::to_string(line) + ", col: " + std::to_string(col) + ". " + cause_msg;
	}
	else {
		message = error + cause_msg;
	}
	
}
