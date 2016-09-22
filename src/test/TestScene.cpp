#include "TestScene.h"
#include "Tek_Scene.h"
#include "Tek_Graphics.h"
#include "Tek_Game.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* icon;

TestScene::TestScene(){

}
void Tek_Scene::initScene(){}

void Tek_Scene::loadSceneAssets(Tek_Graphics* graphics){
    icon = graphics->loadTexture("assets/graphics/sprites/Tektonic.png");
    std::cout << "Asset " << icon << " Loaded" << std::endl;
}

void Tek_Scene::updateScene(float deltaTime){

}

void Tek_Scene::renderScene(Tek_Graphics* graphics){
    graphics->drawTexture(icon, 0, 0, _game->getWidth(), _game->getHeight());
    //std::cout << "drawing" << std::endl;
}

void Tek_Scene::destroyScene(){
    SDL_DestroyTexture(icon);
    icon = NULL;
}
