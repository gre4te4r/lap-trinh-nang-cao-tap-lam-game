#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

#include "GameObject.h"
#include"TextureManage.h"

class Enemy : public GameObject{

public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();


    float getEnemyPosX();

    float getEnemyPosY();

    int getEnemyWidth();

    int getEnemyHeight();

    void getBulletDestination(Vector2D des);

};

#endif // ENEMY_H_INCLUDED
