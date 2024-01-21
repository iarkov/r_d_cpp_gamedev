#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
	//This const values can be moved later into a config file
	//so they can be modified more granuarily on the go(by other programmers or designers) without need to modify code
	if (distance > 2000)
	{
		return 0.2f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 5.0f;
	}
	return 10.0f;
}

float Pistol::getPrecision(int distance) const
{
	if (distance > 200)
	{
		return 0.05f;
	}
	if (distance > 100)
	{
		return 0.5f;
	}
	if (distance > 50)
	{
		return 1.5f;
	}
	if (distance > 20)
	{
		return 4.0f;
	}
	return 7.0f;
}

float AssaultRifle::getPrecision(int distance) const
{
	if (distance > 200)
	{
		return 0.4f;
	}
	if (distance > 100)
	{
		return 1.0f;
	}
	if (distance > 50)
	{
		return 2.0f;
	}
	if (distance > 20)
	{
		return 6.0f;
	}
	return 8.5f;
}

int BareHand::getDamageRate(int distance) const {
	if (distance > 1) {
		return 0;
	}
	return 1;
}

int Axe::getDamageRate(int distance) const {
	if (distance > 2) {
		return 0;
	}
	return 10;
}