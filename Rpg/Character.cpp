//
//  Character.cpp
//  Rpg
//
//  Created by Soufiane on 23/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Character.h"

Character::Character(std::string m_name)
{
    m_texture.loadFromFile("/Users/mrhade/Desktop/Rpg/Character_Hero_Archor.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,100,100));// Character is 100x100
    m_sprite.setScale(0.32, 0.32);//Now the character has the same size as the tiles 32x32
    }
sf::Sprite Character::getSprite()
{
    return m_sprite;
}
void Character::moveRight()
{
    m_sprite.move(32,0);
    m_sprite.setTextureRect(sf::IntRect(0,0,100,100));//Puts the correct TextureRect from the char file
    m_sprite.setScale(-0.32, 0.32);//Character looks to the right
    
}
void Character::moveLeft()
{
    m_sprite.move(-32, 0);
    m_sprite.setTextureRect(sf::IntRect(0,0,100,100));//Puts the correct TextureRect from the char file
    m_sprite.setScale(0.32, 0.32);//Character looks to the left
}
void Character::moveUp()
{
    m_sprite.move(0, -32);
    m_sprite.setTextureRect(sf::IntRect(0,100,100,100));//Character looks up
}
void Character::moveDown()
{
    m_sprite.move(0, 32);
    m_sprite.setTextureRect(sf::IntRect(0,200,100,100));//Character looks down
    
}








