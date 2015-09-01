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
#include <iostream>
using namespace sf;

void Game::play()
{
    
    RenderWindow window(VideoMode(720, 460), "Bound By Fate");
    window.setFramerateLimit(60);
    Character player("Game Ressources/italy_wing_walking_by_silvermistanimelover-d8y9dmy.png");
    Mob *moss= new Mob(Vector2f(32*4,32*9),"Game Ressources/wolfsheet6_0.png");
    addMob(moss);
    Mob *a=new Mob(Vector2f(32*10,32*9),"Game Ressources/wolfsheet6_0.png");
    addMob(a);
    TileMap map;
    map.loadFromFile("Game Ressources/Test.map");
    map.load("Game Ressources/dg_grounds32.gif", Vector2u(32,32));

    View mainView(player.getSprite().getPosition(),sf::Vector2f(720/1.5,460/1.5));

    
    while (window.isOpen())
    {
        window.clear();
        window.draw(map);
        
        updateMobs(window, player, map);
        manageEvents(window, player, map);

        //Center the game view on the player
        mainView.setCenter(player.getSprite().getPosition());
        window.setView(mainView);
        
        window.draw(player);
        window.display();
    }


}

bool Game::addMob(Mob *newMob)
{
    //Search for a free slot
    for(int i(0);i<activeMobs.size();i++)
    {
        if(activeMobs[i]==NULL)
        {
            activeMobs[i]=newMob;//Fill the slot with the new mob
            return true;
        }
    }
    //No more free slot -> create a new one !
    activeMobs.push_back(newMob);
    return true;
}

bool Game::deleteMob(Mob *mobToDelete)
{
    //Search the mob to delete
    for(int i(0);i<activeMobs.size();i++)
    {
        if(activeMobs[i]==mobToDelete)
        {
            delete mobToDelete;//Desallocate the mob
            activeMobs[i]=NULL;//The slot is now free
            return true;
        }
    }
    //Error: mob not found
    std::cout<<"Error: The mob you're trying to delete doesn't existe ! ";
    return false;
}

void Game::deleteAllMobs()
{
    for(int i(0);i<activeMobs.size();i++)
    {
        delete activeMobs[i];
    }
    activeMobs.clear();
}

void Game::updateMobs(sf::RenderWindow &window, Mobile target, TileMap map)
{
    for(int i(0);i<activeMobs.size();i++)
    {
        activeMobs[i]->IA(window, target, map);
        activeMobs[i]->setWPosition(window.mapPixelToCoords(Vector2i(activeMobs[i]->getSprite().getPosition())));
        window.draw(*activeMobs[i]);
    }
}

void Game::manageEvents(sf::RenderWindow &window, Character &player, TileMap map)
{

    sf::Event event;
    while (window.pollEvent(event))
    {

    // Close window : exit
    if (event.type == Event::Closed)
    {
        window.close();
        deleteAllMobs();
    }
    
    // Escape pressed : exit
    else if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
        deleteAllMobs();
    }
    //Right arrow : move player right
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        player.getAnimatedWalk().y=48*2;
        player.collisionWithTileManager(map);
        player.moveRight();
        player.canMove();
    }
    //Left arrow : move player left
    else if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        player.getAnimatedWalk().y=48;
        player.collisionWithTileManager(map);
        player.moveLeft();
        player.canMove();
    }
    //Up arrow : move player up
    else if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        player.getAnimatedWalk().y=48*3;
        player.collisionWithTileManager(map);
        player.moveUp();
        player.canMove();
        
    }
    //Down arrow : move player down
    else if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        player.getAnimatedWalk().y=0;
        player.collisionWithTileManager(map);
        player.moveDown();
        player.canMove();
        
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::Left) || //So walk animation only occur
           Keyboard::isKeyPressed(Keyboard::Up)   ||Keyboard::isKeyPressed(Keyboard::Down))  //when pler moved
    {
        //Animates the plaer's movements
        player.getAnimatedWalk().x += 47;
        if(player.getAnimatedWalk().x>=47*2)
        player.getAnimatedWalk().x=0;
            
        player.getSprite().setTextureRect(IntRect(player.getAnimatedWalk().x,player.getAnimatedWalk().y,47,47));
        }
    }

}







