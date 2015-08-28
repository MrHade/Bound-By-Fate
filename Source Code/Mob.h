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
    
    void IA(sf::RenderWindow &window,Mobile target, TileMap map);//Makes the mob moving, attacking, tracking...
    void trackMobile(Mobile target);//Walks to the target
    void attack(Mobile target);
    void goTo(sf::RenderWindow &window,sf::Vector2i destination);//The mob will walk to it's initial position
    void walk();//Will make the mob walk near his initialPosition
    
    //initialPositionDebugSquare
    sf::RectangleShape debugInitalPoint;

private:
    const sf::Vector2i m_initialPosition;//Spwan position of the mob
    const unsigned int m_detectionZoneWidth;
    const unsigned int m_detectionZoneHeight;
    unsigned int m_steps;//Number of steps that the mob made
    unsigned int m_maxSteps;//The maximum number of steps from the inital position, that a mob should do
    //Movement States
    bool m_isWalking;
    bool m_isTracking;
    bool m_isGoingToDestionation;//Is the mob moving to a position on the map?

    sf::RenderWindow m_window;//The winndow where the mob is displayed
};
#endif /* defined(__Bound_By_Fate__Mob__) */
