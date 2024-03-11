#pragma once
#include <SFML/Graphics.hpp>
#include "Misc.h"
#include <vector>
#include <iostream>

class Line {
public:
    Line(sf::RenderWindow& window, LineParameters params, Line* previousLine = nullptr) :
        m_line(sf::RectangleShape(sf::Vector2f(params.length, 1.f))), m_rorationAngle(params.rotationAngle), m_previousLine(previousLine)
    {
        if (!previousLine) {
            m_line.setPosition(sf::Vector2f(0.f, window.getSize().y - 150.f));
        }
        else 
        {
            m_line.setPosition(
                sf::Vector2f(
                    m_previousLine->getPosition().x + m_previousLine->getGlobalBounds().width,
                    m_previousLine->getPosition().y + 
                    ((m_previousLine->getRotation() > 180.f) ? -(m_previousLine->getGlobalBounds().height) : m_previousLine->getGlobalBounds().height)
                )
            );
        }

        m_line.rotate(m_rorationAngle);
        m_line.setFillColor(sf::Color(0, 0, 0));
    }

    Coordinates getPosition() {
        return Coordinates{ m_line.getPosition().x, m_line.getPosition().y };
    }

    sf::FloatRect getGlobalBounds() {
        return m_line.getGlobalBounds();
    }

    float getRotation() {
        return m_rorationAngle;
    }

    void move(float xMouvement) {
        m_line.setPosition(m_line.getPosition().x - xMouvement, m_line.getPosition().y);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(m_line);
    }
private:
    sf::RectangleShape m_line{};
    float m_rorationAngle = 0.f;
    Line* m_previousLine = nullptr;
};

class Trace {
public:
    Trace(sf::RenderWindow& window) {
        Line firstLine(window, LineParameters{});
        m_trace.push_back(firstLine);
    }
    Trace(sf::RenderWindow& window, std::vector<LineParameters> level) {
        m_trace.push_back(Line { window, LineParameters{} });

        for (LineParameters param : level) {
            m_trace.push_back(Line{ window, param, &(m_trace[m_trace.size() - 1]) });
        }
    }

    std::vector<Line>& getTrace() {
        return m_trace;
    }

    void draw(sf::RenderWindow& window) {
        for (Line element : m_trace) {
            element.draw(window);
        }
    }

    void update(float deltaTime) {
        move(deltaTime);
    }

private:
    const float m_lowerBoundary = 100.f;
    std::vector<Line> m_trace{};
    sf::RenderWindow* m_window = nullptr;

    float m_velocity = 0.0f;
    float m_maxForwardVelocity = 100.0f;
    float m_maxBackwardVelocity = 20.0f;
    int m_direction = 1;

    void move(float deltaTime) {
        float xMouvement = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            m_direction = static_cast<int>(Direction::Forward);

            m_velocity = (m_velocity < m_maxForwardVelocity) ? m_velocity += 5.0f : m_velocity;
            xMouvement = m_velocity * deltaTime * m_direction;
            std::cout << m_direction << " " << m_velocity << " " << xMouvement << std::endl;
            for (Line& line : m_trace) {
                line.move(xMouvement);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            m_direction = static_cast<int>(Direction::Backward);

            m_velocity = (m_velocity < m_maxBackwardVelocity) ? m_velocity += 2.0f : m_velocity;
            xMouvement = m_velocity * deltaTime * m_direction;
            std::cout << m_direction << " " << m_velocity << " " << xMouvement << std::endl;
            for (Line& line : m_trace) {
                line.move(xMouvement);
            }
        }
        else {
            if (m_velocity - 2.0f < 0) {
                m_velocity = 0.0f;
            }
            else
            {
                m_velocity -= 2.0f;
                xMouvement = m_velocity * deltaTime * m_direction;

                for (Line& line : m_trace) {
                    line.move(xMouvement);
                }
            }
        }
    }
};