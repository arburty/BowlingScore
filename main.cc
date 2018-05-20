#include "Frame.h"
#include "Frame10.h"
#include "Game.h"
#include "Bowler.h"
#include "Score.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	Game one;
	one.setFrame("4 3");
	one.setFrame("x 1");
	one.setFrame("4 /");
	one.setFrame("- 0");
	one.setFrame("2 8");
	one.setFrame("4 6");
	one.setFrame("4 6");
	one.setFrame("4 6");
	one.setFrame("4 6");
	one.setFrame("0 / 0");
	one.setScore(200);
	cout << one;

	Bowler tom("Tom");
	Bowler sarah("Sarah",200);

	sarah.addGame(one);
	Game two(one);
	two.editFrame(1, "x");
	two.editFrame(10, "x x x");
	two.editFrame(8, "9 /");
	two.setScore(220);
	sarah.addGame(two);
	sarah.setAvg_Handicap(210);

	cout << tom << "\n" << sarah;
    cout << "\n";
    Score score(two);
    cout << "score:: " << score << "\n";
    int s = score.scoring();
    cout << "hello::::" << s << "\n";
    cout << "score:: " << score << "\n";

    cout << two;
}
