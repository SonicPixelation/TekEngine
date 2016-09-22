#include "Tek_Scene.h"
#include "Tek_Graphics.h"
#include "Tek_Game.h"

void Tek_Scene::init(Tek_Game* game){
    this->_game = game;
    this->initScene();
}

void Tek_Scene::loadAssets(Tek_Graphics* graphics){
    this->loadSceneAssets(graphics);
}

void Tek_Scene::update(float deltaTime){
    this->updateScene(deltaTime);
}
void Tek_Scene::render(Tek_Graphics* graphics){
    this->renderScene(graphics);
}

void Tek_Scene::destroy(){
    this->destroyScene();
}


void Tek_Scene::setScene(Tek_Scene* scene){
    _game->setScene(scene);
}
