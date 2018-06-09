#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

#include "ECS.hpp"
#include "Components.hpp"

GameObject * player;
GameObject * enemy;
Map *map;

SDL_Renderer * Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout << "Subsystem initialized..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN);
        if(window!=NULL){
            std::cout << "Window created..." << std::endl;
        } else{
            std::cout << "Error! Unable to create window..." << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
         if(renderer != NULL){
            std::cout << "Renderer created..." << std::endl;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        } else{
            std::cout << "Error! Unable to create renderer..." << std::endl;
        }
        
        
        setRunning(true);
    } else {
        setRunning(false);
    }
    
    
    player = new GameObject("assets/Player.png", 0, 0);
    enemy = new GameObject("assets/Enemy.png", 32, 32);
    map = new Map();
    
    newPlayer.addComponent<PositionComponent>();
    //newPlayer.getComponent<PositionComponent>()
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
            case SDL_QUIT:
                setRunning(false);
                break;
                
            default:
                break;
    }
}

void Game::update(){
    
    player->update();
    enemy->update();
    manager.update();
    std::cout<< newPlayer.getComponent<PositionComponent>().x() << "," <<
            newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    //This is where we add stuff to render
    map->drawMap();
    player->render();
    enemy->render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}