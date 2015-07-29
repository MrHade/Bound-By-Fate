//
//  Mobile.cpp
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Mobile.h"
Mobile::Mobile(std::string m_name)
{
    //Setting the Mobile display
    m_texture.loadFromFile("/Users/mrhade/Documents/C++/Rpg/Game Ressources/italy_wing_walking_by_silvermistanimelover-d8y9dmy.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,48,48));// Mobile is 24x31
    m_sprite.setScale(0.64,0.64);//Now the Mobile has the same size as the tiles 32x32
    m_sprite.setPosition(32*5, 32*3);
    //Setting variables for collision manager
    m_canMoveRight=true;
    m_canMoveLeft=true;
    m_canMoveUp=true;
    m_canMoveDown=true;
}
Mobile::Mobile(): m_name("Moss")
{
    //Setting the Mobile display
    m_texture.loadFromFile("/Users/mrhade/Documents/C++/Rpg/Game Ressources/italy_wing_walking_by_silvermistanimelover-d8y9dmy.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,48,48));// Mobile is 24x31
    m_sprite.setScale(0.64,0.64);//Now the Mobile has the same size as the tiles 32x32
    m_sprite.setPosition(32*5, 32*3);
    //Setting variables for collision manager
    m_canMoveRight=true;
    m_canMoveLeft=true;
    m_canMoveUp=true;
    m_canMoveDown=true;
}

sf::Sprite& Mobile::getSprite()
{
    return m_sprite;
}
void Mobile::moveRight()
{
    
    //  m_sprite.setTextureRect(sf::IntRect(100,0,-100,100));//Flips the Mobile
    if(m_canMoveRight)
    {
        m_sprite.move(32,0);
    }
}
void Mobile::moveLeft()
{
    // m_sprite.setTextureRect(sf::IntRect(0,0,100,100));//Puts the correct TextureRect from the char file
    
    if(m_canMoveLeft)
    {
        m_sprite.move(-32, 0);
    }
}
void Mobile::moveUp()
{
    //  m_sprite.setTextureRect(sf::IntRect(0,100,100,100));//Mobile looks up
    if(m_canMoveUp)
    {
        m_sprite.move(0, -32);
    }
}
void Mobile::moveDown()
{
    //  m_sprite.setTextureRect(sf::IntRect(0,200,100,100));//Mobile looks down
    
    if(m_canMoveDown)
    {
        m_sprite.move(0, 32);
    }
}
//********************************
void Mobile::canMove()
{
    m_canMoveRight=true;
    m_canMoveLeft=true;
    m_canMoveUp=true;
    m_canMoveDown=true;
}

//********************************
void Mobile::collisionWithTileManager(TileMap map)
{
    std::vector<std::vector<int> > vmap = map.getVmap();
    
    //If you want to add tiles that provoke collision, put " || numberOfYourTile " after the 54
    //54=Trees
    //Don't use else if because the char could be in the middle of 4 tiles so we have to check every collision
    
    //Collision with tiles on the right of Mobile
    if(vmap[(m_sprite.getPosition().y)/32][((m_sprite.getPosition().x)+32)/32]==54 /*add tiles here*/)
    {
        m_canMoveRight=false;
    }
    //Collision with tiles on the left of Mobile
    if (vmap[(m_sprite.getPosition().y)/32][((m_sprite.getPosition().x)-32)/32]==54 /*add tiles here*/)
    {
        m_canMoveLeft=false;
    }
    //Collision with tiles above the Mobile
    if(vmap[((m_sprite.getPosition().y)-32)/32][(m_sprite.getPosition().x)/32]==54 /*add tiles here*/)
    {
        m_canMoveUp=false;
    }
    //Collision with tiles under the Mobile
    if (vmap[((m_sprite.getPosition().y)+32)/32][(m_sprite.getPosition().x)/32]==54 /*add tiles here*/)
    {
        m_canMoveDown=false;
    }
    //If the Mobile is on a tile where he's not suppose to be, we block him
    if (vmap[(m_sprite.getPosition().y)/32][(m_sprite.getPosition().x)/32]==54 /*add tiles here*/)
    {
        m_canMoveRight=false;
        m_canMoveLeft=false;
        m_canMoveUp=false;
        m_canMoveDown=false;
    }
    
}








