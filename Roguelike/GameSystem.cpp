#include "stdafx.h"
#include "GameSystem.h"
#include <iostream>
#include <conio.h>
#include "sqlite3.h"

// Constructor sets up the game
GameSystem::GameSystem(string levelFile) {

	sqlite3 *db;
	int rc;

	rc = sqlite3_open("test.db", &db);

	// For debugging
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(1);
	} else {
		fprintf(stderr, "Opened database successfully\n");
	}

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

