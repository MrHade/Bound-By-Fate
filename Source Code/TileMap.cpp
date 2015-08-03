//
//  TileMap.cpp
//  TileGame
//
//  Created by Soufiane on 18/07/15.
//  Copyright (c) 2015 Soufiane. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace sf;
TileMap::TileMap()
{

}
bool TileMap::loadFromFile(std::string filePath)
{
    std::ifstream flux(filePath.c_str());
    if (flux)//If file was loaded correctly
    {
        std::vector<int> temp;
        bool atemp(true),btemp(true);
        int iTemp;
        for(int i(0);btemp;i++)
        {
            atemp=true;//Puts atemp to true so we can go back in the 2nd loop
            for (int j(0);atemp; j++)
            {
                flux>>iTemp;
                if(iTemp!=0)// In .map files 0 means that a new line started so we keep pushing until we get a 0
                {
                temp.push_back(iTemp-1);//We have to put iTemp -1 because the value 0 is used for new line
                }
                else//If it detect a 0 in the file it push the temp and start a new line
                {
                    atemp=false;

                }
                if(flux.eof())//Stop the loop if we are at the end of the file
                {
                    btemp=false;
                    break;
                }
            }
            vmap.push_back(temp);//Push_back the temp vector into the vmap vector
            temp.clear();//Delete every value in temp so we can fill it again with next row of value

        }
        return true;//Every thing was ok !
    }
    else
    {
        return false;//Erreor while loading the map
        std::cout<<"ERROR: Map was not loaded !"<<std::endl;
    }
}


bool TileMap::load(std::string textureFile,Vector2u tileSize)
{

    if(!m_texture.loadFromFile(textureFile)) //Load the texture
    {
        return false;//Return false if the texture was not loaded correctly
    }
    int width = vmap[0].size();//The width of the map (unite = tile)
    int height = vmap.size();//The height of the map (unite = tile)
    m_VertexArray.setPrimitiveType(Quads);
    m_VertexArray.resize(width*height*4); // Width * Height= area of the map but every tile has 4 corner so *4
    if(width>=height)
    {
    //Fill each Vertex of m_VertexArray with a tile
    for(int i(0);i<width;i++)
    {
        for(int j(0);j<height;j++)
        {
            //Pointer to the currentVertex used in m_VertexArray
            Vertex* currentVertex = &m_VertexArray[(i+j*width)*4];

            //The number/letter of the actual tile
            int tileNumber = vmap[j][i];

            //Set the position of each 4 corner of every tile
            currentVertex[0].position = Vector2f(i*tileSize.x,j*tileSize.y);
            currentVertex[1].position = Vector2f((i+1)*tileSize.x,j*tileSize.y);
            currentVertex[2].position = Vector2f((i+1)*tileSize.x,(j+1)*tileSize.y);
            currentVertex[3].position = Vector2f(i*tileSize.x,(j+1)*tileSize.y);
            // find its position in the tileset texture
            int tu = tileNumber % (m_texture.getSize().x / tileSize.x);
            int tv = tileNumber / (m_texture.getSize().x / tileSize.x);

            // define its 4 texture coordinates
            currentVertex[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            currentVertex[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            currentVertex[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            currentVertex[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

        }//for end
    }//for end
    }//if end
    else
    {
        //Fill each Vertex of m_VertexArray with a tile
        for(int i(0);i<height;i++)
        {
            for(int j(0);j<width;j++)
            {
                //Pointer to the currentVertex used in m_VertexArray
                Vertex* currentVertex = &m_VertexArray[(j+i*width)*4];

                //The number of the actual tile
                int tileNumber = vmap[i][j];

                //Set the position of each 4 corner of every tile
                currentVertex[0].position = Vector2f(j*tileSize.x,i*tileSize.y);
                currentVertex[1].position = Vector2f((j+1)*tileSize.x,i*tileSize.y);
                currentVertex[2].position = Vector2f((j+1)*tileSize.x,(i+1)*tileSize.y);
                currentVertex[3].position = Vector2f(j*tileSize.x,(i+1)*tileSize.y);

                // find its position in the tileset texture
                int tu = tileNumber % (m_texture.getSize().x / tileSize.x);
                int tv = tileNumber / (m_texture.getSize().x / tileSize.x);

                // define its 4 texture coordinates
                currentVertex[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                currentVertex[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                currentVertex[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                currentVertex[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }//for end
        }//for end
    }//else end
    return true; // Every thing was ok !
}
void TileMap::clear()//Usefull to use with a real time map changing
{
    m_VertexArray.clear();
    vmap.clear();

}
std::vector<std::vector<int> > TileMap::getVmap()
{
    return vmap;
}






















