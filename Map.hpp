#ifndef MAP_HPP
#define MAP_HPP

#include "Game.hpp"

class Map {
public:
    Map();
    Map(const Map& orig);
    virtual ~Map();
    
    void loadMap(int arr[20][25]);
    void drawMap();
private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
};

#endif /* MAP_HPP */

