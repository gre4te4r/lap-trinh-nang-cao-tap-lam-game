#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}
void MenuState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(TheGame::Instance()->getRenderer());
    }
}
bool MenuState::onEnter()
{
    if (!TheTextureManager::Instance()->load("playButton.png", "playButton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("exitButton.png", "exitButton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    MenuButton *playButton = new MenuButton();
    playButton->load(300, 250, 250, 60, "playButton", s_menuToPlay, true);
    m_gameObjects.push_back(playButton);

    MenuButton *exitButton = new MenuButton();
    exitButton->load(300, 350, 250, 60, "exitButton", s_exitFromMenu, true);
    m_gameObjects.push_back(exitButton);

    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::onExit()
{
    //    for (int i = 0; i < m_gameObjects.size(); i++)
    //    {
    //        m_gameObjects[i]->clean();
    //    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playButton");
    TheTextureManager::Instance()->clearFromTextureMap("exitButton");
    std::cout << "exiting MenuState\n";
    return true;
}
void MenuState::s_menuToPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    TheGame::Instance()->clean();
}
