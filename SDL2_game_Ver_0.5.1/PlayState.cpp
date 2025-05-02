#include "PlayState.h"
#include <iostream>
const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
    player->update();

    mousePos = TheInputHandler::Instance()->getMousePosition();

    for (std::vector<GameObject *>::size_type i = 0; i != enemies.size(); i++)
    {
        Vector2D pos = player->playerGetPosition();
        enemies[i]->getBulletDestination(pos);
        enemies[i]->update();
    }

    for (std::vector<GameObject *>::size_type i = 0; i != bullets.size(); i++)
    {
        bullets[i]->update();
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_E))
    {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastShotTime >= fireRate)
        {
            generateBullet();
            lastShotTime = currentTime;
        }
    }

    if (SDL_GetTicks() - lastSpawnTime >= spawnInterval)
    {
        spawnEnemy();
        lastSpawnTime = SDL_GetTicks();
    }

    if (SDL_GetTicks() - lastLevelUpTime >= LevelUpTime)
    {
        if (spawnInterval > 0)
            spawnInterval -= 100;
        lastLevelUpTime = SDL_GetTicks();
    }
    checkBulletEnemyCollision();
    checkPlayerEnemyCollision();
    checkBulletOutofScreen();
}
void PlayState::render()
{
    TextureManager::Instance()->draw("background", 0, 0, 853, 480, TheGame::Instance()->getRenderer());

    player->draw(TheGame::Instance()->getRenderer());

    for (std::vector<Enemy *>::size_type i = 0; i != enemies.size(); i++)
    {
        enemies[i]->draw(TheGame::Instance()->getRenderer());
    }

    for (std::vector<Bullet *>::size_type i = 0; i != bullets.size(); i++)
    {
        bullets[i]->draw(TheGame::Instance()->getRenderer());
    }
}
bool PlayState::onEnter()
{
    player = new Player();
    player->load(300, 300, 40, 40, "run");
    m_gameObjects.push_back(player);
    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::onExit()
{
//    for (int i = 0; i < (int)m_gameObjects.size(); i++)
//    {
//        m_gameObjects[i]->clean();
//        delete m_gameObjects[i];
//    }
//    m_gameObjects.clear();
//
    for (Enemy* enemy : enemies)
    {
        enemy->clean();
        delete enemy;
    }
    enemies.clear();

    for (Bullet* bullet : bullets)
    {
        bullet->clean();
        delete bullet;
    }
    bullets.clear();
    std::cout << "exiting playState\n";
    return true;
}

void PlayState::spawnEnemy()
{
    int ran = rand() % 4;
    int randomX;
    int randomY;
    Enemy *newEnemy = new Enemy();

    if (ran == 1)
    {
        randomX = -40;
        randomY = rand() % 440;
    }
    else if (ran == 2)
    {
        randomX = 893;
        randomY = rand() % 440;
    }
    else if (ran == 3)
    {
        randomX = rand() % 893;
        randomY = -40;
    }
    else
    {

        randomX = rand() % 893;
        randomY = 520;
    }

    Vector2D pos = player->playerGetPosition();
    newEnemy->getBulletDestination(pos);

    newEnemy->load(randomX, randomY, 40, 40, "enemyRun");

    enemies.push_back(newEnemy);
}

void PlayState::generateBullet()
{

    Bullet *newBullet = new Bullet();

    Vector2D position = player->playerGetPosition();

    int posX = position.getX() + 6;
    int posY = position.getY() + 15;

    newBullet->load(posX, posY, 16, 16, "bullet");

    Vector2D pos = *mousePos;

    newBullet->getBulletDestination(pos);

    bullets.push_back(newBullet);
    SoundManager::Instance()->playSound("bullet", 0);
}

void PlayState::checkBulletEnemyCollision()
{
    for (int i = bullets.size() - 1; i >= 0; i--)
    {
        SDL_Rect Rect1;
        Rect1.x = bullets[i]->getBulletPosX();
        Rect1.y = bullets[i]->getBulletPosY();
        Rect1.w = bullets[i]->getBulletWidth();
        Rect1.h = bullets[i]->getBulletHeight();
        for (int j = enemies.size() - 1; j >= 0; j--)
        {
            SDL_Rect Rect2;
            Rect2.x = enemies[j]->getEnemyPosX();
            Rect2.y = enemies[j]->getEnemyPosY();
            Rect2.w = enemies[j]->getEnemyWidth();
            Rect2.h = enemies[j]->getEnemyHeight();

            if (RectRect(&Rect1, &Rect2))
            {
                delete enemies[j];
                enemies.erase(enemies.begin() + j);

                delete bullets[i];
                bullets.erase(bullets.begin() + i);
                SoundManager::Instance()->playSound("die", 0);
                break;
            }
        }
    }
}

void PlayState::checkPlayerEnemyCollision()
{

    SDL_Rect Rect1;

    Vector2D position = player->playerGetPosition();

    Rect1.x = position.getX();
    Rect1.y = position.getY();
    Rect1.w = player->getPlayerWidth();
    Rect1.h = player->getPlayerHeight();

    for (int j = enemies.size() - 1; j >= 0; j--)
    {
        SDL_Rect Rect2;
        Rect2.x = enemies[j]->getEnemyPosX();
        Rect2.y = enemies[j]->getEnemyPosY();
        Rect2.w = enemies[j]->getEnemyWidth();
        Rect2.h = enemies[j]->getEnemyHeight();

        if (RectRect(&Rect1, &Rect2))
        {
            delete enemies[j];
            enemies.erase(enemies.begin() + j);
            SoundManager::Instance()->playMusic("playerDie", 0);
            TheGame::Instance()->getStateMachine()->popState();
            TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
            break;
        }
    }
}

void PlayState::checkBulletOutofScreen()
{

    for (int i = bullets.size() - 1; i >= 0; i--)
    {

        if (bullets[i]->getBulletPosX() > 853 || bullets[i]->getBulletPosX() < 0 || bullets[i]->getBulletPosY() > 480 || bullets[i]->getBulletPosY() < 0)
        {

            delete bullets[i];
            bullets.erase(bullets.begin() + i);
        }
    }
}
