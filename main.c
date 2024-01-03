#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

char game;


int main(int argc, char **argv) {
	// constants:
	struct Tetrinos {
		uint8_t current;
		uint8_t saved;
		uint8_t tetrinoList[3];
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
