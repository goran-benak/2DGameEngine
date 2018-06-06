/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObject.cpp
 * Author: rosenkranz
 * 
 * Created on May 17, 2018, 9:00 PM
 */

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, int x, int y) {

    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
    
}

GameObject::GameObject(const GameObject& orig) {
}

GameObject::~GameObject() {
}

void GameObject::update(){
    xpos++;
    ypos++;
    
    srcRect.h = 32;
    srcRect.w = 32;
    
    srcRect.x=0;
    srcRect.y=0;
   
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
    
    
}

void GameObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}