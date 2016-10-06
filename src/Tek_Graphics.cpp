#include "Tek_Graphics.h"
#include "Tek_SpriteSheet.h"
#include "Tek_Sprite.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
Tek_Graphics::Tek_Graphics(){}



bool Tek_Graphics::createScreen(int Width, int Height, const char* Title){
    SDL_CreateWindowAndRenderer(Width, Height, 0, &this->_window, &this->_renderer);
    if(_window == NULL){
        std::cout << "Failed to create SDL_Window! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if(_renderer == NULL){
        std::cout << "Failed to create SDL_Renderer! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetWindowTitle(_window, Title);
    return true;
}

void Tek_Graphics::clearScreen(){
    SDL_RenderClear(_renderer);
}

void Tek_Graphics::drawTexture(SDL_Texture* texture, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y, int width, int height){
    SDL_Rect srcRect = {srcX, srcY, srcWidth, srcHeight};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopy(_renderer, texture, &srcRect, &dstRect);
}

void Tek_Graphics::drawSprite(Tek_Sprite* sprite, int x, int y){
    drawTexture(sprite->getTexture(), sprite->getX(), sprite->getY(), sprite->getWidth(), sprite->getHeight(), x, y, sprite->getWidth(), sprite->getHeight());
}

void Tek_Graphics::drawSprite(Tek_Sprite* sprite, int x, int y, int width, int height){
     drawTexture(sprite->getTexture(), sprite->getX(), sprite->getY(), sprite->getWidth(), sprite->getHeight(), x, y, width, height);
}

void Tek_Graphics::flipScreen(){
    SDL_RenderPresent(this->_renderer);
}
//asset managment
SDL_Texture* Tek_Graphics::loadTexture(const char* filename){
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
    return texture;
}

Tek_SpriteSheet* Tek_Graphics::loadSpriteSheet(const char* filename){
    SDL_Texture* texture = loadTexture(filename);
    Tek_SpriteSheet* sheet = new Tek_SpriteSheet(texture);
    return sheet;
}

Tek_Sprite* Tek_Graphics::loadSprite(const char* filename){
    SDL_Surface* surface = IMG_Load(filename);
    int width  = surface->w;
    int height = surface->h;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    Tek_Sprite* sprite = new Tek_Sprite(texture, 0, 0, width, height);
    return sprite;
}

void Tek_Graphics::destroy(){
    SDL_DestroyRenderer(_renderer);
    _renderer = NULL;
    SDL_DestroyWindow(_window);
    _window = NULL;
}
