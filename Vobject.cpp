#include "Vobject.hpp"

Vobject::Vobject(){
    this->active = 0;
}

Vobject::Vobject(sf::Vector2f pos, float rad){
    this->position_curr = pos;
    this->position_old = pos;
    this->radius = rad;
}

//based on Verlet integration
void Vobject::updatePosition(float dt){
    sf::Vector2f pos_change = position_curr - position_old;
    position_old = position_curr;
    position_curr = position_curr + pos_change + this->acceleration * dt * dt;
}

float Vobject::getRadius(){
    return this->radius;
}

int Vobject::isActive(){
    return this->active;
}

void Vobject::setActive(){
    this->active = 1;
}

sf::Vector2f Vobject::getPosition(){
    return this->position_curr;
}

void Vobject::setPosition(sf::Vector2f pos){
    this->position_curr = pos;
}