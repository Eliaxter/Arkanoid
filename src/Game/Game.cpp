#include "Game.h"

#include "raylib.h"

#include "Menu.h"
#include "Feedback.h"
#include "Gameplay.h"
#include "FinalMenu.h"
#include "Credits.h"
#include "Global.h"

namespace Game
{
	GameState state = GameState::StartMenu;

	void GameLoop()
	{
		InitWindowArkanoid();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);
			if (state == GameState::StartMenu)
			{
				Menu();
			}
			if (state == GameState::Instructions)
			{
				HowToPlay();
			}
			if (state == GameState::Game)
			{
				Update();
				Draw();
			}
			if (state == GameState::MenuFinal)
			{
				FinalMenu();
			}
			if (state == GameState::Credits)
			{
				CreditsScreen();
			}
			if (state == GameState::CloseAll)
			{
				break;
			}
			EndDrawing();
		}
		UnloadMusicStream(backgroundMusic);
		UnloadSound(collisionWave1);
		UnloadSound(collisionWave2);
		CloseAudioDevice();
		CloseWindow();
	}
}