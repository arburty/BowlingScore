//Austin Burt
// 6/17/2017

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Frame10.h"

using namespace std;

Frame10::Frame10() : ball3('n') {
	is10 = true;
}


//Frame10::Frame10(char a, char b, char c ='n') {
//}

Frame10::Frame10(const Frame10 &f) {
	ball1 = f.getB1();
	ball2 = f.getB2();
	ball3 = f.getB3();
}

void Frame10::setB2(char pins) {
	if (getB1() == 'X') {
		if (pins != 'x' && pins != 'X' && pins != 'f' && pins != 'F' && pins != '-' && !isdigit(pins)) {
			cerr << "Invalid first Ball, you entered '"<< pins << "'\n";
			exit(0);
		}
		switch (pins) {
			case 'x': pins = 'X';break;
			case 'f': pins = 'F';break;
		}

		ball2 = pins;
		return;
	}

	if (pins == '/') {
		ball2 = pins;
		return;
	} else if (pins == 'f' || pins == 'F') {
		ball2 = 'F';
		return;
	} else if (pins == '-') {
		ball2 = pins;
		return;
	} else if (pins == '0') {
		ball2 = '-';
		return;
	}
	if (!isdigit(pins)) {
		cerr << "Invalid second Ball, you entered '"<< pins << "'\n";
		exit(0);
	}

	char b1 = getB1();
	int firstnum;
	if (b1 == 'F' || b1 == '-')
		firstnum = 0;
	else
		firstnum = 10 - (58 - b1);

	int secnum = 10-(58 - pins);
	if (10 - firstnum - secnum == 0)
		ball2 = '/';
	else if (10 - firstnum - secnum > 0)
		ball2 = pins;
	else {
		cerr << "this does not add up to ten! firstball was " << firstnum << " and second ball was "
			<< secnum << ".\n";
		exit(0);
	}

}

void Frame10::setB3(char pins) {
	char b2 = getB2();
	if (b2 == 'X' || b2 == '/') {
		if (pins != 'x' && pins != 'X' && pins != 'f' && pins != 'F' && pins != '-' && !isdigit(pins)) {
			cerr << "Invalid Ball in the 10th, you entered '"<< pins << "'\n";
			exit(0);
		}
		switch (pins) {
			case 'x': pins = 'X';break;
			case 'f': pins = 'F';break;
			case '0': pins = '-';break;
		}

		ball3 = pins;

	} else if (getB1() == 'X') {
		if (pins == '/') {
			ball3 = pins;
			return;
		} else if (pins == 'f' || pins == 'F') {
			ball3 = 'F';
			return;
		} else if (pins == '-') {
			ball3 = pins;
			return;
		} else if (pins == '0') {
			ball3 = '-';
			return;
		}
		if (!isdigit(pins)) {
			cerr << "Invalid third Ball, you entered '"<< pins << "'\n";
			exit(0);
		}

		int firstnum;
		if (b2 == 'F' || b2 == '-')
			firstnum = 0;
		else
			firstnum = 10 - (58 - b2);

		int secnum = 10-(58 - pins);
		if (10 - firstnum - secnum == 0)
			ball3 = '/';
		else if (10 - firstnum - secnum > 0)
			ball3 = pins;
		else {
			cerr << "this does not add up to ten! firstball was " << firstnum << " and second ball was "
				<< secnum << ".\n";
			exit(0);
		}
	} else
		cerr << "Sorry, Game is over, no more pins for you!\n";


}

void Frame10::setFrame(const char *temp) {
	string word = temp;
	setFrame(word);
}

void Frame10::setFrame(const string word) {
	char a = word[0];
	char b = word[2];
	setB1(a);
	setB2(b);
	a = getB2();
	b = getB2();
	if (a == 'X' || b == '/') {
		setB3(word[4]);
	}
}

char Frame10::getB3() const {
	return ball3;
}

ostream &operator<<(ostream &stream, const Frame10 &frame) {
	char b1 = frame.getB1();
	char b2 = frame.getB2();
	char b3 = frame.getB3();
	if (b1 =='n')
		stream << "   |";
	else if (b2 == 'n')
		stream << b1 << "  |";
	else if (b3 =='n')
		stream << b1 << b2 << " |";
	else
		stream << b1 << b2 << b3 << "|";

	return stream;
}
