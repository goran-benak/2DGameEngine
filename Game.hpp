#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h" 
#include "SDL2/SDL_image.h"
#include <iostream>

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    static SDL_Renderer * renderer;
    
    bool isRunning(){return game_running_status;} //this becomes inline
    void setRunning(bool running){game_running_status = running;} //this becomes inline
private:
    int cnt = 0;
    bool            game_running_status;
    SDL_Window      *window;
};

#endif /* GAME_HPP */

