#pragma once

#include <SFML/Graphics.hpp>

class Component
{
public:
    bool exists = false;
};

class CTransform : public Component
{
public:
    sf::Vector2f pos = { 0.0, 0.0};
    sf::Vector2f velocity = { 0.0, 0.0 };
    float angle = 0;

    CTransform() = default;
    CTransform(const sf::Vector2f& p, const sf::Vector2f& v, const float a)
        : pos(p), velocity(v), angle(a) {}
};

class CCollision : public Component
{
public:
    float radius = 0;

    CCollision() = default;

    explicit CCollision(const float r)
        : radius(r) {}
};

class CScore : public Component
{
public:
    int score = 0;

    CScore() = default;

    explicit CScore(const int s)
        : score(s) {}
};

class CShape : public Component
{
public:
    sf::CircleShape circle;

    CShape() = default;

    CShape(const float radius, const int points, const sf::Color& fill, const sf::Color outline, const float thickness)
        : circle(radius, points)
    {
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        circle.setOrigin(sf::Vector2f(radius, radius));
    }
};

class CLifespan : public Component
{
public:
    int totalLifespan = 0;
    int remainingLifespan = 0;

    CLifespan() = default;

    explicit CLifespan(const int total)
        : totalLifespan(total), remainingLifespan(total) {}
};

class CInput : public Component
{
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool shoot = false;

    CInput() = default;
};

