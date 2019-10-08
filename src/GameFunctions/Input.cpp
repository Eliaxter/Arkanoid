#include "Input.h"

#include "raylib.h"

#include "Player.h"

void MovePlayer()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		player1.x += 500.0f * GetFrameTime();
	}
	if (IsKeyDown(KEY_LEFT))
	{
		player1.x -= 500.0f * GetFrameTime();
	}
}

