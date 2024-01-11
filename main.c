#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"


int main(int argc, char **argv) {
	// vars
	int seed;


	// game setup
	if (argc > 1)
		seed = atoi(argv[1]);

	tetrino.x=1;
	tetrino.y=1;
	tetrino.currentTetrino=L;
	tetrino.currentAngle=UP_ANGLE;
	tetrino.linesCleared=0;
	globals.keyPressed=0x00;

	//gmae loop
	int fourth=0;
	Forever
	{
		display();


		sleep(TICK_RATE);


		if(loseCheck())
			lose();


		//globals.keyPressed=0x00;
		globals.keyPressed=keyPress();

		if((globals.keyPressed & RIGHT_MOVE) && moveCheck(RIGHT, NONE, NONE, NONE))
			++tetrino.x;
		if((globals.keyPressed & LEFT_MOVE) && moveCheck(LEFT, NONE, NONE, NONE))
			--tetrino.x;
		if((globals.keyPressed & ROTATE_CLOCK_MOVE) && moveCheck(NONE, NONE, RIGHT, NONE))
		{
			if(++tetrino.currentAngle==4)
				tetrino.currentAngle=0;
		}
		if((globals.keyPressed & ROTATE_COUNTER_CLOCK_MOVE) && moveCheck(NONE, NONE, LEFT, NONE))
		{
			if(--tetrino.currentAngle==0)
				tetrino.currentAngle=3;
		}
		if(globals.keyPressed & SLAM_MOVE)
			SLAMIT();
		if(globals.keyPressed & FASTER_MOVE && moveCheck(NONE, DOWN, NONE, NONE))
		{
			++tetrino.y;
			continue;//continius the forever loop and should display again
		}
		if(++fourth==4)
		{
			if(tetrino.currentTetrino++==SQUARE)
				tetrino.currentTetrino=L;
			fourth=0;
		}
	}
	/*
	 * for(int i=0; i<16; ++i)
	{
		printf("%d ", tetrinos[tetrino.currentTetrino][tetrino.currentAngle]&(1<<i) ? 1 : 0);
		if((i+1)%4==0)
			putchar('\n');
	}
	*/


	return 0; // return statment more info:
						// https://www.geeksforgeeks.org/return-statement-in-c/
}




/*
 *
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
 */
