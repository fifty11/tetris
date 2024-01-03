#ifndef Header_Guard_Tetris
#define Header_Guard_Tetris

#include <stdint.h>
#include <stdio.h>
#define RIGHT 0
#define LEFT 1

#define L 0
#define BACKWARDS_L 1
#define S 2
#define BACKWARDS_S 3
#define BAR 4
#define PYRAMID 5
#define SQUARE 6

uint16_t tetrinos[7][4] =
{
//		   up,	 right,	  down,	  left
		{0x4460, 0x0E80, 0xC440, 0x2E00}, // L
		{0x6440, 0x0E20, 0x44C0, 0x8E00}, // Backwards_L
		{0x8C40, 0x6C00, 0x0462, 0x06C0}, // S
		{0x4C80, 0xC600, 0x2640, 0x0C60}, // Backwards_S
		{0x4444, 0x0F00, 0x2222, 0x00F0}, // bar
		{0x4E00, 0x4640, 0x0E40, 0x4C40}, // pyramid
		{0x0660, 0x0660, 0x0660, 0x0660} // square
};

void display(void);
void keyPress(void);
void logic(void);

#endif
