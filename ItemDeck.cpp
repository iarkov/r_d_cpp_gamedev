#include "ItemDeck.h"

#include "Item.h"
#include <algorithm>

ItemDeck::ItemDeck()
{
	//TODO: Move item's database to file in format:
	// type;name; additional if needed params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

	//TODO: Setup more items of diferent types
	m_itemsDataBase = { 
		new Weapon{"The Sword of DOOM", 5},
		new UndeadWeapon{"Stinky knife", 2},
		new UndeadWeapon{"Holy grenade", 4},
		new ZombieWeapon{ "Holy Sword", 3 }
	};

	m_ItemsPlayed = {};
}

ItemDeck::~ItemDeck()
{
	//TODO: FREE MEMORY
	for (Item* item : m_itemsDataBase) {
		delete item;
	}
}

std::vector<Item*> ItemDeck::generateItems()
{
	//TODO: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
	const unsigned int itemsNumberToDeck = std::rand() % m_itemsDataBase.size();

	std::vector<Item*> itemsToDeck{};

	for (int i = 0; i < itemsNumberToDeck; i++) {
		if (m_itemsDataBase.size() == m_ItemsPlayed.size()) {
			m_ItemsPlayed.clear();
		}

		unsigned int idx = std::rand() % m_itemsDataBase.size();
		const std::set<Item*>::iterator itemPlayedSetIt = m_ItemsPlayed.find(m_itemsDataBase[idx]);
		const std::vector<Item*>::iterator itemPlayedVectorIt = std::find(itemsToDeck.begin(), itemsToDeck.end(), m_itemsDataBase[idx]);

		if (itemPlayedSetIt == m_ItemsPlayed.end() and itemPlayedVectorIt == itemsToDeck.end()) {
			m_ItemsPlayed.insert(m_itemsDataBase[idx]);
			itemsToDeck.push_back(m_itemsDataBase[idx]);
		}
		else {
			i--;
		}
	}

	return itemsToDeck;
}
