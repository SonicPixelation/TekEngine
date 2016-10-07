#include "Tek_Game.h"
#include "Tek_Graphics.h"
#include "Tek_Scene.h"
#include "Tek_InputManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Tek_Game::Tek_Game(const char* appId, const char* appVersion){
    this->_appId = appId;
    this->_appVersion = appVersion;
    this->_Width = 640;
    this->_Height = 480;
    this->_Title = "Tek Game";
    this->_Fullscreen = false;
    this->_currentScene = NULL;

    this->_graphics = new Tek_Graphics();
    this->_input    = new Tek_InputManager();
}


void Tek_Game::start(){
    _running = true;
    run();
}

void Tek_Game::stop(){
    _running = false;
}


//
bool Tek_Game::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Failed to init SDL! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if(!getGraphics()->createScreen(this->_Width, this->_Height, this->_Title)){
        return false;
    }
    setFullscreen(_Fullscreen);
    return true;
}
//
void Tek_Game::run(){
    if(!init()){stop();}
    if(_currentScene != NULL){
        _currentScene->init(this);
        _currentScene->initAssets(_graphics);
    }
    SDL_Event event;
    int lastTime = SDL_GetTicks();
    while(_running){
        int startTime = SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                _input->keyDownEvent(event);
            }
            else if(event.type == SDL_KEYUP){
                _input->keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT){
                stop();
            }
        }
        _graphics->clearScreen();
        int deltaTime = startTime - lastTime;
        update(deltaTime);
        render(this->getGraphics());
        lastTime = startTime;
        _graphics->flipScreen();
    }
    destroy();
    SDL_Quit();
}

void Tek_Game::update(int deltaTime){
    if(_currentScene != NULL){
        _currentScene->update(deltaTime);
    }
}

void Tek_Game::render(Tek_Graphics* graphics){
    if(_currentScene != NULL){
        _currentScene->render(graphics);
    }
}


void Tek_Game::destroy(){
    if(_currentScene != NULL){
        _currentScene->destroy();
    }
    _graphics->destroy();
    delete _graphics;
}

//setters
void Tek_Game::setScene(Tek_Scene* newScene){
    if(_currentScene != NULL){_currentScene->destroy();}
    _currentScene = newScene;
    if(_running){
        _currentScene->init(this);
        _currentScene->initAssets(_graphics);
    }
}

void Tek_Game::setScreenSize(int width, int height){
    this->_Width = width;
    this->_Height = height;
    if(_running){
        SDL_SetWindowSize(getGraphics()->getWindow(), _Width, _Height);
        SDL_SetWindowPosition(getGraphics()->getWindow(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
}

void Tek_Game::setFullscreen(bool fullscreen){
    this->_Fullscreen = fullscreen;
    if(_running){
        if(_Fullscreen){
            SDL_SetWindowFullscreen(getGraphics()->getWindow(), SDL_WINDOW_FULLSCREEN);
            SDL_SetWindowPosition(getGraphics()->getWindow(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        }else{
            SDL_SetWindowFullscreen(getGraphics()->getWindow(), 0);
        }
    }
}

void Tek_Game::setTitle(const char* title){
    this->_Title = title;
    if(_running){
        SDL_SetWindowTitle(_graphics->getWindow(), _Title);
    }
}
