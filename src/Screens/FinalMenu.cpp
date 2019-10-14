#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"
#include "Gameplay.h"

namespace Game
{
	void DrawWindowFinalMenu()
	{
		ClearBackground(BLACK);
	}

	void DrawTextFinalMenu()
	{
		DrawText("End of Game!", 300, 160, 20, RAYWHITE);

		DrawText("Return to Main Menu: M", 300, 220, 20, RAYWHITE);

		DrawText("Play Again: Y/N", 300, 200, 20, RAYWHITE);

		DrawText("Credits: C", 300, 240, 20, RAYWHITE);
	}

	void InputFinalMenu()
	{
		if (IsKeyDown(KEY_M))
		{
			state = GameState::StartMenu;
		}
		if (IsKeyDown(KEY_ESCAPE))
		{
			CloseWindow();
		}
		if (IsKeyDown(KEY_C))
		{
			state = GameState::Credits;
		}
		if (IsKeyDown(KEY_Y))
		{
			InitGame();
			state = GameState::Game;
		}
		if (IsKeyDown(KEY_N))
		{
			state = GameState::CloseAll;
		}
	}

	void FinalMenu()
	{
		if (IsMusicPlaying)
		{
			StopMusicStream(backgroundMusic);
		}
		DrawWindowFinalMenu();
		DrawTextFinalMenu();
		InputFinalMenu();
		UnloadMusicStream(backgroundMusic);
		UnloadSound(collisionWave1);
		UnloadSound(collisionWave2);
	}
}