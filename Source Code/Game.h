//
//  Game.h
//  Bound By Fate
//
//  Created by Soufiane on 28/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __Bound_By_Fate__Game__
#define __Bound_By_Fate__Game__
#include <vector>
#include "Mob.h"
#include "Character.h"
class Game
{
public:
     void play();

     bool addMob(Mob *newMob);
     bool deleteMob(Mob *mobToDelete);
     void deleteAllMobs();
     void updateMobs(sf::RenderWindow &window, Mobile target, TileMap map);
                // Call IA function of each mob + draw all the mobs
    
     void manageEvents(sf::RenderWindow &window, Character &player, TileMap map);
private:
    std::vector<Mob*> activeMobs;
};
#endif /* defined(__Bound_By_Fate__Game__) */
