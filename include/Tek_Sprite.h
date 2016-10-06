#ifndef TEK_SPRITE_H
#define TEK_SPRITE_H

class SDL_Texture;
//
class Tek_Graphics;

class Tek_Sprite
{
    public:
        /* Tek_Sprite
        *  @param SDL_Texture* texture
        *  @param int x
        *  @param int y
        *  @param int width
        *  @param int height
        *  the constructor for the Tek_Sprite class
        *  builds the sprite so it is easier to draw
        */
        Tek_Sprite(SDL_Texture* texture, int x, int y, int width, int height);


        /* void draw
        *  @param Tek_Graphics* graphics
        *  @param int x
        *  @param int y
        *  draws this sprite at the given loction of x, y
        */
        void draw(Tek_Graphics* graphics, int x, int y);

        /* void draw
        *  @param Tek_Graphics* graphics
        *  @param int x
        *  @param int y
        *  @param int width
        *  @param int height
        *  draws the sprite at the given location of x, y
        *  and draws it to the size of width, height
        */
        void draw(Tek_Graphics* graphics, int x, int y, int width, int height);

        /* void destroy
        */
        void destroy();

        //getters------------------------------------------------------------
        int getX(){return _srcX;}
        int getY(){return _srcY;}
        int getWidth(){return _srcWidth;}
        int getHeight(){return _srcHeight;}

        SDL_Texture* getTexture(){return _texture;}

    private:
        SDL_Texture* _texture;
        int _srcX;
        int _srcY;
        int _srcWidth;
        int _srcHeight;
};

#endif // TEK_SPRITE_H
