CXXFLAGS=-std=c++11 -Wall -Wextra -Wpedantic -Wfatal-errors
HEAD=Frame.h Frame10.h Game.h Bowler.h Score.h
OBJ= main.o Frame.o Frame10.o Game.o Bowler.o Score.o

main: $(OBJ) $(HEAD)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

Frame.o:: Frame.h
Frame10.o:: Frame10.h
Game.o:: Game.h
Bowler.o:: Bowler.h
Score.o:: Score.h
main.o:: $(HEAD)

clean:
	rm -f main *.o


