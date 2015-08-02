//
//  Mobile.h
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __Bound_By_Fate__Mobile__
#define __Bound_By_Fate__Mobile__
#include <string>
#include "TileMap.h"
#include <SFML/Graphics.hpp>

class Mobile
{
public:
    Mobile(std::string pathTotexture);
    Mobile();
    sf::Sprite& getSprite();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void canMove();//The mobile can move again
    
    void collisionWithTileManager(TileMap);//Collision between a mobile and specific tiles
    void collisionWithMobileManager(Mobile);//Collision between 2 mobile
    
protected:
    std::string m_name;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    bool m_canMoveRight,m_canMoveLeft,m_canMoveUp,m_canMoveDown;
};
#endif /* defined(__Bound_By_Fate__Mobile__) */
