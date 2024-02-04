#pragma once
#include <vector>
#include <set>

class Monster;

class MonsterDeck
{
public:
	MonsterDeck();
	~MonsterDeck();

	Monster* generateMonster();

private:
	std::vector<Monster*> m_monstersDatabase;
	std::set<Monster*> m_monstersPlayed;
};