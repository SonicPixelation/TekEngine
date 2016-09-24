#include "Tek_InputManager.h"

void Tek_InputManager::clearInput(){
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}


void Tek_InputManager::keyDownEvent(const SDL_Event& event){
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode]    = true;
}

void Tek_InputManager::keyUpEvent(const SDL_Event& event){
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode]     = false;
}




bool Tek_InputManager::wasKeyPressed(SDL_Scancode key){
    return this->_pressedKeys[key];
}

bool Tek_InputManager::wasKeyReleased(SDL_Scancode key){
    return this->_releasedKeys[key];
}

bool Tek_InputManager::isKeyHeld(SDL_Scancode key){
    return this->_heldKeys[key];
}
