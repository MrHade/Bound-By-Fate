//
//  Mob.cpp
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Mob.h"
using namespace sf;
Mob::Mob(): Mobile()
{
    m_texture.loadFromFile("/Users/mrhade/Documents/C++/Rpg/Game Ressources/wolfsheet6_0.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(IntRect(0,0,32,64));
    m_sprite.setScale(0.75,0.5);
    m_sprite.setPosition(320, 160);
}
