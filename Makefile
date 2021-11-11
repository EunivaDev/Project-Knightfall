all:
	g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o Project_Knightfall src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image