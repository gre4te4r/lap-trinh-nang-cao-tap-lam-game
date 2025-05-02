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
    static Game* Instance()
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
     int m_currentFrame;
    GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;


#endif // GAMECLASS_H_INCLUDED
