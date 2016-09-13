#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"


using namespace std;

class Level {
public:
	Level();

	void loadLevel(string fileName, Player &player);
	void displayLevel();

	void playerAction(char userInput, Player &player);

	// Getters and setters for tiles
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

	int getMapHeight();
	int getMapWidth();

	void setMapDetails(vector <string> mapDetails);

private:
	void processPlayerMove(Player &player, int targetX, int targetY);
	void attackEnemy(Player &player, int targetX, int targetY);
	void pickUpItem(Player &player);

private:

	int _mapHeight;
	int _mapWidth;

	vector <string> _levelData;
	vector <Enemy> _enemies;
	vector <Item> _items;
};

