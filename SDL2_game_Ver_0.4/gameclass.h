#ifndef GAMECLASS_H_INCLUDED
#define GAMECLASS_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"

#include "TextureManage.h"
#include "gameObject.h"
#include "player.h"
#include "Enemy.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "Bullet.h"
#include "collision.h"
#include "SoundManager.h"
#include"GameStateMachine.h"

class Game
{
public:
    static Game* Instance() // Singleton accessor
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new Game();
        }
        return s_pInstance;
    }
    bool init(const char *title, int xpos, int ypos, int width, int height, int flags);

    void render();

    void update();

    void handleEvents();

    void clean();

    void spawnEnemy();

    void generateBullet();

    void checkBulletEnemyCollision();

    void checkPlayerEnemyCollision();

    void checkBulletOutofScreen();

    bool running() { return m_bRunning; }
    SDL_Renderer* getRenderer() const { return myRenderer; }
    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }


private:
    Game();
    ~Game() {}

    static Game* s_pInstance;
    SDL_Window *myWindow;
    SDL_Renderer *myRenderer;

    bool m_bRunning;

    Player *player;

    Vector2D *mousePos;

    int m_currentFrame;

    std::vector<GameObject *> m_gameObjects;
    std::vector<Enemy *> enemies;
    std::vector<Bullet *> bullets;
    GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;


#endif // GAMECLASS_H_INCLUDED
