#ifndef GAMECLASS_H_INCLUDED
#define GAMECLASS_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>

#include "SDL.h"

#include "TextureManage.h"
#include"gameObject.h"
#include"player.h"
#include"Enemy.h"
#include"Vector2D.h"
#include"InputHandler.h"

class Game
{
public:
    Game();
    ~Game();
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render();

    void update();

    void handleEvents();

    void clean();

    bool running() { return m_bRunning; }

private:

    SDL_Window* myWindow;
    SDL_Renderer* myRenderer;

    bool m_bRunning;

    GameObject* playerWalk;
    GameObject* playerAttack;

    int m_currentFrame;


    std::vector<GameObject*> m_gameObjects;


};

#endif // GAMECLASS_H_INCLUDED
