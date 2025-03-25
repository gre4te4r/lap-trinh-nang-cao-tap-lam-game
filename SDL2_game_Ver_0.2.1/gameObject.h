#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <string>
#include <map>

#include <SDL.h>
#include <SDL_image.h>

#include"TextureManage.h"
#include "Vector2D.h"
#include"InputHandler.h"

class GameObject{

public:

    GameObject() {}

    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();


protected:


    std::string m_textureID;
    int m_currentFrame;
    int m_currentRow;
    SDL_RendererFlip m_flip;

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_width;
    int m_height;
};

#endif // GAMEOBJECT_H_INCLUDED
