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

	//gmae loop
	Forever
	{
		display();
		

		usleep(TICK_RATE);
		
		
		if(loseCheck())
			lose();


		globals.keyPressed=keyPress();

		if((globals.keyPressed & RIGHT_MOVE) && moveCheck(&tetrino, 1, 0, 0))
			++tetrino.x;
		if((globals.keyPressed & LEFT_MOVE) && moveCheck(&tetrino, -1, 0, 0))
			--tetrino.x;
		if((globals.keyPressed & ROTATE_CLOCK_MOVE) && moveCheck(&tetrino, 0, 0, 1))
		{
			if(tetrino.currentAngle==4)
				tetrino.currentAngle=1;
			else
				++tetrino.currentAngle;
		}
		if((globals.keyPressed & ROTATE_COUNTER_CLOCK_MOVE) && moveCheck(&tetrino, 0, 0, -1))
		{
			if(tetrino.currentAngle==1)
				tetrino.currentAngle=4;
			else
				--tetrino.currentAngle;
		}
		if(globals.keyPressed & SLAM_MOVE)
			SLAMIT();
		if(globals.keyPressed & FASTER_MOVE && moveCheck(&tetrino, 0, 1, 0))
		{
			++tetrino.y;
			continue;//continius the forever loop and should display again
		}
	}


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
