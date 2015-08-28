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
m_isWalking(false),m_isGoingToDestionation(false),m_steps(0),m_maxSteps(10)

{
    m_texture.loadFromFile(pathToTexture);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(IntRect(0,0,32,64));
    m_sprite.setScale(0.75,0.5);
    m_sprite.setPosition(initialPosition.x,initialPosition.y);//initial position of the mob

    //Debug
    debugInitalPoint.setPosition(initialPosition);
    debugInitalPoint.setSize(Vector2f(32,32));
    debugInitalPoint.setFillColor(Color::Red);
    
}

void Mob::IA(RenderWindow &window,Mobile target, TileMap map)
{
    
    
    //If another Mobile enter this zone the current Mobile will see him and can attack him.
    sf::FloatRect detectionZone((m_sprite.getPosition().x)-96+12,(m_sprite.getPosition().y-96+16),0,0);  //It's not an attribut because mob has a new one after each movements
 
    //If a mobile intersects mob's detection zone
    if(target.getSprite().getGlobalBounds().intersects(detectionZone) && !m_isGoingToDestionation)
    {
        collisionWithMobileManager(target);
        collisionWithTileManager(map);
        trackMobile(target);//TRACK HIM !
    }
    else if (!m_isGoingToDestionation)
    {
        collisionWithMobileManager(target);
        collisionWithTileManager(map);
        walk();
    }
    if(!m_isTracking && !m_isWalking && m_isGoingToDestionation)
    {
        collisionWithMobileManager(target);
        collisionWithTileManager(map);
        goTo(window,m_initialPosition);
    }
    //Reset the states to false for the next frame
    m_isTracking=false;
    m_isWalking=false;
    canMove();

}

void Mob::trackMobile(Mobile target)
{
    m_isWalking=false;//Mob is not walking now
    m_isTracking=true;//Mob starts tracking
    
    collisionWithMobileManager(target);
    
    if(Random::getIntRandom(0, 1)==0)//This will make movements more realistic
    {
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


void Mob::goTo(RenderWindow &window,Vector2i destination)
{
    Vector2f wdestination= window.mapPixelToCoords(destination);//destination in the world
    
    if(Random::getIntRandom(0, 1)==0)//This will make the mob take random paths
    {
        //If initial position is above mob move up
        if (m_canMoveUp && wdestination.y<m_wposition.y)
        {
            moveUp();
            m_sprite.setTextureRect(IntRect(5*32,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If initial position is under mob move down
        else if (m_canMoveDown && wdestination.y>m_wposition.y)
        {
            moveDown();
            m_sprite.setTextureRect(IntRect(0,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If initial position is on the left of mob move left
        else if (m_canMoveLeft && wdestination.x < m_wposition.x)
        {
            moveLeft();
            m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
            m_sprite.setScale(0.5,0.75);
        }
        //If initial position is on the right of mob move right
        else if (m_canMoveRight && wdestination.x>m_wposition.x)
        {
            moveRight();
            m_sprite.setTextureRect(IntRect(10*32,0,64,32));
            m_sprite.setScale(0.5,0.75);
            
        }
        //If the mob arrived to destination, stop the function goTo and let's the mob do something else
        else if (wdestination.x==m_wposition.x && wdestination.y==m_wposition.y)
        {
            m_isGoingToDestionation=false;
        }
    }
    else
    {
        //If initial position is on the left of mob move left
        if (m_canMoveLeft && wdestination.x < m_wposition.x)
        {
            moveLeft();
            m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
            m_sprite.setScale(0.5,0.75);
        }
        //If initial position is on the right of mob move right
        else if (m_canMoveRight && wdestination.x>m_wposition.x)
        {
            moveRight();
            m_sprite.setTextureRect(IntRect(10*32,0,64,32));
            m_sprite.setScale(0.5,0.75);
            
        }
        //If initial position is above mob move up
        else if (m_canMoveUp && wdestination.y<m_wposition.y)
        {
            moveUp();
            m_sprite.setTextureRect(IntRect(5*32,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If initial position is under mob move down
        else if (m_canMoveDown && wdestination.y>m_wposition.y)
        {
            moveDown();
            m_sprite.setTextureRect(IntRect(0,0,32,64));
            m_sprite.setScale(0.75,0.5);
        }
        //If the mob arrived to destination, stop the function goTo and let's the mob do something else
        else if (wdestination.x==m_wposition.x && wdestination.y==m_wposition.y)
        {
            m_isGoingToDestionation=false;
        }
        
    }
    

}

void Mob::walk()
{
    m_isWalking=true;
    int randomNumber= Random::getIntRandom(0, 3);
    //Mob will move in a random direction untill he's to far from his initial point
    if(randomNumber==0 && m_steps<m_maxSteps && m_canMoveRight)
    {
        moveRight();
        m_sprite.setTextureRect(IntRect(10*32,0,64,32));
        m_sprite.setScale(0.5,0.75);
        
        m_steps++;

    }
    else if (randomNumber==1 && m_steps<m_maxSteps && m_canMoveLeft)
    {
        moveLeft();
        m_sprite.setTextureRect(IntRect(10*32,4*64,64,32));
        m_sprite.setScale(0.5,0.75);
        
        m_steps++;

    }
    else if (randomNumber==2 && m_steps<m_maxSteps && m_canMoveUp)
    {
        moveUp();
        m_sprite.setTextureRect(IntRect(5*32,0,32,64));
        m_sprite.setScale(0.75,0.5);

        m_steps++;

    }
    else if (randomNumber==3 && m_steps<m_maxSteps && m_canMoveDown)
    {
        moveDown();
        m_sprite.setTextureRect(IntRect(0,0,32,64));
        m_sprite.setScale(0.75,0.5);
        
        m_steps++;
    }
    else if (m_steps>=m_maxSteps-1)
    {
        m_isGoingToDestionation=true;
        m_isWalking=false;
        m_steps=0;
    }
    
}














