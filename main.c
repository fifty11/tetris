#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

char game;

uint16_t tetrinos[] = {0x0644, 0x0622, 0x4444, 0x0066, 0x00E4};


int main(int argc, char **argv) {
	// constants:
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


	return 0; // return statment more info:
						// https://www.geeksforgeeks.org/return-statement-in-c/
}
