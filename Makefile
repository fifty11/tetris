BUILD_DIR = ./build
EXECUTABLE = tetriz

C_SOURCES = \
		   main.c \
		   tetris.c 

OBJECTS = $(notdir $(C_SOURCES:.c=.o))

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

all-terminal:
	# mkdir -p $(BUILD_DIR)
	clang -O2 -c $(C_SOURCES)
	clang -o $(EXECUTABLE) $(OBJECTS)

all-gui:

test:
	mkdir -p build
	rm -rf build/*
	clang -c -o ./build/main.o main.c 
	clang -c -o ./build/tetris.o tetris.c 
	clang -v -o ./build/tetris ./build/tetris.o ./build/main.o
