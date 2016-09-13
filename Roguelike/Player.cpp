#include "stdafx.h"
#include "Player.h"
#include <ctime>
#include <random>
#include "libtcod.hpp"
#include "Level.h"

using namespace std;

// Constructor initializes the players position
Player::Player() {
	_x = 0;
	_y = 0;
}

// Initializes the player with properties
void Player::init(int level, int health, int attack, int defense, int experience) {
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}

void Player::addToInventory(Item item)
{
	_playerInventory.push_back(item);
}

// Sets the players position
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

// Gets the players position using reference variables
void Player::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}

int Player::attack()
{
	static default_random_engine random_engine(time(NULL));
	uniform_int_distribution<int> attackRoll(1, _attack);

	return attackRoll(random_engine);
}

void Player::addExperience(int experience)
{
	_experience += experience;

	while(_experience > _requiredExperience)
	{
		printf("Leveled Up!\n");
		static default_random_engine random_engine(time(NULL));
		uniform_int_distribution<int> healthGain(_maxHealthPerLevel / 2, _maxHealthPerLevel);
		_requiredExperience *= 2;
		_attack += 1;
		_health += healthGain(random_engine);
		_level++;
		system("PAUSE");
	}
}

void Player::setInventoryCapacity(int capacity)
{
	_inventoryCapacity = capacity;
}

int Player::takeDamage(int attack) {
	attack -= (_defense / 3);
	if (attack > 0) {
		_health -= attack;
		// If the player dies return 1
		if (_health <= 0) {
			return 1;
		}
	}
	return 0;
}

void Player::displayInventory(vector <string> levelDetails) {
	for (int i = 0; i < _playerInventory.size(); i++)
	{
		string s = to_string(i);
		TCODConsole::root->putChar(levelDetails[i].size() + 2, i, s[0]);
		if (i > 9)
		{
			TCODConsole::root->putChar(levelDetails[i].size() + 3, i, s[1]);
		}
		for (int j = 0; j < _playerInventory[i].getName().size(); j++) {
			//printf("\n%d: %s", i, _playerInventory[i].getName().c_str());
			TCODConsole::root->putChar(j + levelDetails[i].size() + 5, i, _playerInventory[i].getName()[j]);
		}
		if (i == _playerInventory.size() - 1)
		{
			printf("\n");
			TCODConsole::root->flush();
		}
	}
}
