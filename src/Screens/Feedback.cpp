#include "Feedback.h"

#include "raylib.h"

#include "Game.h"

namespace Game
{
	void DrawWindowFeedBack()
	{
		ClearBackground(BLACK);
	}

	void DrawTextFeedBack()
	{
		DrawText("How To play", 340, 120, 30, GRAY);

		DrawText("Move player to the left, press the key: A", 190, 160, 20, RAYWHITE);

		DrawText("Move player to the right, press the key: D", 190, 180, 20, RAYWHITE);

		DrawText("Back: B", 680, 420, 25, RAYWHITE);
	}

	void InputFeedBack()
	{
		if (IsKeyDown(KEY_B))
		{
			state = GameState::StartMenu;
		}
	}

	void FeedBack()
	{
		DrawWindowFeedBack();
		DrawTextFeedBack();
		InputFeedBack();
	}
}

