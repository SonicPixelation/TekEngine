#include "Tek_Sprite.h"
#include "Tek_Graphics.h"

#include <SDL2/SDL.h>

Tek_Sprite::Tek_Sprite(SDL_Texture* texture, int x, int y, int width, int height){
    this->_texture = texture;
    this->_srcX = x;
    this->_srcY = y;
    this->_srcWidth  = width;
    this->_srcHeight = height;
}

void Tek_Sprite::draw(Tek_Graphics* graphics, int x, int y){
    graphics->drawSprite(this, x, y);
}

void Tek_Sprite::draw(Tek_Graphics* graphics, int x, int y, int width, int height){
    graphics->drawSprite(this, x, y, width, height);
}


void Tek_Sprite::destroy(){
    SDL_DestroyTexture(_texture);
    _texture = NULL;
}

