#ifndef TEK_SPRITESHEET_H
#define TEK_SPRITESHEET_H

class SDL_Texture;

class Tek_SpriteSheet
{
    public:
        Tek_SpriteSheet(SDL_Texture* texture, int width, int height, int tileWidth, int tileHeight);


        void destroy();
    private:
        SDL_Texture* _texture; //
        int _width;            //
        int _height;           //
        //
        int _tileWidth;        //
        int _tileHeight;       //
};

#endif // TEK_SPRITESHEET_H
