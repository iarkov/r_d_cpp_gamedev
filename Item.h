#pragma once
#include "Tribe.h"
#include "Monster.h"
#include <string>

class Item
{
public:
	virtual int getPower(Monster* monster) const { return getBasePower(); }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power)
	{
		setName(name);
		m_power = power;
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Monster* monster) const override
	{
		switch (monster->getTribe())	
		{
		case Tribe::Undead:
			return monster->getLevel();
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: kills ZOMBIES instantly!\n";
	}
};

//TODO: Add new Item type with unique properties
class ZombieWeapon : public Weapon {
public:
	ZombieWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Monster* monster) const override
	{
		switch (monster->getTribe())
		{
		case Tribe::Zombie:
			return getBasePower() * 2;
		case Tribe::Undead:
		case Tribe::Human:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};