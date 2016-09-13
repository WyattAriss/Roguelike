#include "stdafx.h"
#include "Enemy.h"
#include <ctime>
#include <random>


// Constructor initializes the enemy's properties
Enemy::Enemy(string name, char tile, int level, int health, int attack, int defense, int experienceValue)
{
	_name = name;
	_tile = tile;
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experienceValue;
}


// Sets the enemy's position
void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

// Gets the enemy's position
void Enemy::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

// Gets the name of the enemy
string Enemy::getName()
{
	return _name;
}


int Enemy::attack() {
	static default_random_engine random_engine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(random_engine);
}

int Enemy::takeDamage(int attack)
{
	attack -= (_defense / 3);
	if (attack > 0)
	{
		_health -= attack;
		// If the enemy dies then we return its experience value
		if (_health <= 0)
		{
			return _experience;
		}
	}
	return 0;
}
