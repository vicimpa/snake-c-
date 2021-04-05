build:
	g++ -Os -std=c++17 -c lib/Vector2.cpp -o lib/Vector2.o
	g++ -Os -std=c++17 -c lib/GameMap.cpp -o lib/GameMap.o
	g++ -Os -std=c++17 -c lib/GameSnake.cpp -o lib/GameSnake.o

	g++ -o main \
		main.cpp \
		lib/Vector2.o \
		lib/GameSnake.o \
		lib/GameMap.o \
		-Os -std=c++17 -pthread -lncurses


run:
	./main

clean:
	rm lib/*.o
	rm ./main