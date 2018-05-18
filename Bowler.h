#ifndef BOWLER_H_INCLUDED
#define BOWLER_H_INCLUDED

#include <iostream>
#include <list>
#include "Frame.h"
#include "Frame10.h"
#include "Game.h"

class Bowler {
	public:
		Bowler(const std::string);
		Bowler(const char *);
		Bowler(const std::string, const int);
		Bowler(const char *, const int);
		void setAverage(const int);
		void setHandicap(const int);
		void setAvg_Handicap(const int);
		std::string getName() const;
		int getAverage() const;
		int getHandicap() const;
		void addGame(const Game);
		std::list<Game> getGames() const;
	private:
		std::string name;
		int average;
		int handicap;
		int basisScore;
		double pFactor;
		std::list<Game> games;
		
		void computeHandicap();
};

std::ostream &operator<<(std::ostream &, const Bowler &);

#endif
