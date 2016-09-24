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

    this->_Width  = 640;
    this->_Height = 480;
    this->_Title  = "TekEngine";
    _currentScene = NULL;
    this->_graphics = new Tek_Graphics();
    this->_input    = new Tek_InputManager();
}

void Tek_Game::start(){
    this->_running = true;
    run();
}

void Tek_Game::stop(){
    this->_running = false;
}

void Tek_Game::setScene(Tek_Scene* scene){
    if(scene != NULL) scene->destroy();
    _currentScene = scene;
    if(_running){
        _currentScene->init(this);
        _currentScene->loadAssets(_graphics);
    }
}
//
bool Tek_Game::init(){
    bool success = _graphics->createWindow(_Width, _Height, _Title);
    return success;
}

void Tek_Game::run(){
    if(!init()){stop();}
    SDL_Event event;
    if(_currentScene != NULL){
        _currentScene->init(this);
        _currentScene->loadAssets(_graphics);
    }
    int lastTime = SDL_GetTicks();
    while(_running){
        _input->clearInput();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                if(event.type == SDL_KEYDOWN){
                    _input->keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP){
                _input->keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT){
                stop();
            }
        }

        int nowTime = SDL_GetTicks();
        SDL_UpdateWindowSurface(_graphics->getWindow());
        int deltaTime = nowTime - lastTime;
        update(deltaTime);
        render(this->_graphics);
        lastTime = nowTime;
    }
    destroy();
    SDL_Quit();
}

void Tek_Game::update(float deltaTime){
    if(_currentScene != NULL){
        _currentScene->update(deltaTime);
    }
}

void Tek_Game::render(Tek_Graphics* graphics){
    _graphics->clearScreen();
    if(_currentScene != NULL){
        _currentScene->render(graphics);
    }
    _graphics->flipScreen();
}

void Tek_Game::destroy(){
    if(_currentScene != NULL){
        _currentScene->destroy();
    }
    _graphics->destroyWindow();
    delete _graphics;
}

//setters
void Tek_Game::setWindowSize(int width, int height){
    _Width  = width;
    _Height = height;
    if(_running){
        _graphics->updateWindow(_Width, _Height);
    }
}
void Tek_Game::setWindowTitle(const char* title){
    _Title = title;
    if(_running){
        _graphics->updateWindow(_Title);
   }
}
