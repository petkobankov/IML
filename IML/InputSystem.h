#pragma once
class InputSystem {
private:
	char data;
	bool isInput(const char& input) { return (data == input); };
public:
	bool isDigit() { return (data >= '0' && data <= '9'); };
	bool isDash() { return isInput('-'); };
	bool isDot() { return isInput('.'); };
	bool isUpperCase() { return (data >= 'A' && data <= 'Z'); };
	bool isLowerCase() { return (data >= 'a' && data <= 'z'); };
	bool isQuote() { return isInput('"'); };
	bool isLeftArrow() { return isInput('<'); };
	bool isRightArrow() { return isInput('>'); };
	bool isSlash() { return isInput('/'); };
	bool isSpace() { return (isInput(' ') || isInput('\n') || isInput('\t') || isInput('\v') || isInput('\r') || isInput('\f')); };
	bool isNewLine() { return isInput('\n'); };
	char& getInput() { return data; }
};