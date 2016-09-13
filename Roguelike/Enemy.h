#pragma once
#include <string>

using namespace std;

class Enemy {
public:
	Enemy(string name, char tile, int level, int health, int attack, int defense, int experience);

	// Compute attack
	int attack();

	int takeDamage(int attack);

	// Setters
	void setPosition(int x, int y);

	// Getters
	void getPosition(int &x, int &y);
	string getName();

private:
	// Properties
	string _name;
	char _tile;

	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;

	// Position
	int _x;
	int _y;

};

