#pragma once
#include <vector>
#include "Item.h"


class Player {
public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	void addToInventory(Item item);

	// Compute attack
	int attack();

	// Take damage
	int takeDamage(int attack);

	// Setters
	void setPosition(int x, int y);

	void addExperience(int experience);

	void setInventoryCapacity(int capacity);

	// Getters
	void getPosition(int &x, int &y);

	void displayInventory(vector <string> level);


private:
	// Properties
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;
	int _requiredExperience = 50;
	int _maxHealthPerLevel = 12;
	int _inventoryCapacity = 10;

	vector <Item> _playerInventory;

	// Position
	int _x;
	int _y;

};
