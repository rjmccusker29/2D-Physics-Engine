#include "Engine.hpp"

Engine::Engine(){}

void Engine::update(float dt){
    applyCollisions();
    constrain_to_area();
    updatePositions(dt);
}

//if an object is inactive, all objects with a higher index must be inactive
void Engine::updatePositions(float dt){
    for (int i=0; i<1000; i++){
        if (!this->objs[i].isActive())
            break;
        this->objs[i].updatePosition(dt);
    }
}

void Engine::constrain_to_area(){
    for (int i=0; i<1000; i++){
        Vobject& obj = this->objs[i];
        if (!obj.isActive())
            break;
        sf::Vector2f dist_vector = obj.getPosition() - this->area_center;
        float dist_scalar_sq = dist_vector.x * dist_vector.x + dist_vector.y * dist_vector.y; //square root is costly, will only find if necessary
        float radii_diff = this->area_radius - obj.getRadius();
        if (dist_scalar_sq > radii_diff * radii_diff){
            float dist_scalar = sqrt(dist_scalar_sq);
            sf::Vector2f dist_unit_vector = dist_vector / dist_scalar;
            //move object to the maximum distance from the center without being outside the area
            //unit vector * distance required
            sf::Vector2f new_position = this->area_center + dist_unit_vector * (this->area_radius - obj.getRadius());
            obj.setPosition(new_position);
        }
    }
}

void Engine::applyCollisions(){
    for (int i=0; i<1000; i++){
        Vobject& obj1 = getObjects()[i];
        if (!obj1.isActive()) break;
        for (int j=0; j<1000; j++){
            Vobject& obj2 = getObjects()[j];
            if (i == j) continue;
            if (!obj2.isActive()) break;

            sf::Vector2f dist_vector = obj1.getPosition() - obj2.getPosition();
            float dist_sq_scalar = dist_vector.x * dist_vector.x + dist_vector.y * dist_vector.y;
            float radii_sum = obj1.getRadius() + obj2.getRadius();
            if (dist_sq_scalar < radii_sum * radii_sum){
                float dist_scalar = sqrt(dist_sq_scalar);
                sf::Vector2f unit_vector = dist_vector / dist_scalar;

                float mass_ratio_1 = obj1.getRadius() / (obj1.getRadius() + obj2.getRadius());
                float mass_ratio_2 = 1 - mass_ratio_1;

                //move each object until they are touching not overlapping. change in position relative to size to simulate mass
                float dist_required = radii_sum - dist_scalar;
                obj1.setPosition(obj1.getPosition() + unit_vector * mass_ratio_2 * dist_required);
                obj2.setPosition(obj2.getPosition() - unit_vector * mass_ratio_1 * dist_required);
            }
        }
    }
}

Vobject* Engine::getObjects(){
    return objs;
}

void Engine::addObject(sf::Vector2f position, float radius){
    for (int i=0; i<1000;i++)
        if (!this->objs[i].isActive()){
            this->objs[i] = Vobject(position, radius);
            this->objs[i].setActive();
            break;
        }
}

sf::Vector2f Engine::get_area_center(){
    return this->area_center;
}

float Engine::get_area_radius(){
    return this->area_radius;
}

