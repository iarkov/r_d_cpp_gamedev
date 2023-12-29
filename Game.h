#pragma once
#include <string>
#include <vector>

// ----------------- TASK 5 -----------------
class Weapon {
public:
    Weapon();
    Weapon(std::string name, int damage, int range);
    void weaponInfo();
private:
    std::string m_name;
    int m_damage;
    int m_range;
};

// ----------------- TASK 4 -----------------
enum class Class {
    Assault,
    Support,
    Sniper,
    Medic
};

class Player;

// ----------------- TASK 7 -----------------
class Team {
public:
    Team(std::string name);

    std::string getName() {
        return m_name;
    }

    bool addPlayer(Player* pl);
    bool removePlayer(Player* pl);
private:
    std::string m_name;
    int m_players_number;
    std::vector<Player*> m_players;
};

class Player {
public:
    Player(std::string name, Class cl);

    Weapon* getWeapon();
    void setWeapon(Weapon* wp);
    void setTeam(Team* teamPtr);
    void printPlayerInfo();

private:
    std::string m_name;
    int m_health;
    Weapon* m_weapon;
    Class m_class;
    Team* m_teamPtr;
};
