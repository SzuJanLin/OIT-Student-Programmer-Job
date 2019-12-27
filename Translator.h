#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

/*
This is a translator that would take in a text that needed to be translated and return the translated text. 
It will also check if the user input is translatable. It it's not it will return an exception. 
*/

class Translator
{

public:
	Translator();
	~Translator();

	/*
	I used a back search method to parse the string. If the current one is less than the previous one,
	I will subtract the total num. If it is equal or larger, I will add them up.
	*/
	string TranslateRomToMod(const string input);

	/*
	Because it is easier to build a number from the digit in 10^0, I decided to build the roman letter backward. And then flip the whole string in the end.
	To do this, first I needed to know how many numbers there are. Since the rule of each number is the same. Only the letter is different. currentDecimal
	will keep track of which places I'm at as I go through the for loop.
	*/
	string TranslateModToRom(const string input);

	/*this function will convert a single Roman letter to the corresponding modern number in int
	*/
	int ConvertSingleRom(const char letter);

	/*this function will convert a modern int to the corresponding roman letter
	*/
	char ConvertSingleMod(const int number);
};



#endif // !TRANSLATOR_H



