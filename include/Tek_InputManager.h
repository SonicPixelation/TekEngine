#ifndef TEK_INPUTMANAGER_H
#define TEK_INPUTMANAGER_H

#include <SDL2/SDL.h>
#include <map>

class Tek_InputManager
{
    public:

        /* void clearInput
        */
        void clearInput();
        /* void keyDownEvent
        *  @param1 const SDL_Event& event
        */
        void keyDownEvent(const SDL_Event& event);
        /* void keyUpEvent
        *  @param1 const SDL_Event& event
        */
        void keyUpEvent(const SDL_Event& event);
        //
        /* bool wasKeyPressed
        *  @param1 SDL_Scancode key
        */
        bool wasKeyPressed(SDL_Scancode key);
        /* bool wasKeyReleased
        *  @param1 SDL_Scancode key
        */
        bool wasKeyReleased(SDL_Scancode key);
        /* bool isKeyHeld
        *  @param1 SDL_Scancode key
        */
        bool isKeyHeld(SDL_Scancode key);
    private:
        std::map<SDL_Scancode, bool> _pressedKeys;
        std::map<SDL_Scancode, bool> _releasedKeys;
        std::map<SDL_Scancode, bool> _heldKeys;
};

#endif // TEK_INPUTMANAGER_H
