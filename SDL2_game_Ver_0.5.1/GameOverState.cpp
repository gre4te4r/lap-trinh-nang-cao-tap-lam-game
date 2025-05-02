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
    TextureManager::Instance()->draw("overBackground", 0, 0, 853, 480, TheGame::Instance()->getRenderer());
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(TheGame::Instance()->getRenderer());
    }
}
bool GameOverState::onEnter()
{
    MenuButton *menuButton = new MenuButton();
    menuButton->load(300, 150, 128, 32, "menuButton", s_gameOverToMain, true);
    m_gameObjects.push_back(menuButton);

    MenuButton *restartButton = new MenuButton();
    restartButton->load(300, 250, 128, 32, "restartButton", s_restartPlay, true);
    m_gameObjects.push_back(restartButton);

    std::cout << "entering OverState\n";
    return true;
}

bool GameOverState::onExit()
{
//    for (int i = 0; i < m_gameObjects.size(); i++)
//    {
//        m_gameObjects[i]->clean();
//        delete m_gameObjects[i];
//    }
//    m_gameObjects.clear();

    std::cout << "exiting OverState\n";
    return true;
}
void GameOverState::s_gameOverToMain()
{
    TheGame::Instance()->getStateMachine()->popState();
    TheGame::Instance()->getStateMachine()->pushState(new MenuState);
}

void GameOverState::s_restartPlay()
{
    TheGame::Instance()->getStateMachine()->popState();
    TheGame::Instance()->getStateMachine()->pushState(new PlayState);
}
