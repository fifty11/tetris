#include "tetris.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char game;

uint16_t tetrinos[7][4] = {
		{0x4460, 0xE80, 0xC440, 0x2E00}, // L
		{0x6440, 0xE20, 0x44C0, 0x8E00}, // Backwards_L
		{0x8C40, 0x6C00, 0x462, 0x6C0}, // S
		{0x4C80, 0xC600, 0x2640, 0xC60}, // Backwards_S
		{0x4444, 0xF00, 0x2222, 0xF0}, // bar
		{0x4E00, 0x4640, 0xE40, 0x4C40}, // pyramid
		{0x660, 0x660, 0x660, 0x660} // square
};

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
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 16; ++k)
			{
				if (tetrinos[i][j] & (0x8000 >> k))
					printf("1 ");
				else
					printf("0 ");
				if (((k + 1) % 4) == 0)
					printf("\n");
			}
			printf("\n\n");
		}
		printf("\n\n\n");
	}

	return 0; // return statment more info:
						// https://www.geeksforgeeks.org/return-statement-in-c/
}
