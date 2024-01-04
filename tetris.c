#include "tetris.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


struct Tetrinos tetrino;

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
struct Globals globals;



void display(void) { return; };

uint8_t keyPress(void) { return 0; };
uint8_t loseCheck(void) { return 0; };


uint8_t moveCheck( // OBS CAN ONLY BE RUN with either x change, y change or angle NOT MORE THAN 1 // todo make clangd show this message
struct Tetrinos* tetrinoControlStruct,
int8_t xChange,
int8_t yChange,
int8_t angleChange)
{
	if((xChange && yChange) || (yChange && angleChange) || (angleChange && xChange))
		return 0;
	uint16_t newTetrino;
	if(xChange)
	{
	}
	else if(yChange) // a y change value of negative is never expected so it will default too the yChange being down
	{
		for(uint8_t i=0; i<16; ++i)
			if(tetrinoControlStruct->currentTetrino & (1<<i))
				printf("TODOfix this so it return 1 if it can move down by 1");
	}
	else if(angleChange)
	{
		if(angleChange==LEFT)
			newTetrino=tetrinos[tetrinoControlStruct->currentTetrino][tetrinoControlStruct->currentAngle-1 ? tetrinoControlStruct->currentAngle-1 : 4];
		else
			newTetrino=tetrinos[tetrinoControlStruct->currentTetrino][(tetrinoControlStruct->currentAngle+1)==5 ? 1 : tetrinoControlStruct->currentAngle+1];
	}

	return 1;
}


void rotate(void) { return; };
void lose(void)
{
#ifdef TERMINAL_DISPLAY
	system("clear");
	printf("your total core is: %d\n", tetrino.linesCleared);
#endif
#ifdef WINDOW_DISPLAY
#endif
}
void SLAMIT() { return; };

