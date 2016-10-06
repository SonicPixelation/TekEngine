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
    *  @param const SDL_Event& event
    *  this event should be called when
    *  a key is pressed down
    */
    void keyDownEvent(const SDL_Event& event);
    /* void keyUpEvent
    *  @param const SDL_Event& event
    *  this event should be called when the key
    *  is released
    */
    void keyUpEvent(const SDL_Event& event);

    /* bool wasKeyPressed
    *  @paam SDL_Scancode key
    *  returns true when a key is pressed
    */
    bool wasKeyPressed(SDL_Scancode key);
    /* bool wasKeyReleased
    *  @param SDL_Scancode key
    */
    bool wasKeyReleased(SDL_Scancode key);
    /* bool isKeyHeld
    *  @param SDL_Scancode key
    */
    bool isKeyHeld(SDL_Scancode key);

    private:
        std::map<SDL_Scancode, bool> _pressedKeys;
        std::map<SDL_Scancode, bool> _releasedKeys;
        std::map<SDL_Scancode, bool> _heldKeys;
};

#endif // TEK_INPUTMANAGER_H
