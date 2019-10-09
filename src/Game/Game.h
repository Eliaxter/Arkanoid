#ifndef GAME_H
#define GAME_H

enum GameState
{
	StartMenu,
	Game,
	Lose,
	CloseAll
};

extern GameState state;

void GameLoop();

#endif