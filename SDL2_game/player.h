#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

#include "GameObject.h"
#include"TextureManage.h"
#include"InputHandler.h"

class Player : public GameObject{

public:
    void load(int x, int y, int width, int height, std::string textureID);

    void draw(SDL_Renderer* pRenderer);

    void update();

    void clean();

};

#endif // PLAYER_H_INCLUDED
