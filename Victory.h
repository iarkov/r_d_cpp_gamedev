#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Victory
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	//#TODO: Implement in all children classes, see class Item for reference
	virtual std::string getFullInfo() { return ""; }
};

class Victory_LevelUp : public Victory
{
public:
	Victory_LevelUp(int level = 1) : m_levelUp(level) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Level up by " + std::to_string(m_levelUp) + " if won\n"; }

protected:
	int m_levelUp;
};