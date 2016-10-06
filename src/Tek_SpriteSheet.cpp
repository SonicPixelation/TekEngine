#include "Tek_SpriteSheet.h"
#include "Tek_Sprite.h"
#include "Tek_Graphics.h"

#include <SDL2/SDL.h>

Tek_SpriteSheet::Tek_SpriteSheet(SDL_Texture* texture){
    this->_texture = texture;
}

Tek_Sprite* Tek_SpriteSheet::getSprite(int x, int y, int width, int height){
    Tek_Sprite* sprite = new Tek_Sprite(_texture, x, y, width, height);
    return sprite;
}


void Tek_SpriteSheet::destroy(){
    SDL_DestroyTexture(this->_texture);
    this->_texture = NULL;
}


