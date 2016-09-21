#include "Tek_Graphics.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Tek_Graphics::Tek_Graphics(){}



bool Tek_Graphics::createWindow(int width, int height, const char* title){
    SDL_CreateWindowAndRenderer(width, height, 0, &this->_window, &this->_renderer);
    if(_window == NULL){
        return false;
    }
    if(_renderer == NULL){
        return false;
    }

    SDL_SetWindowTitle(_window, title);
}


SDL_Texture* Tek_Graphics::loadTexture(const char* filepath){
    SDL_Surface* surface = IMG_Load(filepath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    return texture;
}
