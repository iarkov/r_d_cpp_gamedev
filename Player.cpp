#include "Player.h"
#include <iostream>
#include <cstdlib>

// aka RAII principle, see more here: 
// https://covemountainsoftware.com/2019/11/26/why-i-prefer-c-raii-all-the-things/
Player::~Player()
{
	delete m_class;
	delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
	delete m_class;
	m_class = playerClass;
}

void Player::attack(Player& other, int distance)
{
	if (&other == this)
	{
		std::cout << "\n-------FRIENDLY FIRE!-------\n";
	}

	if (other.isEliminated())
	{
		std::cout << "Player " << other.getName() << " has been already eliminated!\n\n";
		return;
	}

	if (this->isEliminated()) {
		std::cout << "Corpses do not attack, unless they are not zombies, but this is not the case!!!\n\n";
		return;
	}

	//More damage-related modifiers can be added here
	//TODO: Add miss-chance of the class into account
	int random_luck = (std::rand() % 100); 
	int luck = random_luck < static_cast<int>(other.m_class->getMissChance() * 100) ? 0 : 1;

	const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());

	other.takeDamage(damage * luck);

	std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
		" with damage " << damage;
	
	if (!luck) {
		std::cout << ", but missed";
	}
	std::cout << std::endl;
	std::cout << "Player " << other.getName() << " has " << other.getHealth() << " health left" << std::endl;

	if (other.isEliminated())
	{
		//m_health = 0;	//for consistency. For example UI may not support properly negative values

		std::cout << "Player " << other.getName() << " was eliminated!\n";
	}
	std::cout << std::endl;
}