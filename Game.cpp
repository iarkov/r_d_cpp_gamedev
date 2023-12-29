#include "Game.h"
#include <iostream>

Weapon::Weapon() {
    m_name = "knife";
    m_damage = 50;
    m_range = 1;
}

Weapon::Weapon(std::string name, int damage, int range) :
    m_name(name), m_damage(damage), m_range(range) {}

void Weapon::weaponInfo() {
    std::cout << "Weapon name: " << m_name << " ; weapon damage: " << m_damage << " ; weapon range: " << m_range << std::endl;
}

Team::Team(std::string name) : m_name(name) {
    m_players_number = 0;
}

Player::Player(std::string name, Class cl) :
    m_name(name), m_class(cl)
{
    m_health = 100;

    Weapon* wpPtr = nullptr;
    Weapon wp = Weapon();
    wpPtr = &wp;
    this->setWeapon(wpPtr);
}

// ----------------- TASK 6 -----------------
Weapon* Player::getWeapon() {
    return m_weapon;
};

void Player::setWeapon(Weapon* wp) {
    m_weapon = wp;
}

bool Team::addPlayer(Player* pl) {
    m_players.push_back(pl);
    pl->setTeam(this);
    m_players_number += 1;

    return true;
}

bool Team::removePlayer(Player* pl) {
    for (int i = 0; i < m_players_number; i++) {
        if (m_players[i] == pl) {
            m_players.erase(m_players.begin() + i);
            pl->setTeam(nullptr);
            m_players_number -= 1;
        }
    }
    return true;
}

void Player::setTeam(Team* teamPtr) {
    m_teamPtr = teamPtr;
}

void Player::printPlayerInfo() {
    std::cout << "Player: " << m_name;
    std::cout << " ; Health: " << m_health;
    std::cout << " ; Class: ";
    switch (m_class) {
    case Class::Assault:
        std::cout << "Assault";
        break;
    case Class::Support:
        std::cout << "Support";
        break;
    case Class::Sniper:
        std::cout << "Sniper";
        break;
    case Class::Medic:
        std::cout << "Medic";
        break;
    }

    if (m_teamPtr) {
        std::cout << " ; Team: " << m_teamPtr->getName();
    }
}