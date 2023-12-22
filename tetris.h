#ifndef TETRIS_HEADER_GUARD
#define TETRIS_HEADER_GUARD

#define RIGHT 0
#define LEFT 1

#define L tetrinos[0]
#define BACKWARDS_L tetrinos[1]
#define BAR tetrinos[2]
#define SQUARE tetrinos[3]
#define PYRAMID tetrinos[4]


void display(void);
void keyPress(void);
void logic(void);

#endif
