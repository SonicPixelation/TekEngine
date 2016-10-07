#ifndef TEK_GRAPHICS_H
#define TEK_GRAPHICS_H

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
//
class Tek_SpriteSheet;
class Tek_Sprite;

class Tek_Graphics
{
    public:
        Tek_Graphics();
        /* bool createScreen
        *  @param int Width
        *  @param int Height
        *  @param const char* Title
        *  creates the SDL_Window and SDL_Renderer
        */
        bool createScreen(int Width, int Height, const char* Title);

        /* void clear
        *  clears the renderer so that the next frame can be drawn
        *  without causing a bleeding effect
        */
        void clearScreen();

        /* void draw
        *  @param SDL_Texture* texture
        *  @param int srcX
        *  @param int srcY
        *  @param int srcWidth
        *  @param int srcHeight
        *  @param int x
        *  @param int y
        *  @param int width
        *  @param int height
        *  draws the SDL texture with the bound of srcX, srcY, srcWidth, srcHeight
        *  to the location of x, y, width, height in the window
        */
        void drawTexture(SDL_Texture* texture, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y, int width, int height);

        /* void drawSprite
        *  @param Tek_Sprite* sprite
        *  @param int x
        *  @param int y
        *  draws the give sprite that the location x, y on the screen
        */
        void drawSprite(Tek_Sprite* sprite, int x, int y);

        /* void drawSprite
        *  @param Tek_Sprite* sprite
        *  @param int x
        *  @param int y
        *  @param int width
        *  @param int height
        *  draws the sprite at location x, y with the given size in pixels
        *  of width, height
        */
        void drawSprite(Tek_Sprite* sprite, int x, int y, int width, int height);

        /* void flip
        *  flips the renderer buffer so that the next frame can be drawn
        */
        void flipScreen();
        //------------------------------------------------------------------------------------------------------------------
        //asset loading

        /* SDL_Texture
        *  @param const char* filename
        *  Loads the file in the given path and converts it to a SDL_Texture
        */
        SDL_Texture* loadTexture(const char* filename);

        /* Tek_SpriteSheet* loadSpriteSheet
        *  @param const char* filename
        *  Loads the gievn file as a spritesheet
        */
        Tek_SpriteSheet* loadSpriteSheet(const char* filename);

        /* Tek_Sprite* loadSprite
        *  @param const char* filename
        *  Loads the given file as a sprite
        */
        Tek_Sprite* loadSprite(const char* filename);

        /* void destroy
        *  Cleans up memory at the end of the game
        */
        void destroy();

        //getters
        SDL_Window* getWindow(){return _window;}
        SDL_Renderer* getRenderer(){return _renderer;}

    private:
        SDL_Window* _window;     //
        SDL_Renderer* _renderer; //
};

#endif // TEK_GRAPHICS_H
