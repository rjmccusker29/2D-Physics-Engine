#include <SFML/Graphics.hpp>
#include "Vobject.hpp"
#include "Engine.hpp"
#include "Drawer.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Engine", sf::Style::Default);
    int framerate = 60;
    window.setFramerateLimit(framerate);

    Engine engine;
    Drawer drawer{window};
    sf::Clock clock;

    sf::Vector2f spawn_pos = {500.0f, 150.0f};
    float x_degrees = 0.0f;
    float size_degrees = 0.0f;
    float spawn_size = 25.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    engine.addObject(spawn_pos, spawn_size);
                    
                    x_degrees += 0.5f;
                    spawn_pos.x = 500.0f + 200.0f*sin(x_degrees);
                    size_degrees += 0.5f;
                    spawn_size = 25.0f + 20.0f*sin(spawn_size);
                    
                } else if (event.key.code == sf::Keyboard::F)
                    engine.addObject({700.0f, 200.0f}, 15.0f);
            }

        }

        engine.update(clock.getElapsedTime().asSeconds());
        clock.restart();
        window.clear();
        drawer.draw(engine);
        window.display();
    }

    return 0;
}