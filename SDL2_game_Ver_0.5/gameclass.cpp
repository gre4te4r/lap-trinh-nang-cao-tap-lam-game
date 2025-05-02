#include <SDL_image.h>
#include <SDL.h>

#include "gameclass.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "MenuState.h"

Game *Game::s_pInstance = nullptr;

Game::Game()
{
    myWindow = nullptr;
    myRenderer = nullptr;
    m_bRunning = false;
    m_currentFrame = 0;
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {

        myWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (myWindow != 0)
        {

            myRenderer = SDL_CreateRenderer(myWindow, -1, 0);

            if (myRenderer != 0)
            {

                SDL_SetRenderDrawColor(myRenderer, 0, 255, 255, 255);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG);

    if (!SoundManager::Instance()->load("aBullet.mp3", "bullet", SOUND_SFX))
    {
        return false;
    }
    if (!SoundManager::Instance()->load("aDeath.mp3", "die", SOUND_SFX))
    {
        return false;
    }
    if (!SoundManager::Instance()->load("playerDeath.mp3", "playerDie", SOUND_MUSIC))
    {
        return false;
    }
    if (!SoundManager::Instance()->load("bgMusic.mp3", "bgMusic", SOUND_MUSIC))
    {
        return false;
    }
    SoundManager::Instance()->playMusic("bgMusic", -1);
    Mix_VolumeMusic(20);
    m_bRunning = true;
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());
    return true;
}

void Game::render()
{

    SDL_RenderClear(myRenderer);

    m_pGameStateMachine->render();

    SDL_RenderPresent(myRenderer);
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update(myWindow, myRenderer);
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::clean()
{

    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    SDL_Quit();
}



