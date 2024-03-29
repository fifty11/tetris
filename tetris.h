#ifndef A_WORKING_HEADER_GUARD
#define A_WORKING_HEADER_GUARD

#include <stdint.h>
#include <stdio.h>

// #define TERMINAL_DISPLAY
// #define WINDOW_DISPLAY


#define Forever for(;;) 

#define TICK_RATE 1

#define GRID_HEIGHT 20 // do not change the size of the grid these are just to make the code more readable
#define GRID_WIDTH 10
#define DISPLAY_GRID_HEIGHT 20 // do not change the size of the grid these are just to make the code more readable
#define DISPLAY_GRID_WIDTH 10

#define LEFT_MOVE (1<<1)
#define RIGHT_MOVE (1<<2)
#define ROTATE_CLOCK_MOVE (1<<3)
#define ROTATE_COUNTER_CLOCK_MOVE (1<<4)
#define FASTER_MOVE (1<<5)
#define SLAM_MOVE (1<<6)

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define NONE 5

#define UP_ANGLE 0
#define RIGHT_ANGLE 1
#define DOWN_ANGLE 2
#define LEFT_ANGLE 3

#define L 0
#define BACKWARDS_L 1
#define S 2
#define BACKWARDS_S 3
#define BAR 4
#define PYRAMID 5
#define SQUARE 6

#ifdef TERMINAL_DISPLAY

#define BLANK_COLOR ' '
#define L_COLOR 'b'
#define BACKWARDS_L_COLOR 'c'
#define S_COLOR 'd'
#define BACKWARDS_S_COLOR 'e'
#define BAR_COLOR 'f'
#define PYRAMID_COLOR 'g' 
#define SQUARE_COLOR 'h'

#endif

#ifdef WINDOW_DISPLAY

#define L_COLOR // yellow
#define BACKWARDS_L_COLOR // red
#define S_COLOR // green
#define BACKWARDS_S_COLOR // pink
#define BAR_COLOR // purple
#define PYRAMID_COLOR // turcose
#define SQUARE_COLOR // fortnite

#endif

extern uint16_t tetrinos[7][4];
extern uint8_t grid[GRID_WIDTH][GRID_HEIGHT]; // use the defines of the tetrinos to shift a bit to the right to indicate color

struct Tetrinos {
	uint8_t x;
	uint8_t y;
	uint8_t currentTetrino; //used for color coating and shape
	uint8_t currentAngle;
	uint8_t graceTick; // this is a toggle
	uint8_t saved;
	uint8_t tetrinoList[3];
	uint32_t linesCleared;
};
extern struct Tetrinos tetrino;

struct Globals
{
	uint8_t keyPressed;
};
extern struct Globals globals;


void display(void);

uint8_t keyPress(void);
void clearLines();
uint8_t loseCheck(void);

uint8_t moveCheck(
int8_t xPos,
int8_t yPos,
int8_t angle, 
int8_t tetrino);

void rotate(void);
void lose(void);
void SLAMIT();

#endif
