//
//  TileMap.h
//  TileGame
//
//  Created by Soufiane on 18/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//

#ifndef __TileGame__TileMap__
#define __TileGame__TileMap__

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap();
    //Load the TileMap from a .map file and put it in a multidimentional char vector
    bool loadFromFile(std::string filePath);
    //Convert the char values from the multidimentional vector to tiles and texture them
    bool load(std::string textureFile,sf::Vector2u tileSize);//tileSize is the size of the tiles in the tileset
    void clear();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();
        
        // apply the tileset texture
        states.texture = &m_texture;
        
        // draw the vertex array
        target.draw(m_VertexArray, states);
    }
    
    sf::VertexArray m_VertexArray;//Contains the tiles of the map
    sf::Texture m_texture;//The texture of the tiles of the map
    std::vector<std::vector<int> > vmap;// Contains the map from .map file
    
};
#endif /* defined(__TileGame__TileMap__) */
