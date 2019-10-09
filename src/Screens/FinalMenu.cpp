#include "FinalMenu.h"

#include "raylib.h"

void DrawWindowFinalMenu()
{
	BeginDrawing();
	ClearBackground(BLACK);
}

void DrawTextFinalMenu()
{
	DrawText("End of Game!", 300, 160, 20, RAYWHITE);

	DrawText("Return to Main Menu: M", 300, 220, 20, RAYWHITE);

	DrawText("Play Again: Y/N", 300, 200, 20, RAYWHITE);
}

void InputFinalMenu()
{
	if (IsKeyDown(KEY_M))
	{

	}
	if (IsKeyDown(KEY_ESCAPE))
	{

	}
	if (IsKeyDown(KEY_Y))
	{

	}
	if (IsKeyDown(KEY_N))
	{

	}
}

void FinalMenu()
{
	DrawWindowFinalMenu();
	DrawTextFinalMenu();
	InputFinalMenu();
	EndDrawing();
}