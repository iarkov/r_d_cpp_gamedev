#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"
#include <set>

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase =
	{
		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
		new Monster{"Crazy Joe", 4},
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
		new Monster{"Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}},
		new Monster{"Poor Gretchen", 2, Tribe::Zombie, new Runaway_LevelDowngrade{1}, new Victory_LevelUp{2}}
	};

	m_monstersPlayed = {};
}

MonsterDeck::~MonsterDeck()
{
	//TODO: Clear memory
	for (Monster* monster : m_monstersDatabase) {
		delete monster;
	}
	/*
	for (Monster* monster : m_monstersPlayed) {
		delete monster;
	}*/
}

Monster* MonsterDeck::generateMonster()
{
	//#TODO: this call should return new monster every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again

	if (m_monstersDatabase.size() == m_monstersPlayed.size()) {
		m_monstersPlayed.clear();
	}

	const int choice = std::rand() % m_monstersDatabase.size();
	const std::set<Monster*>::iterator monsterPlayedIt = m_monstersPlayed.find(m_monstersDatabase[choice]);

	if (monsterPlayedIt == m_monstersPlayed.end()) {
		m_monstersPlayed.insert(m_monstersDatabase[choice]);
		return m_monstersDatabase[choice];
	}
	else {
		generateMonster();
	}
}