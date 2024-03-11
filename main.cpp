#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Moto.h"
#include "Trace.h"
#include <iostream>
#include <vector>
#include <queue>

void handleSystems(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

int main()
{/*
    std::vector<sf::VideoMode> VMvector = sf::VideoMode::getFullscreenModes();

    sf::RenderWindow window(VMvector[0], "My Window");
    window.setFramerateLimit(120);

    std::vector<LineParameters> level{
        LineParameters{300.f, 315.f},
        LineParameters{400.f, 0.f},
        LineParameters{150.f, 315.f},
        LineParameters{300.f, 0.f},
        LineParameters{50.f, 45.f},
        LineParameters{100.f, 0.f}
    };

    Trace trace{ window, level };
    Motorcycle motorcycle(trace);

    sf::Clock clock;
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        handleSystems(window);

        motorcycle.update(deltaTime);
        trace.update(deltaTime);

        window.clear(sf::Color(255, 255, 255));
        
        motorcycle.draw(window);
        trace.draw(window);

        window.display();
    }

    return 0;
*/
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "My Window");
    sf::CircleShape c(20.f);
    c.setFillColor(sf::Color::Blue);
    //c.setOrigin(c.getRadius(), c.getRadius());
    c.setPosition(100.f, 100.f);
    std::cout << c.getGlobalBounds().getPosition().x << " " << c.getGlobalBounds().getPosition().y;

    while (window.isOpen()) {
        window.clear(sf::Color(255, 255, 255));
        window.draw(c);
        window.display();
    }

    return 0;
};

