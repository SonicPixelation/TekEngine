#include "Tek_Graphics.h"
#include "Tek_SpriteSheet.h"


#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Tek_Graphics::Tek_Graphics(){}



bool Tek_Graphics::createWindow(int width, int height, const char* title){
    SDL_CreateWindowAndRenderer(width, height, 0, &this->_window, &this->_renderer);
    if(_window == NULL){
        std::cout << "Failed to create SDL Window! SDL_ERROR: " << SDL_GetError() << std::endl;
        return false;
    }
    if(_renderer == NULL){
        std::cout << "Failed to create SDL Renderer! SDL_ERROR: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetWindowTitle(_window, title);
    return true;
}

void Tek_Graphics::destroyWindow(){
    SDL_DestroyWindow(_window);
    this->_window = NULL;
    SDL_DestroyRenderer(_renderer);
    this->_renderer = NULL;
}

void Tek_Graphics::updateWindow(const char* title){
    SDL_SetWindowTitle(_window, title);
}

void Tek_Graphics::updateWindow(int width, int height){
    SDL_SetWindowSize(_window, width, height);
    SDL_SetWindowPosition(_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void Tek_Graphics::updateWindow(int width, int height, const char* title){
    SDL_SetWindowSize(_window, width, height);
    SDL_SetWindowPosition(_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_SetWindowTitle(_window, title);
}

//graphics rendering applications--------------------------------------------------
void Tek_Graphics::drawTexture(SDL_Texture* texture, int x, int y, int w, int h){
    int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, w, h};
    SDL_RenderCopy(_renderer, texture, &srcRect, &dstRect);
}

void Tek_Graphics::clearScreen(){
    SDL_RenderClear(_renderer);
}

void Tek_Graphics::flipScreen(){
    SDL_RenderPresent(_renderer);
}

//--------------------------------------------------------------------------------
//graphic asset loading functions
SDL_Texture* Tek_Graphics::loadTexture(const char* filepath){
    SDL_Surface* surface = IMG_Load(filepath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
    return texture;
}

Tek_SpriteSheet* Tek_Graphics::loadSpriteSheet(const char* filepath, int tileWidth, int tileHeight){
    SDL_Surface* surface = IMG_Load(filepath);
    int width = surface->w;
    int height = surface->h;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
    Tek_SpriteSheet* sheet = new Tek_SpriteSheet(texture, width, height, tileWidth, tileHeight);
    return sheet;
}
