// Austin Burt
// 1/19/2018

#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
#include "Score.h"

using namespace std;

Score::Score() : score(0), currFrame(0){
}

Score::Score(Game *g) : score(0), currFrame(0), game(g) {
    scoring();
}

Score::~Score() {
    if ( game != NULL )
        delete game;
    cout << "DECONSTRUCTOR\n";
}

int Score::scoring() {
    int total = 0;
    do {
        unique_ptr<Frame> thisFrame(getFrame(currFrame));
        char ball1 = thisFrame->getB1();
        char ball2 = thisFrame->getB2();
        cout << "frame: " << currFrame + 1 << " || ball1 = " << ball1 << " || ball2 = "
            << ball2 << " || ";
        int pointsB1 = ballWorth(ball1);
        int pointsB2 = ballWorth(ball2);
        if (pointsB1 < 0)
            break; // This frame hasn't been bowled yet. exit.
        //make ball2 worth 0 if it has not been bowled yet, or wasn't updated after a
        //copy and frame changed to a 'X'.  (ex. a '5 6' to a 'X')
        pointsB2 = (pointsB1 == 10 || pointsB2 == -1) ? 0 : pointsB2;
        total += pointsB1 + pointsB2;
        int closedFrames = checkClosed();
        if (closedFrames == 3){ // a double before this frame
            Frame * last2 = getFrame(currFrame-2);
            Frame * last = getFrame(currFrame-1);
            // set the score for the frame 2 frames ago
            int was = last2->getPoints();
            last2->setPoints(was + pointsB1);
            // now set the previous frame
            was = last->getPoints();
            last->setPoints(was + (pointsB1 * 2) + pointsB2);
                // * 2 because those points carry over from last frame
            delete last; delete last2;
            total += pointsB1 * 2 + pointsB2;
        } else if (closedFrames == 2) { // a strike before this frame
            Frame * last = getFrame(currFrame-1);
            int was = last->getPoints();
            last->setPoints(was + pointsB1 + pointsB2);
            total += pointsB1 + pointsB2;
            delete last;
        } else if (closedFrames == 1) { // a spare before this frame
            Frame * last = getFrame(currFrame-1);
            int was = last->getPoints();
            last->setPoints(was + pointsB1);
            total += pointsB1;
            cout << "\n in frame " << currFrame - 1 << " points were set to " << was+pointsB1 << ": "
            << last->getPoints() << "\n";
            delete last;
        }

        thisFrame->setPoints(total);
        cout << "points = " << pointsB1 << " || total = " << total << "\n";
    }
    while (nextFrame());
    setScore(total);
    return total;
}

void Score::setScore(const int val) {
	score = val;
}

int Score::getScore() const {
	return score;
}

bool Score::nextFrame() {
    // returns true for frames 1-9 because 10 is handled differently.
	if (currFrame < 8) {
		currFrame++;
        return true;
    }
	currFrame++;
    return false;
}

Frame Score::* getFrame(const int frame) const {
    unique_ptr<Frame> f(&Frame(game->getFrame(frame)));
    /*f = &game->getFrame(frame);*/
    /*Frame * f = &game->getFrame(frame);*/
    return f;
}

Frame10 Score::getFrame10() const {
	return game.getFrame10();
}

int Score::checkClosed() const {
    if (currFrame >= 1 && currFrame <= 9) {
        Frame frame = getFrame(currFrame - 1);
        if (frame.getB1() == 'X') {
            if (currFrame >= 2 && getFrame(currFrame-2).getB1() == 'X') {
                return 3;
            }
            return 2;
        } else if (frame.getB2() == '/')
            return 1;
    }
    return 0;
}

int Score::ballWorth(const char ball) const {
    int points;
    switch (ball) {
        case 'X': points = 10;break;
        case '/': {
                        char b1 = getFrame(currFrame).getB1();
                        points = 10 - ballWorth(b1);
                  }
                  break;
        case '-': points = 0; break;
        case 'F': points = 0; break;
        case 'n': points = -1; break;
        default: points = ball - '0';
    }
    return points;
}

ostream &operator<<(ostream &stream, const Score &score) {
	    stream << score.getScore();
	    return stream;
}
