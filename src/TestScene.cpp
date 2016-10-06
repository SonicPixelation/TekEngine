#include "TestScene.h"
#include "Tek_Graphics.h"
#include "Tek_Sprite.h"
#include "Tek_Game.h"
#include "Tek_InputManager.h"

Tek_Sprite* sprite;

float x, y;
float xVel, yVel;
;
TestScene::TestScene(){}

void Tek_Scene::initSceneAssets(Tek_Graphics* graphics){
    sprite = graphics->loadSprite("assets/graphics/sprites/Tektonic.png");
}

void Tek_Scene::initScene(){
}

void Tek_Scene::updateScene(int deltaTime){
    if(input->wasKeyPressed(SDL_SCANCODE_ESCAPE)){getGame()->stop();}

    if(input->isKeyHeld(SDL_SCANCODE_W)){yVel = -0.1;}
    if(input->isKeyHeld(SDL_SCANCODE_A)){xVel = -0.1;}
    if(input->isKeyHeld(SDL_SCANCODE_S)){yVel =  0.1;}
    if(input->isKeyHeld(SDL_SCANCODE_D)){xVel =  0.1;}

    if(xVel > 0 || xVel < 0){
        x += xVel * deltaTime;
    }
    if(yVel > 0 || yVel < 0){
        y += yVel * deltaTime;
    }
    xVel = 0;
    yVel = 0;
}

void Tek_Scene::renderScene(Tek_Graphics* graphics){
    graphics->drawSprite(sprite, int(x), int(y));
}

void Tek_Scene::destroyScene(){
    sprite->destroy();
}
