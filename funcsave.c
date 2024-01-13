
uint8_t moveCheck( // OBS CAN ONLY BE RUN with either x change, y change or angle NOT MORE THAN 1 // todo make clangd show this message OBS MUST BE FIXED WITH GRID_WIDTH AND GRID_HEIGHT
// struct Tetrinos* tetrinoControlStruct, //tetrino contro lstruct isent nececary if you include tetris.h
int8_t xChange,
int8_t yChange,
int8_t angleChange,
int8_t changeAngle, // should be NONE unless change block isent
int8_t changeBlock) // could be used if a pice has been changed out // OBS SHOULD BE 0 IF NO NEW PIce IS USED
{
	uint16_t newTetrino;
	if(changeBlock) // OBS xChange and yChange turn into xSet and ySet if changeBlock is true
	{
		for(uint8_t i=0; i<16; ++i)
			if(tetrinos[changeBlock][changeAngle] & (1<<i))
				if(grid[xChange+(i%4)+1][yChange+((i-(i%4)/4))])
					return 0;
	}
	else if(xChange)
	{
		if(xChange==RIGHT)
			for(uint8_t i=0; i<16; ++i)
				if(tetrinos[tetrino.currentTetrino][tetrino.currentAngle] & (1<<i))
					if(grid[tetrino.x+(i%4)+1][tetrino.y+((i-(i%4)/4))])
						return 0;
		if(xChange==LEFT)
			for(uint8_t i=0; i<16; ++i)
				if(tetrinos[tetrino.currentTetrino][tetrino.currentAngle] & (1<<i))
					if(grid[tetrino.x+(i%4)+1][tetrino.y+((i-(i%4)/4))])
						return 0;
		return 1;
	}
	else if(yChange) // a y change value of negative is never expected so it will default too the yChange being down (+1)
	{
		for(uint8_t i=0; i<16; ++i)
			if(tetrinos[tetrino.currentTetrino][tetrino.currentAngle] & (1<<i))
				if(grid[tetrino.x+(i%4)][tetrino.y+((i-(i%4)/4))+1])
					return 0;
	}
	else if(angleChange)
	{
		uint8_t newAngle;
		if(LEFT)
		{
			if(!tetrino.currentAngle)
				newAngle=3; // biggest angle
			else
				--newAngle;
		}
		else
		{
			if(tetrino.currentAngle==3)
				newAngle=0;
			else
				++newAngle;
		}


		for(uint8_t i=0; i<16; ++i)
			if(tetrinos[tetrino.currentTetrino][newAngle])
				puts("tmp");
	}

	return 1;
}

