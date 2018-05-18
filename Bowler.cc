// Austin Burt
// 7/13/2017

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Frame.h"
#include "Frame10.h"
#include "Game.h"
#include "Bowler.h"

using namespace std;

Bowler::Bowler(const string n) : name(n), average(160), basisScore(220), pFactor(1.0) {
	computeHandicap();
}

Bowler::Bowler(const char *n) : name(n), average(160), basisScore(220), pFactor(1.0) {
	computeHandicap();
}

Bowler::Bowler(const string n, const int avg) : name(n), basisScore(220), pFactor(1.0) {
	setAvg_Handicap(avg);
}

Bowler::Bowler(const char *n, const int avg) : name(n), basisScore(220), pFactor(1.0) {
	setAvg_Handicap(avg);
}

void Bowler::setAverage(const int avg) {
	average = avg;
}

// set handicap with new average
void Bowler::setAvg_Handicap(const int avg) {
	setAverage(avg);
	computeHandicap();
}

// set handicap when average is already known
void Bowler::computeHandicap() {
	handicap = (basisScore - average) * pFactor;	
}

string Bowler::getName() const {
	return name;
}

int Bowler::getAverage() const {
	return average;
} 

int Bowler::getHandicap() const {
	return handicap;
}

void Bowler::addGame(const Game g) { 
	games.push_back(g);
}

list<Game> Bowler::getGames() const {
	return games;
} 

ostream &operator<<(std::ostream &stream, const Bowler &b) {
	stream << "Bowler " << b.getName() << ":\n";
	stream << "Average = " << b.getAverage() << "\n";
	stream << "Handicap = " << b.getHandicap() << "\n";
	list<Game> L = b.getGames();
//	for (auto a : L)
//		stream << a << "\n";
	int num = 1;
	for(list<Game>::iterator i = L.begin(); i != L.end(); i++) {
		stream << "Game " << num++ << ":\n" << *i;
	}
	return stream;
} 
