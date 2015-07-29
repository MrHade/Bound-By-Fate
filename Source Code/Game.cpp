//
//  Game.cpp
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Character.h"
#include "Mob.h"
#include "TileMap.h"
using namespace sf;
void Game::play()
{
    
    RenderWindow window(VideoMode(720, 460), "Bound By Fate");
    window.setFramerateLimit(60);
    Mobile character("Soufiane");
    Mob moss;
    TileMap map;
    map.loadFromFile("/Users/mrhade/Documents/C++/Rpg/Game Ressources/Test.map");
    map.load("/Users/mrhade/Documents/C++/Rpg/Game Ressources/dg_grounds32.gif", Vector2u(32,32));
    
    View mainView(character.getSprite().getPosition(),sf::Vector2f(720/1.5,460/1.5));
    
    Vector2i animatedWalk(0,0);//For character's walk animation
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
                animatedWalk.y=48*2;
                character.collisionWithTileManager(map);
                character.moveRight();
            }
            //Left arrow : move character left
            else if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                animatedWalk.y=48;
                character.collisionWithTileManager(map);
                character.moveLeft();
            }
            //Up arrow : move character up
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                animatedWalk.y=48*3;
                character.collisionWithTileManager(map);
                character.moveUp();
            }
            //Down arrow : move character down
            else if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                animatedWalk.y=0;
                character.collisionWithTileManager(map);
                character.moveDown();
            }
            if(Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::Left) || //So walk animation only occur
               Keyboard::isKeyPressed(Keyboard::Up)   ||Keyboard::isKeyPressed(Keyboard::Down))  //when character moved
            {
            //Animates the character's movements
            animatedWalk.x += 47;
            if(animatedWalk.x>=47*2)
                animatedWalk.x=0;
           
            character.getSprite().setTextureRect(IntRect(animatedWalk.x,animatedWalk.y,47,47));
            }
        }
        character.canMove();

        //Center the game view on the character
        mainView.setCenter(character.getSprite().getPosition());
        window.setView(mainView);
        //Draw the graphics
        window.clear();
        window.draw(map);
        window.draw(character.getSprite());
        window.draw(moss.getSprite());
        window.display();
    }
    

}