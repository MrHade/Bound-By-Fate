//
//  Weapon.h
//  Bound By Fate
//
//  Created by Soufiane on 09/08/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __Bound_By_Fate__Weapon__
#define __Bound_By_Fate__Weapon__

#include <string>
class Weapon
{
public:
    Weapon(std::string name, unsigned int damage);
    std::string getName();
    unsigned int getDamage();
private:
    std::string m_name;
    unsigned int m_damage;
};
#endif /* defined(__Bound_By_Fate__Weapon__) */
