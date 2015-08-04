//
//  Mob.cpp
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Mob.h"
#include "UsefulTools.h"
using namespace sf;

Mob::Mob(Vector2f initialPosition,std::string pathToTexture) :
Mobile(), m_detectionZoneWidth(224),m_detectionZoneHeight(224),m_initialPosition(initialPosition),m_isTracking(false),
m_isWalking(false),m_steps(0),m_maxSteps(10)

{
    m_texture.loadFromFile(pathToTexture);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(IntRect(0,0,32,64));
    m_sprite.setScale(0.75,0.5);
    m_sprite.setPosition(initialPosition.x,initialPosition.y);//initial position of the mob

    
}

void Mob::detectMobile(Mobile target, TileMap map)
{
    
    detectionZoneDebug.setPosition(((m_sprite.getPosition().x)-96+12), (m_sprite.getPosition().y)-96+16);
    detectionZoneDebug.setSize(Vector2f(192,192));
    detectionZoneDebug.setFillColor(Color::Red);
    
    //If another Mobile enter this zone the current Mobile will see him and can attack him.
    sf::FloatRect detectionZone((m_sprite.getPosition().x)-96+12,(m_sprite.getPosition().y-96+16),m_detectionZoneWidth,m_detectionZoneHeight);  //It's not an attribut because mob has a new one after each movements

    if(target.getSprite().getGlobalBounds().intersects(detectionZone))//If a mobile intersects mob's detection zone
    {
        //trackMobile(target);//TRACK HIM !
    }
    else
    {
        walk(map);
    }
    if(!m_isTracking && !m_isWalking)
    {
        goTo(map, m_initialPosition);
    }
    m_isTracking=false; // Mob finished tracking

}
void Mob::trackMobile(Mobile target)
{
    m_isWalking=false;//Mob is not walking now
    m_isTracking=true;//Mob starts tracking
    
    if(Random::getIntRandom(0, 1)==0)//This will make movements more realistic
    {
    collisionWithMobileManager(target);
    //If target is above mob move up
    if (m_canMoveUp && target.getSprite().getPosition().y<m_sprite.getPosition().y)
    {
        moveUp();
        m_sprite.setTextureRect(IntRect(5*32,0,32,64));
        m_sprite.setScale(0.75,0.5);
    }
    //If target is under mob move down
    else if (m_canMoveDown && target.getSprite().getPosition().y>m_sprite.getPosition().y)
    {
        moveDown();
        m_sprite.setTextureRect(IntRect(0,0,32,64));
        m_sprite.setScale(0.75,0.5);
    }
    //If target is on the left of mob move left
    else if (m_canMoveLeft && target.getSprite().getPosition().x < m_sprite.getPosition().x)
    {
        moveLeft();
        m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
        m_sprite.setScale(0.5,0.75);
    }
    //If target is on the right of mob move right
    else if (m_canMoveRight && target.getSprite().getPosition().x>m_sprite.getPosition().x)
    {
        moveRight();
        m_sprite.setTextureRect(IntRect(10*32,0,64,32));
        m_sprite.setScale(0.5,0.75);

    }
        
    }
    else
    {
        collisionWithMobileManager(target);
        //If target is on the left of mob move left
        if (m_canMoveLeft && target.getSprite().getPosition().x < m_sprite.getPosition().x)
        {
            moveLeft();
            m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
            m_sprite.setScale(0.5,0.75);
        }
        //If target is on the right of mob move right
        else if (m_canMoveRight && target.getSprite().getPosition().x>m_sprite.getPosition().x)
        {
            moveRight();
            m_sprite.setTextureRect(IntRect(10*32,0,64,32));
            m_sprite.setScale(0.5,0.75);
            
        }
        //If target is above mob move up
        else if (m_canMoveUp && target.getSprite().getPosition().y<m_sprite.getPosition().y)
        {
            moveUp();
            m_sprite.setTextureRect(IntRect(5*32,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If target is under mob move down
        else if (m_canMoveDown && target.getSprite().getPosition().y>m_sprite.getPosition().y)
        {
            moveDown();
            m_sprite.setTextureRect(IntRect(0,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }


    }
}


void Mob::goTo(TileMap map, Vector2f destination)
{
    if(Random::getIntRandom(0, 1)==0)//This will make movements more realistic
    {
        collisionWithTileManager(map);
        //If initial position is above mob move up
        if (m_canMoveUp && destination.y<m_sprite.getPosition().y)
        {
            moveUp();
            m_sprite.setTextureRect(IntRect(5*32,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If initial position is under mob move down
        else if (m_canMoveDown && destination.y>m_sprite.getPosition().y)
        {
            moveDown();
            m_sprite.setTextureRect(IntRect(0,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If initial position is on the left of mob move left
        else if (m_canMoveLeft && destination.x < m_sprite.getPosition().x)
        {
            moveLeft();
            m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
            m_sprite.setScale(0.5,0.75);
        }
        //If initial position is on the right of mob move right
        else if (m_canMoveRight && destination.x>m_sprite.getPosition().x)
        {
            moveRight();
            m_sprite.setTextureRect(IntRect(10*32,0,64,32));
            m_sprite.setScale(0.5,0.75);
            
        }
        
    }
    else
    {
        collisionWithTileManager(map);
        //If initial position is on the left of mob move left
        if (m_canMoveLeft && destination.x < m_sprite.getPosition().x)
        {
            moveLeft();
            m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
            m_sprite.setScale(0.5,0.75);
        }
        //If initial position is on the right of mob move right
        else if (m_canMoveRight && destination.x>m_sprite.getPosition().x)
        {
            moveRight();
            m_sprite.setTextureRect(IntRect(10*32,0,64,32));
            m_sprite.setScale(0.5,0.75);
            
        }
        //If initial position is above mob move up
        else if (m_canMoveUp && destination.y<m_sprite.getPosition().y)
        {
            moveUp();
            m_sprite.setTextureRect(IntRect(5*32,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If initial position is under mob move down
        else if (m_canMoveDown && destination.y>m_sprite.getPosition().y)
        {
            moveDown();
            m_sprite.setTextureRect(IntRect(0,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        
        
    }
    

}

void Mob::walk(TileMap map)
{
    m_isWalking=true;
    collisionWithTileManager(map);
    if(Random::getIntRandom(0, 3)==0 && m_steps<m_maxSteps)
    {
        moveRight();
        m_steps++;

    }
    else if (Random::getIntRandom(0, 3)==1 && m_steps<m_maxSteps)
    {
        moveLeft();
        m_steps++;

    }
    else if (Random::getIntRandom(0, 3)==2 && m_steps<m_maxSteps)
    {
        moveUp();
        m_steps++;

    }
    else if (Random::getIntRandom(0, 3)==3 && m_steps<m_maxSteps)
    {
        moveDown();
        m_steps++;
    }
    else if (m_steps>=10)
    {
        goTo(map, m_initialPosition);
        m_steps=0;
    }
    
}














