#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

char game;

uint16_t tetrinos[] = {0x0644, 0x0622, 0x4444, 0x0066, 0x00E4};

void turn(uint16_t *tetrino, char dir);


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
	

	printf("pyramid:\n");
	for (int i = 0; i < 16; ++i) {
		if (PYRAMID & (0x01 << i))
			printf("1 ");
		else
			printf("0 ");

		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	printf("\nL:\n");
	for (int i = 0; i < 16; ++i) {
		if (L & (0x01 << i))
			printf("1 ");
		else
			printf("0 ");

		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	printf("\nbackwardsL:\n");
	for (int i = 0; i < 16; ++i) {
		if (BACKWARDS_L& (0x01 << i))
			printf("1 ");
		else
			printf("0 ");

		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	printf("\nbar:\n");
	for (int i = 0; i < 16; ++i) {
		if (BAR & (0x01 << i))
			printf("1 ");
		else
			printf("0 ");

		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	printf("\nsquare:\n");
	for (int i = 0; i < 16; ++i) {
		if (SQUARE & (0x01 << i))
			printf("1 ");
		else
			printf("0 ");

		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	return 0; // return statment more info:
						// https://www.geeksforgeeks.org/return-statement-in-c/
}

void turn(uint16_t *tetrino, char dir) {
	uint16_t tempTrino = 0x00;
	if (dir) {
		char sector; // sector is which fourth of the BIT field the function is
								 // insert processing
		*tetrino = tempTrino;
		return;
	}
	*tetrino = tempTrino;
}
