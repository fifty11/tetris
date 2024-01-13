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

	for(int i=0; i<3; ++i)
		tetrino.tetrinoList[i]=rand()%7; //  is the amount of tetrinos

	//gmae loop
	int fourth=0;
	Forever
	{
		if(++fourth==4)
		{
			if(tetrino.currentTetrino++==SQUARE)
				tetrino.currentTetrino=L;
			fourth=0;
		}


		display();


		sleep(TICK_RATE);


		if(loseCheck())
			lose();


		//globals.keyPressed=0x00;
		globals.keyPressed=keyPress();

		if((globals.keyPressed & RIGHT_MOVE) && moveCheck(tetrino.x+1, tetrino.y, tetrino.currentAngle, tetrino.currentTetrino))
			++tetrino.x;

		if((globals.keyPressed & LEFT_MOVE) && moveCheck(tetrino.x-1, tetrino.y, tetrino.currentAngle, tetrino.currentTetrino))
			--tetrino.x;

		if((globals.keyPressed & ROTATE_CLOCK_MOVE))
		{
			if(tetrino.currentAngle==3) // 3 is the biggest angle
			{
				if(moveCheck(tetrino.x, tetrino.y, UP_ANGLE, tetrino.currentTetrino))
					tetrino.currentAngle=UP_ANGLE;
			}
			else
			{
				if(moveCheck(tetrino.x, tetrino.y, tetrino.currentAngle+1, tetrino.currentTetrino))
						++tetrino.currentAngle;
			}
		}

		if((globals.keyPressed & ROTATE_COUNTER_CLOCK_MOVE))
		{
			if(tetrino.currentAngle==0)
			{
				if(moveCheck(tetrino.x, tetrino.y, LEFT_ANGLE, tetrino.currentTetrino))
					tetrino.currentAngle=LEFT_ANGLE;
			}
			else
			{
				if(moveCheck(tetrino.x, tetrino.y, tetrino.currentAngle-1, tetrino.currentTetrino))
						--tetrino.currentAngle;
			}
				
		}

		if(globals.keyPressed & SLAM_MOVE)
			SLAMIT();

		if(globals.keyPressed & FASTER_MOVE && moveCheck(tetrino.x, tetrino.y+1, tetrino.currentAngle, tetrino.currentTetrino))
		{
			++tetrino.y;//obs this will slam really fast if there is no imunity frame
			continue;//continius the forever loop and should display again
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
