#ifndef TEK_SPRITESHEET_H
#define TEK_SPRITESHEET_H

class SDL_Texture;
//
class Tek_Sprite;

class Tek_SpriteSheet
{
    public:
        /* Tek_SpriteSheet
        *  @param SDL_Texture* texture
        */
        Tek_SpriteSheet(SDL_Texture* texture);
        /* Tek_Sprite* getSprite
        *  @param int x
        *  @param int y
        *  @param int width
        *  @param int height
        *  returns a drawablerectangle specified by x, y, width, height
        */
        Tek_Sprite* getSprite(int x, int y, int width, int height);
        /* void destroy
        *  disposes of the texture
        */
        void destroy();

        //getters
        SDL_Texture* getTexture(){return this->_texture;}
    private:
        SDL_Texture* _texture;
};

#endif // TEK_SPRITESHEET_H
