#include "Tek_Game.h"
#include "Tek_Screen.h"
//
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
extern "C"{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

Tek_Game::Tek_Game(){
    this->_width  = 640;
    this->_height = 480;
    this->_title  = "TekEngine Game";
    this->_running = false;
    _screen = new Tek_Screen();
}


void Tek_Game::start(){
    this->_running = true;
    run();
}

void Tek_Game::stop(){
    this->_running = false;
}

bool Tek_Game::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Failed to init SDL! SDL_Error : %s", SDL_GetError());
        return false;
    }
    if(!getScreen()->createScreen(getWidth(), getHeight(), getTitle())){
        return false;
    }

    return true;
}


void Tek_Game::run(){
    if(!init()){stop();}
    SDL_Event event;
    while(isRunning()){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                stop();
            }
        }
        getScreen()->clearScreen();
        update(1);
        render(getScreen());
        getScreen()->flipScreenBuffer();
    }
    destroy();
    //SDL_Quit();

}

void Tek_Game::update(float deltaTime){}

void Tek_Game::render(Tek_Screen* screen){}

void Tek_Game::destroy(){
    printf("Gnight\n");
    getScreen()->destroy();
    delete _screen;
}


int main(int argc, char* args[]){
    Tek_Game game;
    game.start();
    return 0;
}
