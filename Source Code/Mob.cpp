//
//  Mob.cpp
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Mob.h"
#include <iostream>
using namespace sf;

Mob::Mob(int xPosition,int yPosition,std::string pathToTexture) : Mobile()
{
    m_texture.loadFromFile(pathToTexture);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(IntRect(0,0,32,64));
    m_sprite.setScale(0.75,0.5);
    m_sprite.setPosition(xPosition,yPosition);//initial position of the mob

    
}

void Mob::detectMobile(Mobile target)
{
    
    detectionZoneDebug.setPosition(((m_sprite.getPosition().x)-96+12), (m_sprite.getPosition().y)-96+16);
    detectionZoneDebug.setSize(Vector2f(192,192));
    detectionZoneDebug.setFillColor(Color::Red);
    sf::FloatRect detectionZone((m_sprite.getPosition().x)-96+12,(m_sprite.getPosition().y-96+16),192,192);
    //If another Mobile enter this zone the current Mobile will see him and can attack him.

    if(target.getSprite().getGlobalBounds().intersects(detectionZone))
    {
        trackMobile(target);
    }
}
void Mob::trackMobile(Mobile target)
{
    //If target is above mob move up
    if (m_canMoveUp && target.getSprite().getPosition().y<m_sprite.getPosition().y)
    {
        moveUp();
    }
    //If target is under mob move down
    else if (m_canMoveDown && target.getSprite().getPosition().y>m_sprite.getPosition().y)
    {
        moveDown();
    }
    collisionWithMobileManager(target);
    //If target is on the left of mob move left
    if(m_canMoveLeft && target.getSprite().getPosition().x<m_sprite.getPosition().x)
    {
        moveLeft();
    }
    //If target is on the right of mob move right
    else if (m_canMoveRight && target.getSprite().getPosition().x>m_sprite.getPosition().x)
    {
        moveRight();
    }

} 