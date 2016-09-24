#include "Tek_SpriteSheet.h"

#include <SDL2/SDL.h>


Tek_SpriteSheet::Tek_SpriteSheet(SDL_Texture* texture, int width, int height, int tileWidth, int tileHeight){
    this->_texture = texture;
    this->_width = width;
    this->_height = height;
    this->_tileWidth = tileWidth;
    this->_tileHeight = tileHeight;
}



void Tek_SpriteSheet::destroy(){

}

