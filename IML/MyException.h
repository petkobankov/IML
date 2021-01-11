#pragma once
#include <string>
/// <summary>
/// When an error occurs during process, it's easier to throw and instance of this class. 
/// It's main purpose is for the code to be cleaner and easier to understand.
/// </summary>
enum class e_type {error,syntax,lexer,parser,internal};
class MyException {
	std::string message;

public:
	MyException(e_type type=e_type::error,const std::string& cause_msg="",int line=0,int col=0);
	const std::string& getMessage()const { return message; }
};