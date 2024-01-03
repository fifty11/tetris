#ifndef A_WORKING_HEADER_GUARD
#define A_WORKING_HEADER_GUARD

#include <stdint.h>
#include <stdio.h>

// #define TERMINAL_DISPLAY
// #define WINDOW_DISPLAY


#define Forever for(;;) 

#define TICK_RATE 1000

#define LEFT_MOVE (1<<1)
#define RIGHT_MOVE (1<<2)
#define ROTATE_CLOCK_MOVE (1<<3)
#define ROTATE_COUNTER_CLOCK_MOVE (1<<4)
#define FASTER_MOVE (1<<5)
#define SLAM_MOVE (1<<6)

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

#define L 0
#define BACKWARDS_L 1
#define S 2
#define BACKWARDS_S 3
#define BAR 4
#define PYRAMID 5
#define SQUARE 6

extern uint16_t tetrinos[7][4];

struct Tetrinos {
	uint8_t x;
	uint8_t y;
	uint8_t currentTetrino;
	uint8_t currentAngle;
	uint8_t waitTime;
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
uint8_t loseCheck(void);
uint8_t moveCheck(struct Tetrinos* tetrinoControlStruct, int8_t xChange, int8_t yChange, int8_t angleChange);
void rotate(void);
void lose(void);
void SLAMIT();

#endif
