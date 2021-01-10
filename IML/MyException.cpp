#include "MyException.h"
//enum class e_type {error,syntax,lexer,parser};
MyException::MyException(e_type type, const std::string& cause_msg, int line, int col)
{
	std::string error;
	switch (type)
	{
	case e_type::syntax:
		error = "Syntax error! ";
		break;
	case e_type::internal:
		error = "Internal error! ";
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
