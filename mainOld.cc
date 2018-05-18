#include "Frame.h"
#include "Frame10.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	Frame game[4];
	for (int i = 0; i < 5; i++)
		cout << " " << i+1 << "  ";
	cout << "\n";
	game[0].setB1('x');
	game[1].setB1('4');
	game[1].setB2('6');
	game[2].setB1('9');
	//game[2].setB2('-');
	game[3].setB1('f');
	game[3].setB2('/');

	Frame10 f10;
	f10.setB1('6');
	f10.setB2('4');
	f10.setB3('x');

	for (int i=0;i<4;i++)
		cout << game[i];
	cout << f10;
	cout << "\n";
	
}

