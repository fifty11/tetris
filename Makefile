clean:
	rm -rf build
all:
	mkdir build
	clang -O3 -c -o ./build/main.o main.c
	clang -O3 -c -o ./build/tetris.o tetris.c
	clang -O3 -o ./build/tetris ./build/tetris.o ./build/main.o
test:
	mkdir build
	clang -c -o ./build/main.o main.c 
	clang -c -o ./build/tetris.o tetris.c 
	clang -v -o ./build/tetris ./build/tetris.o ./build/main.o
