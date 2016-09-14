#include "stdafx.h"
#include "Weapon.h"
#include <ctime>
#include <random>

#pragma region Weapon Identifiers:
/*
0	Dagger
1	Short sword
2	Long sword
3	Handaxe
4	Heavy axe
5	Mace
.	.
.	.
.	.
*/
#pragma endregion

Weapon::Weapon(char tile)
{
	_tile = tile;

	int weaponIdentifier = randomWeapon();

	/* Should just need to be connected to the db, find the correct values and store
	the in the correct spot */



	// TODO: This is what I want to let a DB handle
	/*
	switch (weaponIdentifier)
	{
	case '0':
		_name = "Dagger";
		_damageType = 'N';
		_weaponType = "Small Blade";
		_attack = 2;
		_defense = 0;
		_value = 1;
		break;
	case '1':
		_name = "Short Sword";
		_damageType = 'N';
		_weaponType = "Small Blade";
		_attack = 4;
		_defense = 0;
		_value = 3;
		break;
	case '2':
		_name = "Long Sword";
		_damageType = 'N';
		_weaponType = "Blade";
		_attack = 6;
		_defense = 0;
		_value = 10;
		break;
	case '3':
		_name = "Wooden Stick";
		_damageType = 'N';
		_weaponType = "Club";
		_attack = 1;
		_defense = 0;
		_value = 0;
		break;
	default:
		break;
	}
	*/

}

int Weapon::randomWeapon()
{
	static default_random_engine random_engine(time(NULL));
	uniform_int_distribution<int> randomRoll(0, NUM_OF_WEAPONS);

	return randomRoll(random_engine);
}

int Weapon::getAttack()
{
	return _attack;
}

int Weapon::getDefense()
{
	return _defense;
}

string Weapon::getWeaponType()
{
	return _weaponType;
}

