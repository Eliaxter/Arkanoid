#include "Menu.h"

#include "raylib.h"

#include "Game.h"
#include "Gameplay.h"

namespace Game
{
	static int fontSize1 = 20;
	static int fontSize2 = 30;

	static int coordTxtX = 300;
	static int coordTxtY = 140;

	static int coordTxt2X = 200;
	static int coordTxt2Y = 200;

	static int coordTxt3X = 200;
	static int coordTxt3Y = 240;

	static int coordTxt4X = 200;
	static int coordTxt4Y = 280;

	void DrawWindowMenu()
	{
		ClearBackground(BLACK);
	}

	void DrawTextMenu()
	{
		DrawText("Elias Arkanoid!", coordTxtX, coordTxtY, fontSize2, GRAY);
		DrawText("To Play the game, press the key: ENTER", coordTxt2X, coordTxt2Y, fontSize1, RAYWHITE);
		DrawText("How To play, press the key: H", coordTxt3X, coordTxt3Y, fontSize1, RAYWHITE);
		DrawText("To Exit, press the key: ESCAPE", coordTxt4X, coordTxt4Y, fontSize1, RAYWHITE);
	}

	void InputMenu()
	{
		if (IsKeyDown(KEY_ENTER))
		{
			state = GameState::Game;
			InitGame();
		}
		if (IsKeyDown(KEY_H))
		{
			state = GameState::Feedback;
		}
		if (IsKeyDown(KEY_ESCAPE))
		{
			state = GameState::CloseAll;
		}
	}

	void Menu()
	{
		DrawWindowMenu();
		DrawTextMenu();
		InputMenu();
	}
}