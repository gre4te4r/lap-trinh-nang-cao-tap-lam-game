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

    if(!TextureManager::Instance()->load("Run.png", "run", myRenderer)){
        return false;
    }
    if(!TextureManager::Instance()->load("Shot_1.png", "shot", myRenderer)){
        return false;
    }
    if(!TextureManager::Instance()->load("Idle.png", "idle", myRenderer)){
        return false;
    }

    player = new Player();
    player->load(300, 300, 128, 128, "run");
    m_gameObjects.push_back(player);

    if(!TextureManager::Instance()->load("Zombierun.png", "zombieRun", myRenderer)){
        return false;
    }

    if(!TextureManager::Instance()->load("bullet.png", "bullet", myRenderer)){
            std::cout << "er";
        return false;
    }


    if(!TextureManager::Instance()->load("Background.jpg", "background", myRenderer)){
        return false;
    }

    m_bRunning = true;
    return true;
}

void Game::render(){

    SDL_RenderClear(myRenderer);
    TextureManager::Instance()->draw("background", 0, 0, 720, 480, myRenderer);

    player->draw(myRenderer);


    for (std::vector<Enemy*>::size_type i = 0; i != enemies.size(); i++) {
        enemies[i]->draw(myRenderer);
    }



    for (std::vector<Bullet*>::size_type i = 0; i != bullets.size(); i++) {
        bullets[i]->draw(myRenderer);
    }




    SDL_RenderPresent(myRenderer);
}

void Game::update(){




    player->update();





    for(std::vector<GameObject*>::size_type i = 0; i != enemies.size(); i++){

        enemies[i]->update();

    }

    for(std::vector<GameObject*>::size_type i = 0; i != bullets.size(); i++){

        bullets[i]->update();

    }


}

void Game::handleEvents(){

    TheInputHandler::Instance()->update();
}

void Game::clean(){

    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    SDL_Quit();
}

void Game::spawnEnemy() {
    int ran = rand() % 2;
    int randomX;
    int randomY = rand() % (384 - 180 + 1) + 180;
    Enemy* newEnemy = new Enemy();

    if (ran == 1) {
        randomX = -100;
    } else {
        randomX = 800;
        newEnemy->flipEnemy();
    }

    newEnemy->load(randomX, randomY, 96, 96, "zombieRun");
    enemies.push_back(newEnemy);
}

void Game::generateBullet(){

    Bullet* newBullet = new Bullet();

    Vector2D position = player->playerGetPosition();
    int posX ;
    int posY ;
    SDL_RendererFlip flip = player->getPlayerFlip();

    if(flip == SDL_FLIP_NONE){

        posX = position.getX() + 85;
        posY = position.getY() + 60;

    }

    if(flip == SDL_FLIP_HORIZONTAL){

        posX = position.getX() + 8;
        posY = position.getY() + 60;

    }

    newBullet->load(posX, posY, 32, 32, "bullet");

    newBullet->flipBullet(flip);

    bullets.push_back(newBullet);


}

void Game::checkBulletEnemyCollision() {
    for (int i = bullets.size() - 1; i >= 0; i--) {
        SDL_Rect Rect1;
        Rect1.x = bullets[i]->getBulletPosX();
        Rect1.y = bullets[i]->getBulletPosY();
        Rect1.w = bullets[i]->getBulletWidth();
        Rect1.h = bullets[i]->getBulletHeight();
        for (int j = enemies.size() - 1; j >= 0; j--) {
            SDL_Rect Rect2;
            Rect2.x = enemies[j]->getEnemyPosX();
            Rect2.y = enemies[j]->getEnemyPosY();
            Rect2.w = enemies[j]->getEnemyWidth();
            Rect2.h = enemies[j]->getEnemyHeight();

            if (RectRect(&Rect1, &Rect2)) {
                delete enemies[j];
                enemies.erase(enemies.begin() + j);

                delete bullets[i];
                bullets.erase(bullets.begin() + i);
                break;
            }
        }
    }
}

void Game::checkPlayerEnemyCollision(){

        SDL_Rect Rect1;

        Vector2D position = player->playerGetPosition();


        Rect1.x = position.getX();
        Rect1.y = position.getY();
        Rect1.w = player->getPlayerWidth();
        Rect1.h = player->getPlayerHeight();



    for (int j = enemies.size() - 1; j >= 0; j--) {
            SDL_Rect Rect2;
            Rect2.x = enemies[j]->getEnemyPosX();
            Rect2.y = enemies[j]->getEnemyPosY();
            Rect2.w = enemies[j]->getEnemyWidth();
            Rect2.h = enemies[j]->getEnemyHeight();

            if (RectRect(&Rect1, &Rect2)) {
                delete enemies[j];
                enemies.erase(enemies.begin() + j);

                m_bRunning = false;
                break;
            }
        }

}

