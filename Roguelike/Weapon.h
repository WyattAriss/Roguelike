#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	Weapon(char tile);

	int randomWeapon();

	// Getters
	int getAttack();
	int getDefense();
	string getWeaponType();

private:
	const int NUM_OF_WEAPONS = 3; // Number of weapon identifiers in the game

	// Weapon properties
	int _attack;
	int _defense;
	string _weaponType;
	char _damageType; // N - normal, M - magic, F - fire etc.


};

