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
    Mob(int xPosition,int yPosition, std::string pathToTexture);
    
    void detectMobile(Mobile);//Detects a mobile in his detectionZone
    void trackMobile(Mobile target);//Walks to the target
    sf::RectangleShape detectionZoneDebug;//used for debugging detection
private:
};
#endif /* defined(__Bound_By_Fate__Mob__) */
