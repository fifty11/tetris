#ifndef TETRIS_HEADER_GUARD
#define TETRIS_HEADER_GUARD

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

uint16_t tetrinos[7][4];

void display(void);
void keyPress(void);
void logic(void);

#endif
