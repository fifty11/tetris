#include "stdbool.h"
#include "tetris.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define RIGHT 0
#define LEFT 1

#define L 0
#define BACKWARDS_L 1
#define BAR 2
#define SQUARE 3
#define PYRAMID 4

char game;

void turn(uint16_t *tetrino, char dir);

int main(int argc, char **argv) {
	// constants:
	uint16_t tetrinos[] = {0x0644, 0x0622, 0x4444, 0x6600, 0xE400};
	struct Tetrinos {
		uint16_t current;
		uint16_t saved;
		uint16_t tetrinoList[3];
	} tetrino;

	// vars
	int seed;

	game = true;

	// game
	if (argc > 1)
		seed = atoi(argv[0]);

	return 0;
}

void turn(uint16_t *tetrino, char dir) {
	uint16_t tempTrino = 0x00;
	if (dir) {
		char sector; // sector is which fourth of the BIT field the function is processing
		*tetrino=tempTrino;
		return;
	}
	*tetrino=tempTrino;
}
