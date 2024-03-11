#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Misc.h"
#include "Trace.h"

enum class MotoState {
    NoGround,
    RareWheelOnGround,
    FrontWheelOnGround,
    WheelsOnGround
};

enum class Origin {
    RearWheel,
    FrontWheel
};

struct LinesIntersected {
    bool intersects = false;
    std::vector<Line*> linesIntersected{};
};

class Motorcycle {
public:
    Motorcycle(Trace& trace) : m_trace(trace) {
        m_body_texture.loadFromFile("C:\\Users\\micro\\source\\repos\\SFML app\\body.png");

        m_body.setTexture(m_body_texture);
        m_rear_wheel.setOutlineThickness(2.f);
        m_front_wheel.setOutlineThickness(2.f);
        m_rear_wheel.setOutlineColor(sf::Color());
        m_front_wheel.setOutlineColor(sf::Color());
        m_rear_front.setSize(sf::Vector2f(m_body.getLocalBounds().width, 1.f));

        m_front_wheel.setOrigin(sf::Vector2f(40.5f, 40.5f));
        m_rear_wheel.setOrigin(sf::Vector2f(40.5f, 40.5f));

        m_rear_wheel.setPosition(200.f, 200.f);
        m_rear_front.setPosition(m_rear_wheel.getPosition());
        m_front_wheel.setPosition(m_rear_wheel.getPosition().x + m_rear_front.getLocalBounds().width - 1, m_rear_wheel.getPosition().y);

        m_body.setOrigin(sf::Vector2f(0.f, m_body.getTexture()->getSize().y - 1));
        m_body.setPosition(m_rear_wheel.getPosition());

        m_Origin = Origin::RearWheel;

        m_rear_front.setFillColor(sf::Color());

        std::cout << "Motorcycle created" << std::endl;
    }

    void update(float deltaTime) {
        move(deltaTime);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(m_body);
        window.draw(m_front_wheel);
        window.draw(m_rear_wheel);
        //window.draw(m_rear_front);
    }
private:
    sf::Texture m_body_texture;

    sf::Sprite m_body;
    sf::CircleShape m_front_wheel{ 40.5f };
    sf::CircleShape m_rear_wheel{ 40.5f };
    sf::RectangleShape m_rear_front{};

    Trace& m_trace;

    float m_velocity = 0.0f;
    float m_maxFallVelocity = 100.0f;

    MotoState m_state = MotoState::NoGround;
    Origin m_Origin{};

    void move(float deltaTime) {
        float yMouvement = 0.0f;

        switch (m_state)
        {
        case MotoState::NoGround:
            m_velocity = (m_velocity < m_maxFallVelocity) ? m_velocity += 5.0f : m_velocity;
            yMouvement = m_velocity * deltaTime;

            m_body.setPosition(m_body.getPosition().x, m_body.getPosition().y + yMouvement);
            m_rear_wheel.setPosition(m_rear_wheel.getPosition().x, m_rear_wheel.getPosition().y + yMouvement);
            m_front_wheel.setPosition(m_front_wheel.getPosition().x, m_front_wheel.getPosition().y + yMouvement);
            m_rear_front.setPosition(m_rear_front.getPosition().x, m_rear_front.getPosition().y + yMouvement);

            if (wheelintersects(m_rear_wheel).intersects && wheelintersects(m_front_wheel).intersects) {
                m_state = MotoState::WheelsOnGround;
            }
            else if (wheelintersects(m_rear_wheel).intersects) {
                m_state = MotoState::RareWheelOnGround;
            }
            else if (wheelintersects(m_front_wheel).intersects) {
                m_state = MotoState::FrontWheelOnGround;
            }
            break;
        case MotoState::RareWheelOnGround:
            break;
        case MotoState::FrontWheelOnGround:
            break;
        case MotoState::WheelsOnGround:
            break;
        default:
            break;
        }
    }

    LinesIntersected wheelintersects(sf::CircleShape wheel) {
        bool intersects = false;
        std::vector<Line*> linesIntersected {};
        for (Line& line : m_trace.getTrace()) {
            if (wheel.getGlobalBounds().intersects(line.getGlobalBounds())) {
                intersects = true;
                linesIntersected.push_back(&line);
            }
        }
        return LinesIntersected{ intersects, linesIntersected };
    }

    void setOrigin(Origin bodyOrigin) {
        float rotation = 0.f;
        bool leftPartRotation = false;
        bool upPartRotation = false;
        float xOrigin = 0.f;
        float yOrigin = 0.f;

        switch (bodyOrigin)
        {
        case Origin::RearWheel:
            m_body.setPosition(m_rear_wheel.getPosition());
            rotation = m_rear_front.getRotation();
            leftPartRotation = (rotation > 90 && rotation <= 270);
            upPartRotation = (rotation > 180);

            xOrigin = m_body.getOrigin().x - (leftPartRotation ? -(m_rear_front.getLocalBounds().width) + 1.f : m_rear_front.getLocalBounds().width - 1.f);
            yOrigin = m_body.getOrigin().y - (upPartRotation ? -(m_rear_front.getLocalBounds().height) + 1.f : m_rear_front.getLocalBounds().height - 1.f);

            m_body.setOrigin(xOrigin, yOrigin);



            m_Origin = Origin::RearWheel;

            break;
        case Origin::FrontWheel:
            m_body.setPosition(m_front_wheel.getPosition());
            rotation = m_rear_front.getRotation();
            leftPartRotation = (rotation > 90 && rotation <= 270);
            upPartRotation = (rotation > 180);

            xOrigin = m_body.getOrigin().x - (leftPartRotation ? m_rear_front.getLocalBounds().width - 1.f : -(m_rear_front.getLocalBounds().width) + 1.f);
            yOrigin = m_body.getOrigin().y - (upPartRotation ? m_rear_front.getLocalBounds().height - 1.f : -(m_rear_front.getLocalBounds().height) + 1.f);

            m_body.setOrigin(xOrigin, yOrigin);

            m_Origin = Origin::FrontWheel;

            break;
        default:
            break;
        }
    }
};