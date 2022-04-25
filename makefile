game.exe: source.o CDomino.o CDominoCollection.o CDominoesGame.o CPlayer.o
	g++ source.o CDomino.o CDominoCollection.o CDominoesGame.o CPlayer.o -o game

source.o: source.cpp
	g++ -c source.cpp -o source.o

CDomino.o: CDomino.cpp CDomino.h
	g++ -c CDomino.cpp -o CDomino.o

CDominoCollection.o: CDominoCollection.cpp CDominoCollection.h
	g++ -c CDominoCollection.cpp -o CDominoCollection.o

CDominoesGame.o: CDominoesGame.cpp CDominoesGame.h
	g++ -c CDominoesGame.cpp -o CDominoesGame.o

CPlayer.o: CPlayer.cpp CPlayer.h
	g++ -c CPlayer.cpp -o CPlayer.o
	
run:
	./game

clean:
	rm *.o 
