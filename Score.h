#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <iostream>
#include "Frame.h"
#include "Frame10.h"
#include "Game.h"

using namespace std;

class Score {
	public:
        Score();
        Score(Game);
        ~Score();
        int scoring();
        void setScore(const int);
        bool nextFrame();
        int getScore() const;
        Frame getFrame(const int) const;
        Frame10 getFrame10() const;
        int checkClosed() const;
        int ballWorth(const char) const;
    private:
        int score;
        int currFrame;
        Game game;
};

std::ostream &operator<<(std::ostream &, const Score &);

#endif
