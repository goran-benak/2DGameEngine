#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "Game.hpp"



class TextureManager {
public:
    TextureManager();
    TextureManager(const TextureManager& orig);
    virtual ~TextureManager();

    static SDL_Texture * LoadTexture(const char * filename);
    static void draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest);
private:

};

#endif /* TEXTUREMANAGER_HPP */

