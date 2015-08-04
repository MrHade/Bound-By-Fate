//
//  Mob.h
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __Bound_By_Fate__Mob__
#define __Bound_By_Fate__Mob__
#include <SFML/Graphics.hpp>
#include <string>
#include "Mobile.h"
//"A mob is a computer-controlled non-player character (NPC) in a computer game." Wikipedia
class Mob : public  Mobile
{
public:
    Mob(sf::Vector2f initialPosition,std::string pathTotexture);
    
    void detectMobile(Mobile target, TileMap map);//Detects a mobile in his detectionZone
    void trackMobile(Mobile target);//Walks to the target
    void attack(Mobile target);
    void goTo(TileMap map,sf::Vector2f destination);//The mob will walk to it's initial position
    sf::RectangleShape detectionZoneDebug;//used for debugging detection

private:
    const sf::Vector2f m_initialPosition;//Spwan position of the mob
    const unsigned int m_detectionZoneWidth;
    const unsigned int m_detectionZoneHeight;
    //States
    bool m_isWalking;
    bool m_isTracking;
    
};
#endif /* defined(__Bound_By_Fate__Mob__) */
