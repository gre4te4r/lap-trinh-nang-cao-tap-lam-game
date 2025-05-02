#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
    for (int i = 0; i < (int)m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}
void MenuState::render()
{
    TextureManager::Instance()->draw("menuBackground", 0, 0, 853, 480, TheGame::Instance()->getRenderer());
    for (int i = 0; i < (int)m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(TheGame::Instance()->getRenderer());
    }
}
bool MenuState::onEnter()
{
    MenuButton *playButton = new MenuButton();
    playButton->load(300, 250, 128, 32, "playButton", s_menuToPlay, true);
    m_gameObjects.push_back(playButton);

    MenuButton *exitButton = new MenuButton();
    exitButton->load(300, 350, 128, 32, "exitButton", s_exitFromMenu, true);
    m_gameObjects.push_back(exitButton);

    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::onExit()
{
//    for (int i = 0; i < (int)m_gameObjects.size(); i++)
//    {
//        m_gameObjects[i]->clean();
//        delete m_gameObjects[i];
//    }
//    m_gameObjects.clear();
    std::cout << "exiting MenuState\n";
    return true;
}
void MenuState::s_menuToPlay()
{
    GameState* newState = new PlayState();

    if (newState->onEnter()) {
        TheGame::Instance()->getStateMachine()->popState();
        TheGame::Instance()->getStateMachine()->pushState(newState);
    } else {
        std::cout << "Failed to enter PlayState!" << std::endl;
        delete newState;
    }
}


void MenuState::s_exitFromMenu()
{
    TheGame::Instance()->clean();
}
