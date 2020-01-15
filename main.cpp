#include<iostream>
#include<string>
#include"Translator.h"

using namespace std;
/*
Time Spent: 2hrs and 40 mins
This program converts Roman Numerals to modern numbers and vice versa. It will take two type of conversions so I decided to make a 
class that would take in either Roman Numerals or modern numbers and translate it. And the main function will just be the user interface 
that user can input their text. Limits: it can not translate numbers over 4000 due to ASCII character limits. It will have 'E' inside the roman
numeric if it exceed its limit.
*/
int main() {

	int inputNumber = 0;
	string inputString = "", outputString = "";
	Translator translator;

	cout << "Welcome to Roman Numerals Translator..." << endl << endl;

	cout << "Press 1 to translate Roman numbers to modern numbers" << endl;
	cout << "Press 2 to translate modern numbers to Roman numbers" << endl;
	cout << "Press 3 to see options" << endl;
	cout << "Press 4 to exit" << endl<<endl;
	cout << "This is a test" << endl;

	do {
		cout << "Enter options:";
		cin >> inputNumber;
		cin.ignore();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "wrong inputs..." << endl;
			inputNumber = 3;
		}
		if (inputNumber == 1) {
			cout << "Please input Roman Numerals: ";
			getline(cin, inputString);
			cout << "Modern Number: " << translator.TranslateRomToMod(inputString) << endl;
		}
		else if (inputNumber == 2) {
			cout << "Please input modern numbers: ";
			getline(cin, inputString);
			cout << "Roman Number: " << translator.TranslateModToRom(inputString) << endl;
		}
		else if (inputNumber == 3 || inputNumber > 4 || inputNumber < 0) {
			cout << endl << "Options:" << endl;
			cout << "Press 1 to translate Roman numbers to modern numbers" << endl;
			cout << "Press 2 to translate modern numbers to Roman numbers" << endl;
			cout << "Press 3 to see options" << endl;
			cout << "Press 4 to exit" << endl << endl;
		}
		else if (inputNumber == 4) {
			cout << endl << "Good Bye!";
		}
		cout << endl;

	} while (inputNumber != 4);

	

	system("pause");
	return 0;
}