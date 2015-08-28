//
//  Character.cpp
//  Rpg
//
//  Created by Soufiane on 23/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Character.h"
#include <iostream>
Character::Character(std::string pathTotexture): Mobile()
{
    setWeapon(Weapon("Wooden Sword",10));
}