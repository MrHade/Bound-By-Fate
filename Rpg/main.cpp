#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Character.h"
using namespace sf;
int main(int, char const**)
{
    RenderWindow window(VideoMode(720, 460), "RPG");
    TileMap map;
    Character character("Soufiane");
    map.loadFromFile("/Users/mrhade/Desktop/Rpg/Test.map");
    map.load("/Users/mrhade/Desktop/Rpg/dg_grounds32.gif", Vector2u(32,32));
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            else if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            //Right arrow : move character right
            else if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                character.moveRight();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                character.moveLeft();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                character.moveUp();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                character.moveDown();
            }
        }
        window.clear();
        window.draw(map);
        window.draw(character.getSprite());
        window.display();
    }

    return EXIT_SUCCESS;
}
