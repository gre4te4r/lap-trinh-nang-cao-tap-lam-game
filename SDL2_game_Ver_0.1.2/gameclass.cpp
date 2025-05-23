#include<SDL_image.h>
#include<SDL.h>

#include "gameclass.h"
#include"InputHandler.h"


Game::Game()
{
    myWindow = nullptr;
    myRenderer = nullptr;
    m_bRunning = false;
    m_currentFrame = 0;

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags){

 if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

    myWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(myWindow != 0){

        myRenderer = SDL_CreateRenderer(myWindow, -1, 0);

        if(myRenderer != 0){

            SDL_SetRenderDrawColor(myRenderer, 0,255,255,255);
            }
        else{
            return false;
            }
        }
    else{
        return false;
        }
 }
 else{
    return false;
    }

    IMG_Init(IMG_INIT_PNG||IMG_INIT_JPG);

    if(!TextureManager::Instance()->load("Walk.png", "walk", myRenderer)){
        return false;
    }
    if(!TextureManager::Instance()->load("Attack.png", "attack", myRenderer)){
        return false;
    }
    if(!TextureManager::Instance()->load("Idle.png", "idle", myRenderer)){
        return false;
    }

    playerWalk = new Player();
    playerWalk->load(300, 300, 128, 128, "walk");
    m_gameObjects.push_back(playerWalk);



    if(!TextureManager::Instance()->load("Background.jpg", "background", myRenderer)){
        return false;
    }

    m_bRunning = true;
    return true;
}

void Game::render(){

    SDL_RenderClear(myRenderer);
    TextureManager::Instance()->draw("background", 0, 0, 720, 480, myRenderer);

    playerWalk->draw(myRenderer);

    SDL_RenderPresent(myRenderer);
}

void Game::update(){

    playerWalk->update();

}

void Game::handleEvents(){
    TheInputHandler::Instance()->update();
}

void Game::clean(){
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    SDL_Quit();
}



