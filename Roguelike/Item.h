#pragma once
#include <string>

using namespace std;

class Item {
public:
	Item();

	// Getters
	string getName();
	int getValue();
	void getPosition(int &x, int &y);
	bool getOnGround();

	// Setters
	void setPosition(int x, int y);
	void setOnGround(bool onGround);
	void setRarity(int x);

public:

protected:
	// Shared properties
	string _name;
	char _tile;
	int _value;
	int _rarity; // Number used to control drop frequency and rarity
	bool _onGround; // Whether the item is in inventory or on the ground

	// Position
	int _x;
	int _y;


};

