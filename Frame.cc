//Austin Burt
// 6/17/2017

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Frame.h"

using namespace std;

Frame::Frame() : ball1('n'), ball2('n'), is10(false), points(0) {
}

void Frame::setB1(char pins) {
	if (pins != 'x' && pins != 'X' && pins != 'f' && pins != 'F' && pins != '-' && !isdigit(pins)) {
		cerr << "Invalid first Ball, you entered '"<< pins << "'\n";
		exit(0);
	}
	switch (pins) {
		case 'x': pins = 'X';break;
		case 'f': pins = 'F';break;
		case '0': pins = '-';break;
	}

	ball1 = pins;
}

char Frame::getB1() const {
	return ball1;
}

void Frame::setB2(char pins) {
	if (getB1() == 'X') {
		cout << "First ball was a strike silly!\n";
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


void Frame::setFrame(const char *word) {
	string f = word;
	setFrame(f);
}

void Frame::setFrame(const string word) {
	char a = word[0];
	setB1(a);
	a = getB1();
	if (a != 'X')
		setB2(word[2]);

}

void Frame::setPoints(const int p) {
    points = p;
}

int Frame::getPoints() const {
    return points;
}

char Frame::getB2() const {
	return ball2;
}

bool Frame::getIs10() const {
	return is10;
}

ostream &operator<<(ostream &stream, const Frame &frame) {
	char b1 = frame.getB1();
	char b2 = frame.getB2();
	if (b1 == 'X')
		stream << b1 << "  |";
	else if (b1 == 'n')
		stream << "   |";
	else if (b2 == 'n')
		stream << b1 << "  |";
	else
		stream << b1 << " " << b2 << "|";

	return stream;
}
