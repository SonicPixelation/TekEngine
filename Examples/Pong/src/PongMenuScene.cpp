#include "PongMenuScene.h"

#include <Tek_Graphics.h>
#include <Tek_InputManager.h>
#include <Tek_Game.h>


PongMenuScene::PongMenuScene(){}

void Tek_Scene::initScene(){}

void Tek_Scene::initSceneAssets(Tek_Graphics* graphics){}

void Tek_Scene::updateScene(int deltaTime){
    if(input->wasKeyPressed(SDL_SCANCODE_ESCAPE)){getGame()->stop();}
}

void Tek_Scene::renderScene(Tek_Graphics* graphics){}

void Tek_Scene::destroyScene(){}
