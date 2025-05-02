#include "GameOverState.h"
#include "PlayState.h"
#include <iostream>
#include "MenuState.h"
const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}
void GameOverState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(TheGame::Instance()->getRenderer());
    }
}
bool GameOverState::onEnter()
{
    if (!TheTextureManager::Instance()->load("restart.png", "restartButton", TheGame::Instance()->getRenderer()))
    {
        std::cout << "Failed to load menuButton.png\n";
        return false;
    }
    if (!TheTextureManager::Instance()->load("menu.png", "menuButton", TheGame::Instance()->getRenderer()))
    {
        std::cout << "Failed to load menuButton.png\n";
        return false;
    }
    if (!TheTextureManager::Instance()->load("restart.png", "overAnimation", TheGame::Instance()->getRenderer()))
    {
        std::cout << "Failed to load menuButton.png\n";
        return false;
    }
    MenuButton *menuButton = new MenuButton();
    menuButton->load(300, 250, 64, 16, "menuButton", s_gameOverToMain, true);
    m_gameObjects.push_back(menuButton);

    MenuButton *restartButton = new MenuButton();
    restartButton->load(300, 350, 64, 16, "restartButton", s_restartPlay, true);
    m_gameObjects.push_back(restartButton);

    std::cout << "entering OverState\n";
    return true;
}

bool GameOverState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
        delete m_gameObjects[i];
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("restartButton");
    TheTextureManager::Instance()->clearFromTextureMap("menuButton");
    TheTextureManager::Instance()->clearFromTextureMap("overAnimation");
    std::cout << "exiting OverState\n";
    return true;
}
void GameOverState::s_gameOverToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState);
}

void GameOverState::s_restartPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState);
}
