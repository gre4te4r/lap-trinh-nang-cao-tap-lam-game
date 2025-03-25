#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED


#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

#include "GameObject.h"
#include"TextureManage.h"
#include"InputHandler.h"

class Bullet : public GameObject{

public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);

    void update();

    bool isOffScreen();

    void flipBullet(SDL_RendererFlip flip);

    void clean();

    float getBulletPosX();

    float getBulletPosY();

    int getBulletWidth();

    int getBulletHeight();


};



#endif // BULLET_H_INCLUDED
