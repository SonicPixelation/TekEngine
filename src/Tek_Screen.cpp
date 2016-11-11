#include "Tek_Screen.h"

//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//
#include <cstdio>

Tek_Screen::Tek_Screen(){}



bool Tek_Screen::createScreen(int width, int height, const char* title){
    SDL_CreateWindowAndRenderer(width, height, 0, &this->_window, &this->_renderer);
    if(this->_window == NULL){
        printf("SDL Window error! SDL_Error: %s", SDL_GetError());
        return  false;
    }
    if(this->_renderer == NULL){
        printf("SDL Window error! SDL_Error: %s", SDL_GetError());
        return false;
    }

    SDL_SetWindowTitle(this->_window, title);
    return true;
}


void Tek_Screen::clearScreen(){
    SDL_RenderClear(getSDLRenderer());
}


void Tek_Screen::flipScreenBuffer(){
    SDL_RenderPresent(getSDLRenderer());
}

void Tek_Screen::drawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect){
    SDL_RenderCopy(getSDLRenderer(), texture, srcRect, dstRect);
}

SDL_Texture* Tek_Screen::loadTexture(const char* filepath){
    SDL_Surface* surface = IMG_Load(filepath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getSDLRenderer(), surface);
    return texture;
}


void Tek_Screen::updateSize(int width, int height){
    SDL_SetWindowSize(getSDLWindow(), width, height);
    SDL_SetWindowPosition(getSDLWindow(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void Tek_Screen::updateTitle(const char* title){
    SDL_SetWindowTitle(getSDLWindow(), title);
}

void Tek_Screen::destroy(){
    SDL_DestroyWindow(_window);
    _window = NULL;
    SDL_DestroyRenderer(_renderer);
    _renderer = NULL;
}
