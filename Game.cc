// Austin Burt
// 7/13/2017

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Game.h"
#include "Frame.h"

using namespace std;

Game::Game() : score(0), currFrame(0){
}

Game::Game(const Game &g) : score(g.score), currFrame(g.currFrame), frames(g.frames), f10(g.f10) {
}

void Game::setScore(const int val) {
	score = val;
}

int Game::getScore() const {
	return score;
}

void Game::nextFrame() {
	if (currFrame <= 9)
		currFrame++;
	else
		cerr << "Already finished game. No more frames left!\n";
}

void Game::setFrame(const string word) {
	if (currFrame <=8) {
		frames[currFrame].setFrame(word);
		nextFrame();
	} else if (currFrame == 9) {
		f10.setFrame(word);
		nextFrame();
	} else
		cerr << "not a frame! somehow current frame is " << currFrame << ".\n";
}

void Game::setFrame(const char *temp) {
	string word = temp;
	setFrame(word);
}

//remember, currFrame is directly associated with frames[].  it has values 0-9, and 10 means game is over.
//frame is exactly what frame the user wants to edit (1-10).
void Game::editFrame(const int frame, const string word) {
	if (frame < 1 || frame > 10 || frame >= currFrame + 1) {
		cerr << "'" << frame << "' is not a valid frame to edit.\n";
		return;
	}
	if (frame <= 9)
		frames[frame - 1].setFrame(word);
	else if (frame == 10)
		f10.setFrame(word);
}

void Game::editFrame(const int frame, const char *temp) {
	string word = temp;
	editFrame(frame, word);
}

Frame Game::getFrame(const int frame) const {
	if (frame <= 8)
		return frames[frame];
	else
		cerr << "sorry im not good enough to also return a Frame10 :/ \n";
	Frame f;
	return f;
}

Frame10 Game::getFrame10() const {
	return f10;
}
ostream &operator<<(ostream &stream, const Game &game) {
	for (int i = 1; i <= 10; i++)
                stream << " " << i << "  ";
	stream << "total";
        stream << "\n";

	for (int i=0; i<9; i++)
		stream << game.getFrame(i);
	stream << game.getFrame10();
	stream << "  " << game.getScore();
	stream << "\n";

    for (int i=0; i<9; i++) {
        int val = game.getFrame(i).getPoints();
        if (val < 10)
            stream << val << "  |";
        else if (val < 100)
            stream << val << " |";
        else
            stream << val << "|";
    }
	stream << "\n";

	return stream;
}
