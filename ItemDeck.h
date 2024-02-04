#pragma once
#include <vector>
#include <set>

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	std::vector<Item*> generateItems();

private:
	std::vector<Item*> m_itemsDataBase;
	std::set<Item*> m_ItemsPlayed;
};