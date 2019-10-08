#include "Menu.h"

#include "raylib.h"

#include "Game.h"

void DrawWindow()
{
	BeginDrawing();
	ClearBackground(BLACK);
}

void DrawText() 
{
	DrawText("Elias Arkanoid!", 300, 100, 20, RAYWHITE);
	DrawText("To Play the game, press the key: ENTER", 300, 120, 20, RAYWHITE);
	DrawText("How To play, press the key: H", 300, 140, 20, RAYWHITE);
	DrawText("To Exit, press the key: ESCAPE", 300, 160, 20, RAYWHITE);
}

void InputMenu()
{
	if (IsKeyDown(KEY_ENTER))
	{
		state = GameState::Game;
	}
	if (IsKeyDown(KEY_H))
	{

	}
	if (IsKeyDown(KEY_ESCAPE))
	{
		CloseWindow();
	}
}

void Menu()
{
	DrawWindow();
	DrawText();
	InputMenu();
	EndDrawing();
}