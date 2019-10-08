#ifndef BRICKS_H
#define BRICKS_H

#include "raylib.h"

const int lineOfBricks = 5;
const int brickSize = 35;

Rectangle bricks[brickSize] = { 0 };

struct Brick
{
	Vector2 pos;
	bool active;
	int life;
};

void InitBricks();

#endif