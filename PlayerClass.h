#pragma once

class PlayerClass
{
	//FEEL free to add other unique properties
public:
	virtual float getDamageMultiplier() const = 0;
	virtual float getArmorMultiplier() const = 0;
	virtual float getMissChance() const = 0;

	virtual ~PlayerClass() {}	//virtual c-tor for proper destruction of the objects in hierarchy
};

class DefaultClass : public PlayerClass
{
public:
	virtual float getDamageMultiplier() const override { return 1.0f; }
	virtual float getArmorMultiplier() const override { return 1.0f; }
	virtual float getMissChance() const override { return 0.0f; }

private:
	// Any additional properties, methods, helpers can be added here in private section
};

class DefenderClass : virtual public DefaultClass
{
public:
	//Leave damage multiplier as is

	virtual float getArmorMultiplier() const override { return 1.2f; }
	virtual float getMissChance() const override { return 0.1f; } //1 out of 10 shots will be missed. 
	//See Xcom or other turn-based like game for reference what miss chance is
};

class AttackerClass : virtual public DefaultClass
{
public:
	virtual float getDamageMultiplier() const override { return 1.2f; }
	virtual float getMissChance() const override { return 0.05f; }
};

class LuckyManClass : virtual public DefaultClass
{
public:
	virtual float getMissChance() const override { return 0.4f; }
};

//multiple inheritance for pure demonstration purpose
//In general it's best to avoid it unless really neccessary
//Or specific architectural patterns
class BerserkClass : public AttackerClass, LuckyManClass
{
public:
	virtual float getDamageMultiplier() const override { return AttackerClass::getDamageMultiplier(); }
	virtual float getMissChance() const override { return LuckyManClass::getMissChance(); }
	virtual float getArmorMultiplier() const override { return 0.4f; }
};