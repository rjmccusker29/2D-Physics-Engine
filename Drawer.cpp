#include "Drawer.hpp"

void Drawer::draw(Engine &engine){

    //outlining the constraining area
    sf::CircleShape area(engine.get_area_radius());
    area.setOrigin(engine.get_area_radius(), engine.get_area_radius());
    area.setPointCount(128);
    area.setPosition(engine.get_area_center());
    area.setFillColor(sf::Color::Blue);
    this->window.draw(area);

    //modifying a circle to match each object then drawing to screen
    sf::CircleShape circle(1.0f);
    circle.setPointCount(32);
    circle.setOrigin(1.0f, 1.0f);
    circle.setFillColor(sf::Color::White);
    for (int i=0; i<1000; i++){
        Vobject obj = engine.getObjects()[i];
        if (!obj.isActive())
            break;
        circle.setPosition(obj.getPosition());
        circle.setScale(obj.getRadius(), obj.getRadius());
        this->window.draw(circle);
    }
}

