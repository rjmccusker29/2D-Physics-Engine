#pragma once
#include <SFML/Graphics.hpp>


//class defining our objects
class Vobject{
private:
    sf::Vector2f position_curr;
    sf::Vector2f position_old;
    sf::Vector2f acceleration = {0.0f, 1000.0f};
    float radius;
    int active;   //an array of objects is created alongisde an engine; each object is inactive by default

public:
    Vobject();
    Vobject(sf::Vector2f pos, float rad);
    void updatePosition(float dt);
    float getRadius();
    int isActive();
    void setActive();
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
};