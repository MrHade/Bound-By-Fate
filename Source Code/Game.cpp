//
//  Game.cpp
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

#include "Game.h"
#include "Character.h"
#include "Mob.h"
#include "TileMap.h"
#include "Weapon.h"
#include <iostream>
using namespace sf;

void Game::play()
{
    
    RenderWindow window(VideoMode(720, 460), "Bound By Fate");
    window.setFramerateLimit(60);
    Character Kyle("Game Ressources/italy_wing_walking_by_silvermistanimelover-d8y9dmy.png");
    Mob moss(Vector2f(160, 320), "Game Ressources/wolfsheet6_0.png");
    TileMap map;
    map.loadFromFile("Game Ressources/Test.map");
    map.load("Game Ressources/dg_grounds32.gif", Vector2u(32,32));

    View mainView(moss.getSprite().getPosition(),sf::Vector2f(720/1.5,460/1.5));

    Vector2i animatedWalk(0,0);//For Kyle's walk animation
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
            //Right arrow : move Kyle right
            else if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                animatedWalk.y=48*2;
                Kyle.collisionWithTileManager(map);
                Kyle.collisionWithMobileManager(moss);
                Kyle.moveRight();
                Kyle.canMove();

                moss.IA(Kyle, map);

            }
            //Left arrow : move Kyle left
            else if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                animatedWalk.y=48;
                Kyle.collisionWithTileManager(map);
                Kyle.collisionWithMobileManager(moss);
                Kyle.moveLeft();
                Kyle.canMove();
                //Mob detection test
                moss.IA(Kyle, map);
            }
            //Up arrow : move Kyle up
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                animatedWalk.y=48*3;
                Kyle.collisionWithTileManager(map);
                Kyle.collisionWithMobileManager(moss);
                Kyle.moveUp();
                Kyle.canMove();
                
                moss.IA(Kyle, map);

            }
            //Down arrow : move Kyle down
            else if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                animatedWalk.y=0;
                Kyle.collisionWithTileManager(map);
                Kyle.collisionWithMobileManager(moss);
                Kyle.moveDown();
                Kyle.canMove();
                
                moss.IA(Kyle, map);
            }

            if(Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::Left) || //So walk animation only occur
               Keyboard::isKeyPressed(Keyboard::Up)   ||Keyboard::isKeyPressed(Keyboard::Down))  //when Kyle moved
            {
            //Animates the Kyle's movements
            animatedWalk.x += 47;
            if(animatedWalk.x>=47*2)
                animatedWalk.x=0;

            Kyle.getSprite().setTextureRect(IntRect(animatedWalk.x,animatedWalk.y,47,47));
            }
        }
        //Center the game view on the Kyle
        mainView.setCenter(Kyle.getSprite().getPosition());
        window.setView(mainView);
        //Draw the graphics
        window.clear();
        window.draw(map);
        window.draw(Kyle.getSprite());
        window.draw(moss.getSprite());
        window.draw(moss.debugInitalPoint);
        window.display();
    }


}
