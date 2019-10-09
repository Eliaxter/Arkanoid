#ifndef BRICKS_H
#define BRICKS_H

#include "raylib.h"

extern const int lineOfBricks;
const int brickSize = 35;


struct Brick
{
	Rectangle rect;
	int life;
};

extern Brick bricks[brickSize];

void InitBricks();
void DrawBricks();

#endif