#include "stdafx.h"
#include "Level.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include "Weapon.h"
#include "libtcod.hpp"



Level::Level() {
}

void Level::loadLevel(string fileName, Player &player) {

	ifstream file;

	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line)) {
		_levelData.push_back(line);
	}

	setMapDetails(_levelData);

	file.close();

	char tile;

	for (int i = 0; i < _levelData.size(); i++)
	{
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];

			switch (tile)
			{
			case '@':
				player.setPosition(j, i);
				break;
			case 'g': // Goblin
				_enemies.push_back(Enemy("Goblin", tile, 1, 10, 2, 1, 10));
				_enemies.back().setPosition(j, i);
				break;
			case '+': // Item
				_items.push_back(Weapon(tile));
				_items.back().setPosition(j, i);
			}
			
		}
	}

	TCODConsole::initRoot(80, 50, "Roguelike", false);
	TCODConsole::root->clear();

}

void Level::displayLevel() {

	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			TCODConsole::root->putChar(j, i, _levelData[i][j]);
			TCODConsole::flush();
		}

	}
	printf("\n");
}

void Level::playerAction(char userInput, Player &player)
{

	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	// TODO: Need to accepts longer commands in order to equip items
	switch (userInput) {
	case 'w': // Up
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's': // Down
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a': // Left
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd': // Right
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	case 'e': // Pickup object
	case 'E':
		pickUpItem(player);
	case 'i': // View inventory
	case 'I':
		player.displayInventory(_levelData);
		system("PAUSE");
		break;
	default:
		printf("INVALID INPUT");
		system("PAUSE");
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

int Level::getMapHeight()
{
	return _mapHeight;
}

int Level::getMapWidth()
{
	return _mapWidth;
}

void Level::setMapDetails(vector<string> levelData)
{
	_mapHeight = levelData.size();
	_mapWidth = levelData[0].size();
}

void Level::processPlayerMove(Player &player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
	case '#':
		break;
	case '.':
		player.setPosition(targetX, targetY);
		TCODConsole::root->putChar(playerX, playerY, '.');
		TCODConsole::root->putChar(targetX, targetY, '@');
		TCODConsole::root->flush();
		break;
	case '+':
		player.setPosition(targetX, targetY);

		TCODConsole::root->putChar(playerX, playerY, '.');
		TCODConsole::root->putChar(targetX, targetY, '@');
		TCODConsole::root->flush();
		break;
	default:
		attackEnemy(player, targetX, targetY);
		break;
	}
	// Code to handle + when moved over but not picked up
	int itemX;
	int itemY;
	for (int i = 0; i < _items.size(); i++) {
		_items[i].getPosition(itemX, itemY);
		if (playerX == itemX && playerY == itemY) {
			TCODConsole::root->putChar(playerX, playerY, '+');
			TCODConsole::root->flush();
			break;
		}

	}
}

void Level::attackEnemy(Player &player, int targetX, int targetY)
{

	int enemyX;
	int enemyY;
	string enemyName;
	int attackRoll;
	int attackResult;


	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);

		if (targetX == enemyX && targetY == enemyY)
		{
			
			enemyName = _enemies[i].getName();
			// Attack
			attackRoll = player.attack();
			printf("You attacked %s with a roll of %d\n", enemyName.c_str(), attackRoll); // c_str needed because %s looks for char pointer
			attackResult = _enemies[i].takeDamage(attackRoll);
			if (attackResult != 0)
			{
				printf("You have slain a %s", enemyName.c_str());
				player.addExperience(attackResult);

				setTile(targetX, targetY, '.');
				return;
			}

			return;
		}
	}
}

// TODO: attackPlayer function and processEnemyMove function

void Level::pickUpItem(Player &player)
{
	int itemX;
	int itemY;
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	for (int i = 0; i < _items.size(); i++) {

		_items[i].getPosition(itemX, itemY);

		if (playerX == itemX && playerY == itemY) {
			_items[i].setPosition(NULL, NULL);
			_items[i].setOnGround(false);
			player.addToInventory(_items[i]);
			_items.erase(_items.begin() + i);

		}

	}
}



