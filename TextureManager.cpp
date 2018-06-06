/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextureManager.cpp
 * Author: rosenkranz
 * 
 * Created on May 17, 2018, 8:24 PM
 */

#include "TextureManager.hpp"

TextureManager::TextureManager() {
}

TextureManager::TextureManager(const TextureManager& orig) {
}

TextureManager::~TextureManager() {
}

SDL_Texture * TextureManager::LoadTexture(const char* texture){
    
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return tex;
}

void TextureManager::draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest){

    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

