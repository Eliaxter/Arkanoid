#include "Feedback.h"

#include "raylib.h"

#include "Game.h"

namespace Game
{

	static int fontSize1 = 20;
	static int fontSize2 = 25;
	static int fontSize3 = 30;

	static int coordTxtX = 340;
	static int coordTxtY = 120;

	static int coordTxt2X = 190;
	static int coordTxt2Y = 160;

	static int coordTxt3X = 190;
	static int coordTxt3Y = 180;

	static int coordTxt4X = 190;
	static int coordTxt4Y = 200;

	static int coordTxt5X = 680;
	static int coordTxt5Y = 420;

	void DrawTextFeedBack()
	{
		DrawText("How To play", coordTxtX, coordTxtY, fontSize3, GRAY);

		DrawText("Move player to the left, press the key: A", coordTxt2X, coordTxt2Y, fontSize1, RAYWHITE);

		DrawText("Move player to the right, press the key: D", coordTxt3X, coordTxt3Y, fontSize1, RAYWHITE);

		DrawText("To move the ball, press the key: SPACE", coordTxt4X, coordTxt4Y, fontSize1, RAYWHITE);


		DrawText("Back: B", coordTxt5X, coordTxt5Y, fontSize2, RAYWHITE);
	}

	void InputFeedBack()
	{
		if (IsKeyDown(KEY_B))
		{
			state = GameState::StartMenu;
		}
	}

	void HowToPlay()
	{
		ClearBackground(BLACK);
		DrawTextFeedBack();
		InputFeedBack();
	}
}

