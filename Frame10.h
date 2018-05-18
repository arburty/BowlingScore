#ifndef FRAME10_H_INCLUDED
#define FRAME10_H_INCLUDED

#include <iostream>
#include "Frame.h"

using namespace std;

class Frame10 : public Frame {
	public: 
		Frame10();
		Frame10(char, char, char);
		Frame10(const Frame10 &);
		//char getB1() const;
		//char getB2() const;
		char getB3() const;
		//void setB1(char);
		void setB2(char);
		void setB3(char);
		void setFrame(const char *);
		void setFrame(const string);
	private:
		//char ball1;
		//char ball2;
		char ball3;
		//bool is10;
};

std::ostream &operator<<(std::ostream &, const Frame10 &);

#endif
