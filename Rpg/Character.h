//
//  Character.h
//  Rpg
//
//  Created by Soufiane on 23/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __Rpg__Character__
#define __Rpg__Character__
#include <string>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
class Character
{
public:
    Character(std::string m_name);
    sf::Sprite getSprite();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    
    void canMoveRight();//Set canMoveRight to true
    void canMoveLeft();//Set canMoveLeft to true
    void canMoveUp();//Set canMoveUp to true
    void canMoveDown();//Set canMoveDown to true
    
    void collisionManager(TileMap);//Collision between character and specific tiles

    
private:
    std::string m_name;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    bool m_canMoveRight,m_canMoveLeft,m_canMoveUp,m_canMoveDown;
};
#endif /* defined(__Rpg__Character__) */
