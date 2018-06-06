#include "Game.hpp"

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

class GameObject {
public:
    GameObject(const char * texturesheet, int x, int y);
    GameObject(const GameObject& orig);
    virtual ~GameObject();
    
    void update();
    void render();
    
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    
};

#endif /* GAMEOBJECT_HPP */

