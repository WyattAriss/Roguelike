#include "stdafx.h"
#include "GameSystem.h"
#include <iostream>
#include <conio.h>

// Constructor sets up the game
GameSystem::GameSystem(string levelFile) {

	_player.init(1, 10, 1, 1, 0);

	_level.loadLevel(levelFile, _player);
	_level.displayLevel();

	system("PAUSE");
}

void GameSystem::playGame() {

	bool isDone = false;

	while (isDone != true)
	{
		//_level.displayLevel();
		playerMove();
	}

}

void GameSystem::playerMove()
{
	char userInput;
	printf("Enter a move command (w/a/s/d):");
	userInput = _getch();

	_level.playerAction(userInput, _player);

}

