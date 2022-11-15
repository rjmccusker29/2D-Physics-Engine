#pragma once
#include "Engine.hpp"

//class defining an object that will all the objects in an engine onto the window
class Drawer{
private:
    sf::RenderWindow &window;
public:
    explicit Drawer(sf::RenderWindow &win) : window{win}{};
    void draw(Engine &engine);
};