
#include "Game.hpp"

using namespace std;
Game *game = nullptr;
/*
 * 
 */
int main(int argc,char* argv[]) {
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS; //Max time between frames
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    if (game ==nullptr){
        std::cout << "Error crating game!" <<std::endl;
        return 0;
    }
    game->init("RosEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while(game->isRunning()){
    /*handle any user input*/
    /*update all objects, positions etc...*/
    /*render changes to the display*/
        
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        
    }
    game->clean();
    return 0;
}

