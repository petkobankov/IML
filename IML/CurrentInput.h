#pragma once
class CurrentInput {
private:
	char data;
	bool isInput(const char& input) { return (data == input); };
public:
	bool isDigit() { return (data >= '0' && data <= '9'); };
	bool isDash() { return isInput('-'); };
	bool isDot() { return isInput('.'); };
	bool isUpperCase() { return (data >= 'A' && data <= 'Z'); };
	bool isQuote() { return isInput('"'); };
	bool isLeftArrow() { return isInput('<'); };
	bool isRightArrow() { return isInput('>'); };
	bool isSlash() { return isInput('/'); };
	bool isSpace() { return (isInput(' ') || isInput('\n') || isInput('\t') || isInput('\v') || isInput('\r') || isInput('\f')); };
	char& getInput() { return data; }
};