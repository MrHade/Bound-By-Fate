#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Character.h"
#include <iostream>
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
                character.collisionManager(map);
                character.moveRight();
                std::cout<<"Character's current position : ("
                << character.getSprite().getPosition().x<<","
                <<character.getSprite().getPosition().y<<")"<<std::endl;
            }
            //Left arrow : move character left
            else if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                character.collisionManager(map);
                character.moveLeft();
                std::cout<<"Character's current position : ("
                << character.getSprite().getPosition().x<<","
                <<character.getSprite().getPosition().y<<")"<<std::endl;
                
            }
            //Up arrow : move character up
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                character.collisionManager(map);
                character.moveUp();
                std::cout<<"Character's current position : ("
                << character.getSprite().getPosition().x<<","
                <<character.getSprite().getPosition().y<<")"<<std::endl;
                
            }
            //Down arrow : move character down
            else if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                character.collisionManager(map);
                character.moveDown();
                std::cout<<"Character's current position : ("
                << character.getSprite().getPosition().x<<","
                <<character.getSprite().getPosition().y<<")"<<std::endl;
                
            }
        }
        
        character.canMoveRight();
        character.canMoveLeft();
        character.canMoveUp();
        character.canMoveDown();
        
        //Draw the graphics
        window.clear();
        window.draw(map);
        window.draw(character.getSprite());
        window.display();
    }

    return EXIT_SUCCESS;
}











