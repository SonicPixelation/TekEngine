#include "TestScene.h"
#include "Tek_Scene.h"
#include "Tek_Graphics.h"
#include "Tek_Game.h"
#include "Tek_InputManager.h"

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* icon;
int x, y;

TestScene::TestScene(){

}
void Tek_Scene::initScene(){}

void Tek_Scene::loadSceneAssets(Tek_Graphics* graphics){
    icon = graphics->loadTexture("assets/graphics/sprites/Tektonic.png");
}

void Tek_Scene::updateScene(float deltaTime){
    if(_input->wasKeyPressed(SDL_SCANCODE_ESCAPE)){
        _game->stop();
    }
    if(_input->isKeyHeld(SDL_SCANCODE_A)){
        x -= 1 * (deltaTime);
    }
    if(_input->isKeyHeld(SDL_SCANCODE_D)){
        x += 1 * (deltaTime);
    }
}

void Tek_Scene::renderScene(Tek_Graphics* graphics){
    graphics->drawTexture(icon, x, y, _game->getWidth(), _game->getHeight());
}

void Tek_Scene::destroyScene(){
    SDL_DestroyTexture(icon);
    icon = NULL;
}
