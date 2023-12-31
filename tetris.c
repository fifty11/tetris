#include "tetris.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


struct Tetrinos tetrino;
uint8_t grid[10][20] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

static uint8_t displayGrid[10][20] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

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


#ifdef TERMINAL_DISPLAY

void display(void)
{
	for(int i=0; i<GRID_WIDTH; ++i)
		for(int j=0; j<GRID_HEIGHT; ++j)
			switch(grid[i][j]) // hte +1 is because i need the tetrino macros to be -1 for 0 based indexing for the tetrinos 2D array
			{
				case 0:
					displayGrid[i][j]=BLANK_COLOR;
					break;
				case L+1:
					displayGrid[i][j]=L_COLOR;
					break;
				case BACKWARDS_L+1:
					displayGrid[i][j]=BACKWARDS_L_COLOR;
					break;
				case S+1:
					displayGrid[i][j]=S_COLOR;
					break;
				case BACKWARDS_S+1:
					displayGrid[i][j]=BACKWARDS_S_COLOR;
					break;
				case BAR+1:
					displayGrid[i][j]=BAR_COLOR;
					break;
				case PYRAMID+1:
					displayGrid[i][j]=PYRAMID_COLOR;
					break;
				case SQUARE+1:
					displayGrid[i][j]=SQUARE_COLOR;
					break;
			}

	for(int i=0; i<16; ++i)
		if(tetrinos[tetrino.currentTetrino][tetrino.currentAngle] | (1<<i))
			displayGrid[tetrino.x + (i%4)][tetrino.y + ((i-(i%4))/4)]=tetrino.currentTetrino+1;

	system("clear");
	for(int j=0; j<DISPLAY_GRID_HEIGHT; ++j)
	{
		for(int i=0; i<DISPLAY_GRID_WIDTH; ++i)
		{
			putchar(displayGrid[i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
}

#endif

#ifdef WINDOW_DISPLAY
void display(void) { return; };
#endif

uint8_t keyPress(void) { return 0; };

void clearLines()
{
	for(int i=0; i<GRID_HEIGHT; ++i)
		for(int j=0; j<GRID_WIDTH; ++j)
			if(!grid[j][i])
				break;
}

uint8_t loseCheck(void) { return 0; };


uint8_t moveCheck( // OBS CAN ONLY BE RUN with either x change, y change or angle NOT MORE THAN 1 // todo make clangd show this message OBS MUST BE FIXED WITH GRID_WIDTH AND GRID_HEIGHT
// struct Tetrinos* tetrinoControlStruct, //tetrino contro lstruct isent nececary if you include tetris.h
int8_t xChange,
int8_t yChange,
int8_t angleChange)
{
	if((xChange && yChange) || (yChange && angleChange) || (angleChange && xChange))
		return 0;
	uint16_t newTetrino;
	if(xChange)
	{
		if(xChange==RIGHT)
			for(uint8_t i=0; i<16; ++i)
				if(tetrino.currentTetrino & (1<<i))
					if(grid[tetrino.x+(i%4)+1][tetrino.y+((i-(i%4)/4))])
						return 0;
		if(xChange==LEFT)
			for(uint8_t i=0; i<16; ++i)
				if(tetrino.currentTetrino & (1<<i))
					if(grid[tetrino.x+(i%4)+1][tetrino.y+((i-(i%4)/4))])
						return 0;
	}
	else if(yChange) // a y change value of negative is never expected so it will default too the yChange being down (+1)
	{
		for(uint8_t i=0; i<16; ++i)
			if(tetrino.currentTetrino & (1<<i))
				if(grid[tetrino.x+(i%4)][tetrino.y+((i-(i%4)/4))+1])
					return 0;
	}
	else if(angleChange)
	{
		if(angleChange==LEFT)
			tetrino.currentAngle=tetrino.currentAngle-1 ? tetrino.currentAngle-1 : 4;
		else
			tetrino.currentAngle=(tetrino.currentAngle+1)==5 ? 1 : tetrino.currentAngle+1;
	}

	return 1;
}


void rotate(void) { return; };
void lose(void)
{
#ifdef TERMINAL_DISPLAY
	system("clear");
	printf("your total score is: %d\n", tetrino.linesCleared);
#endif
#ifdef WINDOW_DISPLAY
#endif
}

void SLAMIT() { return; };

