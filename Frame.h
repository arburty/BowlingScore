#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <iostream>
using namespace std;

class Frame {
    public:
        Frame();
        char getB1() const;
        char getB2() const;
        bool getIs10() const;
        int getPoints() const;
        void setB1(char);
        void setB2(char);
        void setFrame(const string word);
        void setFrame(const char *);
        void setPoints(const int);
    protected:
        char ball1;
        char ball2;
        bool is10;
        int points;
};

std::ostream &operator<<(std::ostream &, const Frame &);

#endif
