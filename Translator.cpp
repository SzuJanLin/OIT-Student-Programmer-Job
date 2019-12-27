#include "Translator.h"



Translator::Translator()
{
}


Translator::~Translator()
{
}

string Translator::TranslateRomToMod(const string input)
{
	int ModernNum=0, length = input.size();
	ModernNum += ConvertSingleRom(input.at(length - 1));
	for (int i = length - 2; i > -1; i--) { 
		//current and last value and compare them. subtract or add them to ModernNum
		int current = ConvertSingleRom(input.at(i));
		int last = ConvertSingleRom(input.at(i + 1));

		if (current>=last) {
			ModernNum += current;
		}
		else {
			ModernNum -= current;
		}
	}
	return to_string(ModernNum);
}

string Translator::TranslateModToRom(const string input)
{
	stringstream ss;
	string returnString;
	int currentDecimal = 1;
	int length = input.size();
	for (int i = length - 1; i > -1; i--) {
		int currentNum = input.at(i) - '0';
		// I used a big if else statement to parse through different kind of number and pass the number into the converter
		if (currentNum < 4) {
			for (int i = 0; i < currentNum; i++) {
				ss << ConvertSingleMod(currentDecimal);
			}
		}
		else if (currentNum == 4) {
			ss << ConvertSingleMod(currentDecimal * 5);
			ss << ConvertSingleMod(currentDecimal);
		}
		else if (currentNum >= 5 && currentNum < 9) {
			for (int i = 0; i < currentNum - 5; i++) {
				ss << ConvertSingleMod(currentDecimal);
			}
			ss << ConvertSingleMod(currentDecimal * 5);
		}
		else if (currentNum == 9){
			ss << ConvertSingleMod(currentDecimal * 10);
			ss << ConvertSingleMod(currentDecimal);
		}
		currentDecimal *= 10; // currentDecimal will time 10 as it goes through the loop each time.
	}
	returnString = ss.str();
	reverse(returnString.begin(), returnString.end());
	return returnString;
}

int Translator::ConvertSingleRom(const char letter)
{
	switch (letter)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case'C':
		return 100;
	case'D':
		return 500;
	case'M':
		return 1000;
	default:
		return -1;//return error
	}
	return -1;
}

char Translator::ConvertSingleMod(const int number)
{
	switch (number)
	{
	case 1:
		return 'I';
	case 5:
		return 'V';
	case 10:
		return 'X';
	case 50:
		return 'L';
	case 100:
		return 'C';
	case 500:
		return 'D';
	case 1000:
		return 'M';
	default:
		return 'E';// return error
	}
	return 'E';
}


