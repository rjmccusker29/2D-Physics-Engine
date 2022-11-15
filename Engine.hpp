#pragma once
#include <SFML/Graphics.hpp>
#include "Vobject.hpp"
#include <cmath>
#include <iostream>


//Class defining the physics engine. Conatins all objects and determines their positions at each point in time. 
class Engine{
private:
    Vobject objs[1000];    //inactive objects created when engine is created
    // area is the space in the window that the objects will be constrained to 
    sf::Vector2f area_center = {500.0f, 500.0f};
    float area_radius = 450.0f;
public:
    Engine();
    void update(float dt);
    void updatePositions(float dt);
    void constrain_to_area();
    void applyCollisions();
    Vobject* getObjects();
    void addObject(sf::Vector2f position, float radius);
    sf::Vector2f get_area_center();
    float get_area_radius();
};