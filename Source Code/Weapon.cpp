//
//  Weapon.cpp
//  Bound By Fate
//
//  Created by Soufiane on 09/08/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#include "Weapon.h"

Weapon::Weapon(std::string name, unsigned int damage): m_name(name), m_damage(damage)
{

}
std::string Weapon::getName()
{
    return m_name;
}
unsigned int Weapon::getDamage()
{
    return m_damage;
}