#ifndef PLAYSTATE_H_INCLUDED
#define PLAYSTATE_H_INCLUDED

#include "GameState.h"

#include "TextureManage.h"
#include "gameObject.h"
#include "player.h"
#include "Enemy.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "Bullet.h"
#include "collision.h"
#include "SoundManager.h"
#include "gameclass.h"
#include "GameStateMachine.h"
#include"GameOverState.h"

class PlayState : public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();

    void spawnEnemy();
    void generateBullet();
    void checkBulletEnemyCollision();
    void checkPlayerEnemyCollision();
    void checkBulletOutofScreen();

    virtual std::string getStateID() const { return s_playID; }

private:
    static const std::string s_playID;
    Player *player;
    Vector2D *mousePos;
    std::vector<GameObject *> m_gameObjects;
    std::vector<Enemy *> enemies;
    std::vector<Bullet *> bullets;

    Uint32 lastSpawnTime = 0;
    Uint32 spawnInterval = 1000;

    Uint32 lastShotTime = 0;
    const Uint32 fireRate = 100;

    Uint32 lastLevelUpTime = 0;
    const Uint32 LevelUpTime = 10000;
};


#endif // PLAYSTATE_H_INCLUDED
