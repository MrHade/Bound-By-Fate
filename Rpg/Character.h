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
class Character
{
public:
    Character(std::string m_name);
    sf::Sprite getSprite();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    
private:
    std::string m_name;
    sf::Sprite m_sprite;
    sf::Texture m_texture;    
};
#endif /* defined(__Rpg__Character__) */
