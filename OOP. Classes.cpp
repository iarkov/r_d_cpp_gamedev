#include <iostream>
#include <string>
#include <vector>

#include "Rectangle.h"
#include "Game.h"

int main()
{
    // ----------------- TASK 3 -----------------
    std::cout << "----------------- TASK 3 -----------------" << std::endl << std::endl;

    Rectangle rectangle1 = Rectangle();
    std::cout << "Area: " << rectangle1.getArea() << " ; Perimeter: " << rectangle1.getPerimeter() << std::endl << std::endl;

    Rectangle rectangle2 = Rectangle(6.4, 3.2);
    std::cout << "Area: " << rectangle2.getArea() << " ; Perimeter: " << rectangle2.getPerimeter() << std::endl << std::endl;

    Player player1 = Player("Player", Class::Sniper);
    Weapon rifle = Weapon("Rifle", 200, 100);
    player1.setWeapon(&rifle);
    player1.getWeapon()->weaponInfo();

    Player player2 = Player("Berserk", Class::Assault);
    Team dreamTeam = Team("Reepers");

    dreamTeam.addPlayer(&player1);
    dreamTeam.addPlayer(&player2);

    player1.printPlayerInfo();
    std::cout << std::endl;
    player2.printPlayerInfo();
    std::cout << std::endl;

    dreamTeam.removePlayer(&player2);
    player2.printPlayerInfo();
}
