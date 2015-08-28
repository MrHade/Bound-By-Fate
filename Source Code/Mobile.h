//
//  Mobile.h
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __Bound_By_Fate__Mobile__
#define __Bound_By_Fate__Mobile__
#include "TileMap.h"
#include "Weapon.h"

#include <SFML/Graphics.hpp>

class Mobile : public sf::Drawable, sf::Transformable
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
    
    void updatePosition();
    
    void collisionWithTileManager(TileMap);//Collision between a mobile and specific tiles
    void collisionWithMobileManager(Mobile);//Collision between 2 mobile
    
    void setWPosition(sf::Vector2f position);
    
    void setWeapon(Weapon weapon);

protected:
    std::string m_name;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    bool m_canMoveRight,m_canMoveLeft,m_canMoveUp,m_canMoveDown;
    sf::Vector2f m_wposition;// Position of the mobile in the WORLD
    unsigned int m_health;
    Weapon m_weapon;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const //Allows us to draw mobiles
    {
        // apply the transform
        states.transform *= getTransform();
        
        // apply the tileset texture
        states.texture = &m_texture;
        
        // draw the vertex array
        target.draw(m_sprite, states);
    }


};
#endif /* defined(__Bound_By_Fate__Mobile__) */
