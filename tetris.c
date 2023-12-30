#include <stdbool.h>
#include <stdint.h>

#include "tetris.h"

uint16_t tetrinos[7][4] = {
		{0x4460, 0xE80, 0xC440, 0x2E00}, // L
		{0x6440, 0xE20, 0x44C0, 0x8E00}, // Backwards_L
		{0x8C40, 0x6C00, 0x462, 0x6C0}, // S
		{0x4C80, 0xC600, 0x2640, 0xC60}, // Backwards_S
		{0x4444, 0xF00, 0x2222, 0xF0}, // bar
		{0x4E00, 0x4640, 0xE40, 0x4C40}, // pyramid
		{0x660, 0x660, 0x660, 0x660} // square
};

static char isTouhing(char direction) { return 0; }

static void setDirection(uint16_t* tetrino, char type, char direction) {
	
}

void display(void) { return; }

void keyPress(void) { return; }

void logic(void) { return; }
