#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include "Frame.h"
#include "Frame10.h"

using namespace std;

class Game {
	public:
		Game();
		Game(const Game&);
		void setScore(const int);
		void nextFrame();
		void setFrame(const std::string);
		void setFrame(const char *);
		void editFrame(const int, const std::string);
		void editFrame(const int, const char *);
		int getScore() const;
		Frame getFrame(const int) const;
		Frame10 getFrame10() const;
	private:
		int score;
		int currFrame;
		Frame frames[9];
		Frame10 f10;
};

std::ostream &operator<<(std::ostream &, const Game &);

#endif
