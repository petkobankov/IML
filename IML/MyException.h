#pragma once
#include <string>
enum class e_type {error,syntax,lexer,parser};
class MyException {
	std::string message;

public:
	MyException(e_type type=e_type::error,const std::string& cause_msg="",int line=0,int col=0);
	const std::string& getMessage() { return message; }
};