BUILD_DIR = ./build
EXECUTABLE = tetriz

C_SOURCES = \
main.c \
tetris.c

OBJECTS = $(notdir $(C_SOURCES:.c=.o))
COMPILER = clang

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

all:
	@make all-terminal

all-terminal:
	$(COMPILER) -DTERMINAL_DISPLAY -c $(C_SOURCES)
	$(COMPILER) -DTERMINAL_DISPLAY -o $(EXECUTABLE) $(OBJECTS)

test-terminal:
	$(COMPILER) -v -c $(C_SOURCES)
	$(COMPILER) -v -o $(EXECUTABLE) $(OBJECTS)

all-gui:
test-gui:

