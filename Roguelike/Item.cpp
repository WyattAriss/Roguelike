#include "stdafx.h"
#include "Item.h"


Item::Item() {

}

string Item::getName()
{
	return _name;
}

int Item::getValue()
{
	return _value;
}

void Item::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

bool Item::getOnGround()
{
	return _onGround;
}

void Item::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Item::setOnGround(bool onGround)
{
	_onGround = onGround;
}

void Item::setRarity(int x)
{
	_rarity = x;
}
