#include <string>
#include <cstdlib>
#include <ctime>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
	std::srand(time(nullptr));
	//Game cycle
	Player player1("OnePunchMan", new SniperRifle);
	Player player2("JohnCena", new Axe, new DefenderClass);
	Player player3("HarryPotter", new AssaultRifle, new BerserkClass);
	Player player4("SailorMoon", new Pistol, new LuckyManClass);
	//TODO: Other players with other weapons and classes to properly cover different test-cases


	player1.attack(player2, 500);
	player1.attack(player2, 2000);
	player1.attack(player1, 300);
	player2.attack(player1, 100);
	player1.attack(player2, 500);

	player3.attack(player4, 200);
	player4.attack(player3, 20);

	return 0;
}